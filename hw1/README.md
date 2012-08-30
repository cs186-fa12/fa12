# Homework 1: Enron email command-line wrangling 
### CS186, UC Berkeley, Fall 2012
### Points: [5% of your final grade](https://sites.google.com/a/cs.berkeley.edu/cs186-fa2012/additional-course-information)
### Note: *This homework to be done individually!*
### Due: Friday, 9/7, 11:59 PM (You have 4 slip days for all CS186 projects. Use them wisely)

##Description
This assignment will give you some experience with a typical task in modern data management:
using command-line tools to "wrangle" a bunch of publicly-available data into a more structured 
format suitable for subsequent analysis.  In particular, we will 
look at data from the notorious Enron email corpus, subsetted by
 [Berkeley's Enron Analysis website](http://bailando.sims.berkeley.edu/enron_email.html).
 
Along the way you will need to exercise your thinking about efficient out-of-core
techniques.  For those of you who haven't used Ruby before, this assignment will also be a forcing function to 
play around with the language a bit.  You will need to do more with it in subsequent assignments.

###Your challenge
Given a large directory of email messages, generate [csv](http://en.wikipedia.org/wiki/Comma-separated_values) files 
that efficiently capture the message contents in a structured form suitable for analysis via a database 
or statistical package.

###Your tools
For this assignment, you are limited to using [Ruby](http://ruby-lang.org), [bash](http://www.gnu.org/software/bash/), and the [standard Unix utilities](http://en.wikipedia.org/wiki/List_of_Unix_utilities).  We strongly encourage you to use Ruby's built-in [CSV](http://ruby-doc.org/stdlib-1.9.2/libdoc/csv/rdoc/CSV.html) and [find](http://ruby-doc.org/stdlib-1.9.2/libdoc/find/rdoc/Find.html) libraries, and the [mail](https://github.com/mikel/mail/blob/master/README.md) gem to deal with email files, directory trees, and csv files.  All of these are pre-installed on the instructional machines for you.  You should not need to use any additional Ruby gems in your solution. (You may find [ruby-debug](http://bashdb.sourceforge.net/ruby-debug.html) useful along the way -- it is also installed.)

We assume that CS186 students can pick up scripting languages like Ruby and bash on their own; there will be no Ruby or bash training as part of the class.  The course webpages have some [suggested resources for Ruby](https://sites.google.com/a/cs.berkeley.edu/cs186-fa2012/additional-course-information).

###Your constraints
You need to be able to handle an input directory that is far larger than the memory of the computer that runs the script.  To do so, you should:

1. write *streaming* Ruby and bash code that only requires one email message to be in core at a time, and
2. utilize UNIX utilities like `sort` that provide out-of-core divide-and-conquer algorithms.  


You should not need to write much code in either Ruby or bash.  Take advantage of UNIX utilities as much as you can.  In particular, note that there is no need for you to write an out-of-core algorithm to complete this homework.

##Getting started
To follow these instructions **use your CS186 inst account on one of the Linux servers (hive1.cs, hive2.cs, ..., hive28.cs)**. 

*(CS186 accounts are set up with Ruby v1.9.2 and bash version 4.2.10(1). You can code on your own computer, but the CS186 staff will only answer configuration questions pertaining to the CS186 course accounts.  And eventually you need to turn in a solution that runs "out of the box" on the instructional machines.)*

Log into your class account, and check out the git repository for the course:

    % cd
    % git clone git://github.com/cs186-fa12/fa12.git

This will create a directory called `fa12` in your home directory, which will contain a subdirectory called `hw1`. Change directory into there and look around:

    % cd fa12/hw1
    % ls
    hw1.sh    README.md         test              tokens.csv
    mail.csv  state_counts.csv  token_counts.csv
    %

In addition to this README file, you will see:

* `hw1.sh`, a skeleton of the bash file you will write
* `test`, a subdir with ruby unit tests you can use to validate your solution,
* `mail.csv`, `state_counts.csv`, `token_counts.csv` and `tokens.csv`:
   correctly-formatted example outputs.


##Specification
Your solution should be driven by a `hw1.sh` script that is passed one argument: the root of a directory that contains valid email files:

    % ./hw1.sh ~cs186/fa12/hw1/enron_tiny
    
The directory may contain arbitrary files, but the ones that are to be parsed as email must have names ending in ".txt".

The script should overwrite the four example csv output files, as follows:

* `mail.csv` should be a legal csv file containing the same header row as the example.  The remainder of the file should contain the specified fields from all the email messages.  See the discussion of "Reading an email" in the [documentation on the `mail` gem](https://github.com/mikel/mail/blob/master/README.md).
* `tokens.csv` should be a csv file with the same header row as the example: `message_id,token`.  This file is generated by taking the `body` field of a message, and splitting it on non-alphabetical characters into separate tokens (substrings) which are converted to all-lowercase characters.  After splitting and lowercasing, each token should be copied into the `tokens.csv` file, prepended by the associated `message_id` (and a comma).  *Note that a given token may appear multiple times per message\_id, and/or multiple times across different message\_id  s.*
* `token_counts.csv` should have the same header row as the example, and sum up the number of occurrences of each *distinct* token in the `tokens.csv` file.
* `state_counts.csv` is intended to store the rough result of the question "how often is each state mentioned in an email?" It should have the same header as the example file, and then contain those rows from `token_counts.csv` with the (lowercase) name of a US state in the `token` field.  For states containing two tokens in their name, we will look for rows containing only one of the two tokens:
    * "rhode island": *look for rows containing "rhode" (the first token)*
    * "new hampshire", "new jersey", "new mexico", "new york", "north carolina", "north dakota", "south carolina", "south dakota", "west virginia": *look for rows containing the second token*.  Note that this will, for example, mix up "north carolina" and "south carolina" into a single token; that's fine for now.
* Your final solution should be able to run `test/tc_full` in under 5 minutes!

###Testing
A simple [Ruby unit test](http://en.wikibooks.org/wiki/Ruby_Programming/Unit_testing) is provide in `tc_sanity.rb`.  If your code is working, you should see something like this if you type the first line to a bash shell:

    % ruby test/tc_sanity.rb
    ruby test/tc_sanity.rb 
    Loaded suite test/tc_sanity
    Started
    .
    Finished in 1.471638 seconds.

    1 tests, 13 assertions, 0 failures, 0 errors, 0 skips

    Test run options: --seed 53816
    %

The tc_sanity test runs your `hw1.sh` script against a handful of emails taken from the Enron corpus, and compares your output to what the solution produced.  You should have a look at the unit test files -- they are simple and you'd be wise to understand what they're checking.

Our grading script will compare your code against the approximately [1700 emails](http://bailando.sims.berkeley.edu/enron/enron_with_categories.tar.gz) provided on the Berkeley Enron Analysis website.  (We may also test against other data.)  To test against the full Berkeley Enron data, you type:

    % ruby test/tc_full.rb

and hopefully you get 0-failure/0-error output similar to the listing above.  

We need to ensure that your code will scale to much bigger data sets.  To this end, the test scripts use Ruby's [setrlimit](http://www.ruby-doc.org/core-1.9.2/Process.html#method-c-setrlimit) command to cap the amount of virtual memory your hw1.sh script allocates.  If you see something like this:

    nogood.rb:3:in `block in <main>': failed to allocate memory (NoMemoryError)
		from nogood.rb:3:in `each'
		from nogood.rb:3:in `<main>'
		
then your code is not doing appropriate streaming and/or divide-and-conquer!

##Notes
* As noted in `hw1.sh`, the last line should say "exit 0" to indicate a successful completion.  This is important for making the tests run correctly!
* There could be files in the directory that are not reasonable email files.  Still, the Ruby `mail` library will try to treat them as mail.  It will just return a lot of empty mail header fields.  Hence you may want to skip some files by checking if relevant email fields are empty via the `.nil?` predicate in Ruby -- e.g. `if mail_file.from.nil?` is true, it's not a mail file of interest to us.
* It appears that Ruby's File#write is quite slow.  Consider using `$stdio` and [UNIX pipes](http://en.wikipedia.org/wiki/Pipeline_(Unix)) instead, or perhaps the [CSV library's](http://ruby-doc.org/stdlib-1.9.2/libdoc/csv/rdoc/CSV.html) method for writing to csv files.
* Ruby has nice libraries for email, directory walking, csv manipulation, and string manipulation.  But the UNIX utilties are written in C and are faster than anything you will write in Ruby.  So if your code seems very slow and you want to speed it up, try to use less Ruby and work more with the UNIX utilities.  Your final solution should complete the `tc_full` test in under 5 minutes on an unloaded "hive" machine (and it could go much faster!)
* If you lose the original example csv output files, you can always recreate the original copies by typing:
```
% git checkout <foo>.csv
```
or by looking on the website at [https://github.com/cs186-fa12/fa12](https://github.com/cs186-fa12/fa12).

## Turnin instructions
Cd into your solution's directory and run the `submit hw1` command.  It will automatically collect your `hw1.sh` file, but you will need to explicitly tell it about other files:

* yes, *do* turn in any other bash or ruby files your solution uses, and 
* no, *do not* turn in extraneous stuff, especially the common files from the git repo (the csv files, etc.)  

Your turnin session should look something like this:

    % submit hw1
	Looking for files to turn in....
	Turn in ./README.md?  [yes/no] n
	Submitting hw1.sh.
	Turn in ./mail.csv (it's 11924576 bytes long)?  [yes/no] n
	Turn in ./state_counts.csv?  [yes/no] n
	Look at files in directory ./test? [yes/no] n
	Skipping directory ./test.
	Turn in ./token_counts.csv (it's 291537 bytes long)?  [yes/no] n
	Turn in ./tokens.csv (it's 85957509 bytes long)?  [yes/no] n
	Turn in ./bar.rb?  [yes/no] y
	Turn in ./bletch.rb?  [yes/no] y
	Turn in ./foo.rb?  [yes/no] y
	The files you have submitted are:
		./bar.rb ./bletch.rb ./hw1.sh ./foo.rb 
	Is this correct? [yes/no] y
	Copying submission of assignment hw1....
	Submission complete.
	%
	
## Acknowledgements
Much thanks to Professor Hellerstein for putting this assignment together