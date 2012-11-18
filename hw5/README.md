# Homework 5: Approximate Top-K using Count-Min Sketch
### CS186, UC Berkeley, Fall 2012
### Points: [10% of your final grade](https://sites.google.com/a/cs.berkeley.edu/cs186-fa2012/additional-course-information)
### Note: *This homework is to be done in pairs! You are not allowed to make your code publicly accessible, such as putting it on a git public repository. Please refer to [Berkeley Code of Student Conduct](http://campuslife.berkeley.edu/sites/campuslife.berkeley.edu/files/UCB-Code-of-Conduct-new%20Jan2012.pdf) for details.
### Due: Monday 3 December 2012 (You have 4 slip days for all CS186 projects. Use them wisely.)

##Table Of Contents
*  [Outline](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#outline)
*  [Environment Setup](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#environment-setup)
*  [Part 1: Count-Min Sketch](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#part-1-count-min-sketch)
*  [Part 2: Approximate-Top K](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#part-2-approximate-top-k )
*  [Part 3: Testing and Debugging](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#part-3-testing-and-debugging)
*  [Submission](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#submission)

## Outline

In HW3, you looked at how to change the page replacement policy of the PostgreSQL buffer manager. In this project you will move to a higher level in the system and add functionality to the PostgreSQL query executor. We will restrict our focus to grouped aggregates in this homework. 

The grouped aggregate COUNT() that you've seen in lecture assumes that all elements for the column(s) specified will be counted and returned. For many cases however, you only actually want the groups with the k-highest counts (also called as a Top-K query).  One example would be a query that lists the 100 most popular videos on YouTube.

Your task in this project is to implement a new grouped aggregate called APPROX_COUNT() that saves space in memory by only keeping track of a fixed number of elements to maintain an approximate count of the most frequent values.
To do this, you will build a data structure called the Count-Min sketch and intergrate this with the query execution engine.

Excited yet ? !

##Environment Setup

###Virtual Machine
You are required to do this homework on a virtual machine. If you have already installed VirtualBox and the image for Homework 3 or Homework 4, feel free to continue using it and skip this step.
Otherwise, follow the instructions [here](http://alpha.saasbook.info/bookware-vm-instructions#TOC-Downloading-and-running-the-courseware-on-your-own-computer) to install 1) VirtualBox and 2) the virtual machine image. Working on other platforms may have compatibility issues.

###Getting the Code
If you are in a new folder, you will have to clone the fa12 repo:

    cd
    git clone git://github.com/cs186-fa12/fa12.git

or if you already had the repo from previous homeworks, you can pull the repo to get the updates:

    cd fa12
    git pull

Make sure you see the PostgreSQL source code in `fa12/hw5/postgres-8.4.2` and the test data in `fa12/hw5/test`.

###Installing Postgresql-8.4.2 from Source
    cd hw5/postgresql-8.4.2
    ./configure --enable-depend --enable-cassert --enable-debug --prefix=$HOME/pgsql
    make

This step takes 5-10 minutes. If the build is successful, you will see the following line: 

    All of PostgreSQL successfully made. Ready to install.

Then you can go ahead and install it:

    make install

If you see this at the last line of output:

    PostgreSQL installation complete.

Congratulations! You are off to a good start!

### Initializing the Database

We will now delete your existing database from earlier homeworks and initialize a PostgreSQL database at `$HOME/pgsql/data`. As long as you don't delete it later, this only needs to be done once.

    rm -rf $HOME/pgsql/data # this removes your hw3/hw4 database!
    $HOME/pgsql/bin/initdb -D $HOME/pgsql/data

### Starting the database server

This step starts up the database server. Since we will be using multiple tables which have numbers in them, lets create a database called `nums`
  
    $HOME/pgsql/bin/pg_ctl -D ~/pgsql/data -o "-p 11111 -s" -l hw5.log start
    $HOME/pgsql/bin/createdb -p 11111 nums 

Note: This looks similar to the command we used in the previous homeworks. One difference is that we add the `-s` flag to output timing information when a query is run.
    
Make sure that every time you re-install postgres from source or reconfigure the server, you stop and restart the server for your changes to take effect. You can stop the server by typing:

    $HOME/pgsql/bin/pg_ctl -D ~/pgsql/data -o "-p 11111" stop

### The PSQL Client Application

Since you have used the PSQL client in HW3 and HW4, we assume you are familiar with it! If not here is a [link](https://github.com/cs186-fa12/fa12/blob/master/hw3/README.md#the-psql-client-application) to the relevant section in HW3, in case you want to jog your memory.

## Part 1: Count-Min Sketch

In the first part of this homework, you will implement a probabilistic data structure called a Count-Min sketch.
The idea behind probabilistic data structures is that you can get an approximate answer very close to the actual answer while using even less memory than hybrid hash aggregation!  Count-Min sketch is one such data structure and to get an idea of how effective these techniques can be, this [visualization](http://highlyscalable.files.wordpress.com/2012/04/probabilistic-sizes.png) shows you can get an answer within ~4% with 0.1% of memory used !

### Algorithm

A Count-Min sketch consists of a two-dimensional array (widthxdepth) of integer counters. The width represents the number of counters in a single row while the depth represents the number of such rows we have. This [picture](http://highlyscalable.files.wordpress.com/2012/04/count-min-sketch.png) may be useful to visualize how it looks !

First, take some time to familiarize yourself with how the algorithm works by reading the Count-Min section of this [blog post](http://lkozma.net/blog/sketching-data-structures/). (If that was too easy of a read for you, consider reading the original [paper](https://sites.google.com/site/countminsketch/cm-latin.pdf?attredirects=0) describing Count-Min sketches. If you want to try challenge mode, the [Wikipedia article](http://en.wikipedia.org/wiki/Count-Min_sketch) has more details on the accuracy and error bounds of this method in a very concise format.)

Now lets look at some pseudocode to update the frequency of a single data item stored in a count min sketch 

      increment(item) {
          Calculate 'd' hash values for this item where 'd' is the depth of the Count-Min sketch.
          Each hash value here will be a number between 0 and 'width'
          ...
          hashes[1] = get_hash(item)          
          ...
          
          Increment the corresponding counter which is pointed to by each of the hash values. 
          i.e. if hashes[1] was equal to 4, then we would increment counter[4] corresponding to the first row of the  sketch
      }

To summarize, we update 'd' different counters when an item is inserted into the Count-Min sketch. Now lets take a look at how we can estimate the frequency of a particular item

       estimate(item) {
          Calculate 'd' hash values for this item similar to what we did for increment.          
          Return the minimum value among all the counters these hash values point to.
          
          i.e if we had depth = 2 and hashes[1] = 4, and hashes[2] = 2, the we would return the
          minimum of counter[4] from the first row and counter[2] from the second row.
       }
    

### Implementation

Now lets implement a Count-Min sketch that we can use to answer our top-k queries ! The basic interface for what you are expected to implement is given to you in two files:

*  src/include/utils/cmsketch.h
*  src/backend/utils/hash/cmsketch.c

You will need to implement the functions defined in the header file and also create any datastructures you need in the header file. 

NOTE: The major difference between the algorithm described above and your implementation is that we assume the hashes are computed before the functions in cmsketch.h are called. This makes the implementation simpler and we will look at how to compute the hashes in the next section.

### Testing Count-Min Sketches

We love testing ! To help you get started, we have provided a simple test skeleton in the following file

*  src/backend/utils/hash/cmsketch_test.c

To only build and run the count min sketch test, you will need to

        cd src/backend/utils/hash
        make cmsketch_test
        ./cmsketch_test

NOTE: The testcases provided are very basic and do not test all the aspects of the Count-Min sketch. You are encouraged to add more test cases to make sure your data structure works correctly !


## Part 2: Approximate Top-K

Now that we have our Count-Min sketch working and all tested, lets look at how we can integrate this into PostgreSQL as Top-K counting.

### Algorithm

While the Count-Min sketch we implemented can answer point-queries (e.g what is the number of times you saw 'Berkeley'), we need to do a little bit more to answer Top-K queries. In particular, we need to keep track of our current approximate top-K item, so we can output them at the end.

In order to keep track of the "top-k items"-so-far we will use an auxillary data structure in addition to the Count-Min sketch. The algorithm we use to calculate the Top-K is 

    Create a data structure to hold the Top-K items
    for_every_item_we_see(item) {
     
      Increment the count for this item in the Count-Min sketch
      Now estimate the frequency of this item using the sketch - say this is equal to freq_item

      Add freq_item to our data structure.
      If we have more than K-items, remove the item with the lowest frequency from our data structure
      If freq_item was already in our data structure, just update it instead.
    }
    return the k-items we have as the approximate top-k
    
### Implementation

Now, lets dig into PostgreSQL and figure out how to support this ! To do this, you'll first need to understand how aggregation operators are implemented in PostgreSQL. We will provide a list of important files and functions to walk you through this. Take some time to understand the code, before you start modifying things !

PostgreSQL performs HASHED or SORTED aggregations out of the box. We have added a new operator APPROX_COUNT and a new aggregation strategry called HASHED_APPROX. Looking through parts of the code which have `NB186:` will give you a good idea of what changes we made to the code to make this project possible. The three files that you are mainly interested in are:

*	`src/backend/executor/nodeAgg.c` _(Read/Write)_ - Contains main logic for performing the Top-K aggregation.
*	`src/include/nodes/execnodes.h` _(Read/Write)_ - Contains data structures used by nodeAgg.c.
*	`src/include/nodes/plannodes.h` *(Read only)* - Contains information about the Agg plan (e.g., the user-specified K, width, and depth).

**Aggregation happens in two steps (in nodeAgg.c):**

*	In the first step (Phase I), we walk over all the tuples that are produced by the downstream operator (say a FileScan or a IndexScan).
*	In the second step (Phase II), we retrieve the grouped aggregate values using the data structures we have built. (E.g., for Youtube Top 100, output "Charlie bit my finger - again!, 494959206".)
*	You can implement the above mentioned algorithm by filling in the functions:
	* `approx_agg_init` - Any initialization code, called before Phase I.
	* `approx_agg_per_input` - Called once per input tuple. Process each tuple to build up the Count-Min sketch and Top-K data structure. (Phase I work.)
	* `approx_advance_iter` - Output 1 of the top-k tuples (or NULL if done). (Phase II work.)
	* `approx_reset_iter` - Called *between* Phase I and II. Postgres requires this in order to be able to run Phase II multiple times for a single Phase I (e.g., if this were the inner plan for a nested loops join). Each execution of Phase II after a reset should be identical.

### Hints and Pointers

* 	The function `getTupleHashBits` can be used to compute the hash values for the Count-Min sketch. It takes care of computing the d hash values (one for each row of the CM sketch) which are between 0 and 'width'.

*	The Top-K tuples can be stored using any data structure or your choice. Since we will be working with small K the performance implications are not very important. So feel free to build this using an array or a linked list or a priority queue etc.

*	The `struct ApproxTopEntry` can be used to store a single entry in your data structure. It is populated with just the tuple right now and you can add any other fields that are required.

*	We have given you some helper functions which could be useful in implementing the Top-K functions. These include `compare_tuple_with_approx_top_tuple` which can help you check if a tuple that you are seeing is equal to a tuple you have in your data structure.

*	While the input `approx_agg_per_input` is a `TupleTableSlot`, `ApproxTopEntry` stores `MinimalTuples`. This is related to PostgreSQL internals, but we have a function `set_approx_top_entry_from_slot` that can help you fill in the `ApproxTopEntry`. (A `TupleTableSlot` is a Postgres memory buffer, that stores `MinimalTuples`, whch are the actual tuples.)

*	Finally, memory allocation in PostgreSQL is done using MemoryContexts which are useful to avoid memory leaks. You do not need to worry about this for your assignment as the right contexts have been set before the functions are called. Make sure to use `palloc` and `pfree` within your functions.

### Rebuild

When you are done working with the source, you need to rebuild and install your modified version of PostgreSQL. Because we're awesome, we have provided you with a handy script to rebuild Postgres, install the changes, and restart the server.

    cd postgres-8.4.2/
    ./rebuild_and_restart.sh

This step only takes about 1-2 minutes, since only a fraction of the postgresql code needs to rebuild. Work with the error messages if the build fails. Even if it compiles, make sure to check the compiler messages for any unexpected warnings.

Use `$HOME/pgsql/bin/psql -p 11111 nums` to connect to postgres.

## Part 3: Testing and Debugging

### Populating Test Data

We provide four data files data-small, data1, data2 and data3 in `fa12/hw5/test/`. You can load them onto the postgresql server using psql - Note: The third table has 1M points and may take a minute or two to load !

    $HOME/pgsql/bin/psql -p 11111 nums

    postgres=# CREATE TABLE numbers_small (num int);
    CREATE
    postgres=# CREATE TABLE numbers1 (num int);
    CREATE
    postgres=# CREATE TABLE numbers2 (num int);
    CREATE
    postgres=# CREATE TABLE numbers3 (num int);
    CREATE
    postgres=# COPY numbers_small FROM '[full path to your repo here]/fa12/hw5/test/data-small' DELIMITER ',';
    COPY 10
    postgres=# COPY numbers1 FROM '[full path to your repo here]/fa12/hw5/test/data1' DELIMITER ',';
    COPY 80000
    postgres=# COPY numbers2 FROM '[full path to your repo here]/fa12/hw5/test/data2' DELIMITER ',';
    COPY 10000
    postgres=# COPY numbers3 FROM '[full path to your repo here]/fa12/hw5/test/data3' DELIMITER ',';
    COPY 1000000

Note that this step needs to be done only once, as long as you do not wipe out your database.

### Testing

We can now run some queries to examine the counts we get using our sketch and compare that to an accurate count. The syntax for our APPROX_COUNT operator is 

    APPROX_COUNT(k, width, depth) - where k is how many of the highest frequency tuples we should fetch
                                          width and depth are the parameters of the count min sketch

First, lets test if our top-k is working correctly by using the very small dataset containing 10 rows. Try the following query

    SELECT num, APPROX_COUNT(10, 10, 4) AS count FROM numbers_small GROUP BY num ORDER BY count DESC;

Make sure that the output matches what is expected -- If not, jump over to the debugging section to figure out whats wrong. 

Now, given that our sketch works correctly for tiny amounts of data, lets try a bigger test. Execute the following queries:
The first query uses our APPROX_COUNT operator, while the second one computes an exact count.

    SELECT num, APPROX_COUNT(10, 2000, 4) AS count FROM numbers1 GROUP BY num ORDER BY count DESC;
    SELECT num, COUNT(*) AS count FROM numbers1 GROUP BY num ORDER BY count DESC limit 10;

This is testing the CountMin sketch using a dataset of 80000 rows using width of 2000 and depth of 4 (8000 counters in total). 
First, the answers you get should closely match the answer of the second query which computes accurate Top-K. To double-check, here is the output we got:

	nums=# select num, count(*) as C from numbers1 GROUP BY num ORDER BY C DESC limit 10;
	 num |   c
	-----+-------
	   1 | 16698
	   2 |  7210
	   3 |  4483
	   4 |  3125
	   5 |  2372
	   6 |  1964
	   7 |  1632
	   8 |  1412
	   9 |  1204
	  10 |  1098
	(10 rows)

	nums=# select num, approx_count(10, 2000, 4) as C from numbers1 group by num order by C desc;
	 num |   c
	-----+------
	   1 | 16701
	   2 |  7212
	   3 |  4485
	   4 |  3127
	   5 |  2374
	   6 |  1967
	   7 |  1635
	   8 |  1414
	   9 |  1207
	  10 |  1099
	(10 rows)

Wow ! Now isn't that cool that we can use 1/10th of the space and get results that are very close to the actual results.
     
### Reporting Test Results

As you saw in the previous section the CountMin sketch performs pretty well on `numbers1` while using 1/10th of space.
Generally speaking the sketch performs better as we increase the width and depth. However this is not the same for all datasets. In this section you will try to find what is the lowest value of `width*depth` (total space used) for which our counter works well.

The first step for this is to define when are we happy with our APPROX_COUNT results. We will define this as follows:

1. We get the same top results (num column) as the accurate query - a.k.a 100 % recall (not necessarily in same order).
2. The frequency for each result is within 4% (c column) of the accurate query => `|reported freq - actual freq| / actual freq < .04`


Consider width values (100, 300, 700, 1300, 2300, 4300) and depth values (2, 4, 8, 16). In a text file named `results.txt`, write down the lowest values of `width*depth` that works well for each of our data files (data1, data2, data3).  Repeat this for K=10 and for K=5 (Top-10 and Top-5 queries). Your answers should be in the following format:

    <filename>,<k>,<width>,<depth>
    --- example ----
    data1,10,1,10
    data1,5,1,10


#### Timing information

The APPROX_COUNT operator should also be faster as we maintain much lesser state compared to the other aggregation strategies. In this section, you will collect timing information from the log to verify this.

If you examine the log file, you will see messages like this at the end of each query:

	LOG:  QUERY STATISTICS
	DETAIL:  ! system usage stats:
    	 	 !   0.553865 elapsed 0.544034 user 0.008001 system sec
	         !   [2.404150 user 0.032002 sys total]
	         !   0/0 [0/8] filesystem blocks in/out
	         !   0/56 [0/9375] page faults/reclaims, 0 [0] swaps
	         !   0 [0] signals rcvd, 0/0 [0/0] messages rcvd/sent
	         !   0/51 [2/218] voluntary/involuntary context switches
	         ! buffer usage stats:
	         !   Shared blocks:       4425 read,          0 written, buffer hit rate = 0.00%
	         !   Local  blocks:          0 read,          0 written, buffer hit rate = 0.00%
	         !   Direct blocks:          0 read,          0 written
	STATEMENT:  SELECT num, APPROX_COUNT(10, 1000, 4) AS count FROM numbers2 GROUP BY num ORDER BY count DESC;


The time taken to execute this particular query is denoted as `elapsed` in the output. In the above example it is `0.553865 elapsed`, which means the query took 0.55 seconds.

Consider the table `numbers3` for this section. Report the time taken by the approximate query for of k in (10, 20, 50, 100) and with the width set as 1000 and depth set as 4. Also measure the time taken by the accurate query for the same values of K. Your file should be named `performance.txt` and should have lines of the format:

      <k>,<time_taken_by_approx>,<time_taken_by_accurate>
       ---------- example -------------------
      10,0.12321,0.43532
      20,0.87987,0.54646

**NOTE:** The time to run a query may differ between runs and may also be different on each machine. We will take this fact into account when grading these numbers and will put much more weight in executing similar queries and measuring the time taken in our grading scripts.

### Debugging

#### Logging

At any point in a function, you can insert an elog() statement to output a message to the log file, using the same syntax as printf():

    elog(LOG, "Two plus three is %d", 2+3);

This may be helpful for debugging purposes. However, make sure you remove all the debugging logging from your code before submission, since writting debugging logs may incur significant overhead and make your program fail to finish when we test it.

#### GDB

You can use gdb to debug your development on PostgreSQL. First, start psql. In a separate terminal window, you first need to determine the PID of the backend process. The simplest way to do this is to locate the "postgres" process which corresponds to your psql session in the output of `ps aux`:

    $ps aux | grep postgres
    shivaram  5881  0.0  0.0  54684  4172 pts/4    S    21:17   0:00 /home/shivaram/pgsql/bin/postgres -D /home/shivaram/pgsql/data -p 11111 -s
    shivaram  5890  0.0  0.0  54684   948 ?        Ss   21:17   0:00 postgres: writer process
    shivaram  5891  0.0  0.0  54684   720 ?        Ss   21:17   0:00 postgres: wal writer process
    shivaram  5892  0.0  0.0  54816  1188 ?        Ss   21:17   0:00 postgres: autovacuum launcher process
    shivaram  5893  0.0  0.0  17824   980 ?        Ss   21:17   0:00 postgres: stats collector process
    shivaram  5924  0.0  0.0  55888  2588 ?        Ss   21:20   0:00 postgres: shivaram nums [local] idle

Next, grab the PID of the process which corresponds to your db (nums in this case) -- which is the first numeric column in the output of ps. Attach to the backend "postgres" process using gdb:

    gdb ~/pgsql/bin/postgres 5924

Once gdb has attached to the backend process, you might want to set a breakpoint inside the replacement policy code, and then use the "continue" command to resume the execution of the backend process. For example:

    (gdb) break nodeAgg.c:1510 

##Submission

You will need to submit the following files.

* src/backend/utils/hash/cmsketch.c
* src/include/utils/cmsketch.h
* src/backend/executor/nodeAgg.c
* src/include/nodes/execnodes.h
* results.txt: Results of width and depth. Please refer to the [Reporting Test Result](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#reporting-test-results) section for details.
* performance.txt: Running time for different values of k. Please refer to the [Reporting Test Result](https://github.com/cs186-fa12/fa12/blob/master/hw5/README.md#reporting-test-results) section for details.
* README: If you are using slip days, your README should contain a single digit indicating the number of slip days you wish to use. For example, if you wanted to use two slip days, the README would consist of only one line with the number: `2`. If you are not using any slip days, the README should be empty.
* MY.PARTNERS: This will be auto-generated when you run the submit hw5 script.

Make sure the source files `cmsketch.c`, `cmsketch.h`, `nodeAgg.c`, and `execnodes.h` include all the changes you have made to the source. We will be testing and grading your code by patching these files to the postgres source.

On an inst machine, create a folder and put in it only the files to be submitted. You can transfer the files to the inst machines with:

    scp hw5.tar.gz cs186-XX@hive1.cs.berkeley.edu:[path to put the file]

Go to the folder with all the above files, and type ``submit hw5``. You will be asked to input your partner's login first.

```
submit hw5
Please enter the logins of your partner(s), if any.
Enter '.' to stop.
Login:
...
(this part omitted here)
...
Created MY.PARTNERS file.
Looking for files to turn in...
Submitting cmsketch.c.
Submitting cmsketch.h.
Submitting execnodes.h.
Submitting nodeAgg.c.
Submitting performance.txt
Submitting results.txt
Submitting README.
The files you have submitted are:
    ./cmsketch.c ./cmsketch.h ./execnodes.h ./MY.PARTNERS ./nodeAgg.c ./performance.txt ./results.txt ./README
Is this correct? [yes/no] y
Copying submission of assignment hw5....
Submission complete.
```

