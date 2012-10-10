# Homework 3: Buffer Management in PostgreSQL
### CS186, UC Berkeley, Fall 2012
### Points: [10% of your final grade](https://sites.google.com/a/cs.berkeley.edu/cs186-fa2012/additional-course-information)
### Note: *This homework is to be done in pairs! You are not allowed to make your code publicly accessible, such as putting it on a git public repository. Please refer to [Berkeley Code of Student Conduct](http://campuslife.berkeley.edu/sites/campuslife.berkeley.edu/files/UCB-Code-of-Conduct-new%20Jan2012.pdf) for details.
### Due: Tuesday 23 October 2012 (You have 4 slip days for all CS186 projects. Use them wisely.)

##Table Of Contents
*  [Outline](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#outline)
*  [Environment Setup](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#environment-setup)
*  [Code Digesting](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#code-digesting)
*  [Buffer Replacement Algorithms](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#buffer-replacement-algorithms)
*  [Testing and Debugging](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#testing-and-debugging)
*  [Submission](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#submission)

## Outline

In this homework, your mission is to modify PostgreSQL's buffer manager. The buffer replacement policy currently used in PostgreSQL is clock.  You are expected to digest the source code of PostgreSQL's buffer manager with little instruction. On top of that, you will need to modify the source code and implement three buffer replacement algorithms: LRU, MRU and 2Q.

##Environment Setup

###Virtual Machine
You are required to do this homework on a virtual machine. If you have already installed VirtualBox and the image for Homework 2, feel free to continue using it and skip this step.
Otherwise, follow the instructions [here](http://alpha.saasbook.info/bookware-vm-instructions#TOC-Downloading-and-running-the-courseware-on-your-own-computer) to install 1) VirtualBox and 2) the virtual machine image. Working on other platforms may have compatibility issues.


###Getting the Code
If you are in a new folder, you will have to clone the fa12 repo:

    cd
    git clone git://github.com/cs186-fa12/fa12.git

or if you already had the repo from previous homeworks, you can pull the repo to get the updates:

    cd fa12
    git pull

Make sure you see the PostgreSQL source code in `fa12/hw3/postgres-8.4.2` and the test data in `fa12/hw3/test`.

###Installing Postgresql-8.4.2 from Source
    cd postgresql-8.4.2
    ./configure --enable-depend --enable-cassert --enable-debug --prefix=$HOME/pgsql
    make

This step takes 5-10 minutes. If the build is successful, you will see the following line: 

    All of PostgreSQL successfully made. Ready to install.

Then you can go ahead and install it:

    make install

If you see this at the last line of output:

    PostgreSQL installation complete.

Congratulations! You are off to a good start!

### Initializing Database

We now initialize a PostgreSQL database at `$HOME/pgsql/data`. As long as you don't delete it, this only needs to be done once.

    $HOME/pgsql/bin/initdb -D $HOME/pgsql/data

### Starting/Stopping the Database Server

This step starts up the database server.

    $HOME/pgsql/bin/postgres -p 11111 -D $HOME/pgsql/data

Now that the database server is up and running, the current terminal window is taken to output server logs. You will have to open a new terminal window to continue. 
Note that everytime you re-install postgres from the source or reconfigure the server, you will have to stop and restart the server for your changes to take effect. You can stop the server by typing:

    $HOME/pgsql/bin/pg_ctl -D ~/pgsql/data stop

### The PSQL Client Application

Let's use the *psql* client application to pose a few SQL queries to the server:

    $HOME/pgsql/bin/psql -p 11111 postgres
    psql (8.4.2)
    Type "help" for help.
    postgres=#

As suggested by the 'postgres=#' prompt, we are in psql and ready to write all the fun SQL queries. Let's create a table first:

    postgres=# create table test (a int, b int);
    CREATE TABLE

Note that every SQL query must be terminated with a semicolon (;). Next, we insert a few rows into the table, and then run a simple SELECT query:

    postgres=# insert into test values (10, 20);
    INSERT 0 1
    postgres=# insert into test values (30, 40);
    INSERT 0 1
    postgres=# insert into test values (40, 50);
    INSERT 0 1
    postgres=# select * from test where b > 35;
    a  | b 
    ----+----
    30 | 40
    40 | 50
    (2 rows)

To leave psql and go back to the linux command-line, type 'Ctrl-D' or '\q'.

## Code Digesting

The first step of the homework is to understand the implementation of PostgreSQL's buffer manager. You may find the following files relevant:

*  src/backend/storage/buffer/buf_init.c
*  src/backend/storage/buffer/bufmgr.c
*  src/backend/storage/buffer/freelist.c
*  src/include/storage/buf_internals.h
*  src/include/storage/buf.h
*  src/include/storage/bufmgr.h

You will be primarily modifying `freelist.c`. Maybe adding some data structures to `buf_internals.h` is also necessary. You are not allowed to submit other source files than these two, so make sure they include all your changes. To quickly browse the PostgreSQL source code, you may find tools like cscope and tags to be helpful.

The following functions are worth particular attention:

* `StrategyGetBuffer()` in `freelist.c`
  This is called when the bufmgr wants to allocate a new buffer (into which it wants to load a page from disk). Hence, this function should return either a free buffer (if there are any unused buffers), or it should choose a buffer to be replaced. In the latter case, the replacement policy is used to select which buffer to return. Be sure to avoid selecting a buffer for replacement that is still being used (i.e., has refcount > 0).
* `BufferUnpinned()` in `freelist.c`
  This is called when a buffer's reference count reaches zero -- i.e., the buffer was previously pinned (in use), but it is now unused (and hence a candidate for replacement).
* `StrategyInitialize()` in `freelist.c`: This is called to initialize any shared-memory data structures used by the replacement policy.
* `PinBuffer()` and `PinBuffer_Locked()` in `bufmgr.c`: These functions are called to pin a buffer (i.e., to increase its refcount by one). Note that the *refcount* variable in the code is actually what we call *pin_count* in the class. The clock reference counter variable is named usage_counter. If the refcount variable is non-zero, it indicates the page is being used and the page should NOT be a candidate for replacement.

We placed some **CS186** and **TODO** comments to help you finish the task. It may take you some time to digest the code. Be patient and strategic.


## Buffer Replacement Algorithms

You need to implement three buffer replacement policies: LRU, MRU and 2Q. The details of LRU and MRU can be found in lecture notes and the textbook. A description of the 2Q algorithm is given below. Note that a buffer page is not a candidate for any buffer replament algorithm until it has been unpinned (i.e., ref_count turns to zero). You never consider replacing a pinned buffer page.

### The 2Q Buffer Replacement Algorithm

A problem with the LRU and CLOCK strategies is that buffer pages that get accessed only once must sit through the entire queue cycle before being replaced. 2Q is one of the algorithms that try to address this problem. The idea is to manage two separate queues. On the first reference to a page, 2Q places it in a special buffer, the A1 queue, which is managed as a FIFO queue. If the page is re-referenced during its A1 residency, the page is moved to the Am queue, which is managed as a LRU queue. (Hint: you can re-use your LRU implementation for the Am queue here)
In this homework, you will be asked to implement the simplified version of 2Q, and the pseudocode is given below: 

Placing a newly unpinned buffer *buf*:

    unpin(buf) {
        if buf is on the Am queue then
            put buf on the front of the Am queue
        else if buf is on the A1 queue then
            remove buf from the A1 queue
            put buf on the front of the Am queue
        else
            put buf on the front of the A1 queue
        end if
    }

Finding a free slot for a page *p*:

    find_free_slot(p){
        if there are free slots available then
            put p in a free page slot
        else if size(A1) >= thres OR Am is empty /* we set thres = floor(B/2) for this homework */
            delete from the tail of A1
            put p in the freed page slot
        else
            delete from the tail of Am
            put p in the freed page slot
        end if
    }

Although the information above would be sufficient for this homework, interested students are referred to the original research paper introducing 2Q:

*2Q: A Low Overhead High Performance Buffer Management Replacement Algorithm*, Theodore Johnson, Dennis Shasha, VLDB '94

http://www.vldb.org/conf/1994/P439.PDF


### Rebuild

When you are done working with the source, you need to rebuild and install your modified version of PostgreSQL:

    cd postgres-8.4.2/
    make
    make install

This step only takes about 1-2 minutes, since only a fraction of the postgresql code needs to rebuild. Work with the error messages if the build fails. Even if it compiles, make sure to check the compiler messages for any unexpected warnings. You will have to restart the server too for your changes to take effect.

## Testing and Debugging

### Populating Test Data

We provide two data files R and S in `fa12/hw3/test/`. You can load them onto the postgresql server in psql:

    postgres=# CREATE TABLE raw_r_tuples (tname varchar(2), pkey int, num2 int, num3 int, num1 int, node varchar(16), inserttime float8, lifetime float8, testname varchar(64));
    CREATE
    postgres=# CREATE TABLE raw_s_tuples (tname varchar(2), pkey int, num2 int, num3 int, num1 int, node varchar(16), inserttime float8, lifetime float8, testname varchar(64));
    CREATE
    postgres=# COPY raw_r_tuples FROM '[full path to your repo here]/fa12/hw3/test/R' DELIMITER ',';
    COPY 2400
    postgres=# COPY raw_s_tuples FROM '[full path to your repo here]/fa12/hw3/test/S' DELIMITER ',';
    COPY 2400

Note that this step needs to be done only once, as long as you do not wipe out your database.

### Starting PostgreSQL Server with Configuration Parameters

Stop the PostgreSQL server if you already started it, and use the following command to re-start the server:

    $HOME/pgsql/bin/pg_ctl start -D $HOME/pgsql/data -l lru64.log -o "-p 11111 -B 64 -N 1 -o '-te -fm -fh' --buffer-replacement-policy=lru --autovacuum=off"

This command instructs PostgreSQL to write log messages to a file (lru64.log), to use 64 buffers ("-B" option), to use the LRU replacement policy, and to disable autovacuum, which is a background program that may affect buffer behaviors. Note that you should change the log file according to the buffer size and replacement policy parameters.

You can monitor the logs in realtime:

    tail -f lru64.log

If you see the following line in the log, that means the PostgreSQL server has been correctly configured to use LRU.

    LOG:  using buffer replacement policy: lru

### Testing

We now run some testing queries to examine the buffer behavior. Enter psql and run the following 6 queries one by one:

    SELECT * FROM raw_r_tuples;
    SELECT * FROM raw_r_tuples;
    SELECT * FROM raw_r_tuples;
    SELECT * FROM raw_r_tuples r, raw_s_tuples s WHERE r.pkey = s.pkey;
    SELECT * FROM raw_r_tuples r, raw_s_tuples s WHERE r.pkey = s.pkey;
    SELECT * FROM raw_r_tuples r, raw_s_tuples s WHERE r.pkey = s.pkey;

If you examine the log file, you will see some messages like this at the end of each query:

    LOG:  EXECUTOR STATISTICS
    DETAIL:  ! system usage stats:
        !       2.175096 elapsed 2.166767 user 0.002569 system sec
        !       [4.406416 user 0.044053 sys total]
        !       0/0 [66/74] filesystem blocks in/out
        !       0/0 [66/0] page faults/reclaims, 0 [0] swaps
        !       0 [0] signals rcvd, 0/188 [8/3803] messages rcvd/sent
        !       2/112 [389/235] voluntary/involuntary context switches
        ! buffer usage stats:
        !       Shared blocks:         27 read,          4 written, buffer hit rate = 50.00%
        !       Local  blocks:          0 read,          0 written, buffer hit rate = 0.00%
        !       Direct blocks:          0 read,          0 written

The important numbers are after "Shard blocks", which is the buffer pool. In particular, the buffer hit rate is 50% and the number of blocks read from disk (i.e., buffer misses) is 27 in this case.


### Reporting Test Results

You need to report the test result of the CLOCK, LRU, MRU and 2Q replacement policies, together with the different buffer sizes: 16, 32, 64, and 96 (by changing the "-B" option). 

For each combination of replacement policy and buffer pool size, you will have to:

* Restart the server using the command above with the appropriate parameters.
* Open psql, run only the above 6 queries in order. Avoid addtional interaction with the server, as they may affect the buffer behavior.
* Collect 6 hit rates, one for each query.

Collect the hit rates for all the configurations in one file, `performance.txt`, using the following format:

* Use one line for each configuration. 
* Each line should begin with the name of the policy in lower case, followed by the buffer pool size, followed by the six hit rates in the order you execute the queries. Separate each column using a space.
* Record the hit rate as a decimal to two places, without the (%) sign, e.g. 99.26.
* Report the four policies in the following order: clock, lru, mru, lri.

You need to submit a file that consists of 16 lines in total. For example (the numbers are made up):

    clock 16 0.00 99.55 99.55 12.05 23.04 23.04
    clock 32 100.00 100.00 100.00 100.00 100.00 100.00
    clock 64 100.00 100.00 100.00 100.00 100.00 100.00
    clock 96 100.00 100.00 100.00 100.00 100.00 100.00
    lru 16  ...
    lru 32  ...
    ....

**Note that you may get different numbers even in slightly different database settings. For grading, we will run your code to produce these numbers and take this file you submitted as a reference.**

### Debugging

#### Logging

At any point in a function, you can insert an elog() statement to output a message to the log file, using the same syntax as printf():

    elog(LOG, "Two plus three is %d", 2+3);

This may be helpful for debugging purposes. However, make sure you remove all the debugging logging from your code before submission, since writting debugging logs may incur significant overhead and make your program fail to finish when we test it.

#### GDB

You can use gdb to debug your development on PostgreSQL. First, start psql. In a separate terminal window, you first need to determine the PID of the backend process. The simplest way to do this is to locate the "postgres" process with the most recent start time in the output of `ps`:

    ps -f -u $USER | egrep /+postgres | sort -r -k 26
    cs186-tc  2347  2304   0 23:48:55 ?           0:00 ./bin/postgres -D data
    cs186-tc  2309  2304   0 23:42:11 ?           0:00 ./bin/postgres -D data
    cs186-tc  2308  2304   0 23:42:11 ?           0:00 ./bin/postgres -D data
    cs186-tc  2307  2304   0 23:42:11 ?           0:00 ./bin/postgres -D data
    cs186-tc  2306  2304   0 23:42:11 ?           0:00 ./bin/postgres -D data
    cs186-tc  2304 11960   0 23:42:11 pts/14      0:00 ./bin/postgres -D data

Note that there may be a newer version (9.1) of PostgreSQL server running in the background. It came with the virtual machine image and started running at the startup of the virtual machine.  Next, grab the PID of the process, which is the first numeric column in the output of ps. Attach to the backend "postgres" process using gdb:

    gdb ~/pgsql/bin/postgres 2347

Once gdb has attached to the backend process, you might want to set a breakpoint inside the replacement policy code, and then use the "continue" command to resume the execution of the backend process. For example:

    (gdb) break StrategyGetBuffer 
    Breakpoint 1 at 0x8268188: file freelist.c, line 150.
    (gdb) continue

##Submission

You will need to submit the following 5 files.

* src/backend/storage/buffer/freelist.c
* src/include/storage/buf_internals.h
* performance.txt: Report the hit rates in 16 lines. Please refer to the [Reporting Test Result](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#reporting-test-results) section for details.
* README: If you are using slip days, your README should contain a single digit indicating the number of slip days you wish to use. For example, if you wanted to use two slip days, the README would consist of only one line with the number: `2`. If you are not using any slip days, the README should be empty.
* MY.PARTNERS: This will be auto-generated when you run the submit hw3 script.

Make sure the source files `freelist.c` and `buf_internals.h` include all the changes you have made to the source. We will be testing and grading your code by patching these files to the postgres source.

On an inst machine, create a folder and put in it only the files to be submitted. You can transfer the files to the inst machines with:

    scp hw3.tar cs186-XX@hive1.cs.berkeley.edu:[path to put the file]

Go to the folder with all the above files, and type ``submit hw3``. You will be asked to input your partner's login first.

```
submit hw3
Please enter the logins of your partner(s), if any.
Enter '.' to stop.
Login:
...
(this part omitted here)
...
Created MY.PARTNERS file.
Looking for files to turn in...
Submitting freelist.c.
Submitting buf_internals.h
Submitting README.
The files you have submitted are:
    ./freelist.c ./buf_internals.h ./MY.PARTNERS ./README
Is this correct? [yes/no] y
Copying submission of assignment hw3....
Submission complete.
```

