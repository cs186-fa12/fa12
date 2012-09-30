# Homework 2: loCALee - Database Schema Design and Web Application Server Code in Ruby On Rails
### CS186, UC Berkeley, Fall 2012
### Points: [10% of your final grade](https://sites.google.com/a/cs.berkeley.edu/cs186-fa2012/additional-course-information)
### Note: *This homework is to be done in pairs!*
### Due: Wednesday, 10/3, 11:59 PM (You have 4 slip days for all CS186 projects. Use them wisely)

##Edits
*  9/29  8:24pm - Added sample results for Part III when using `generate_fake_data` script.  Also, added clarification that the queries should not return users who create 0 posts (for query 1), or follow 0 locations (for query 3).
*  9/26  8:28pm - The `generate_fake_data` script had a bug in it, so the code was updated. Run `git pull` to get the updated script.
*  9/26  2:44pm - FYI: If the server crashes when trying to sign up a user, please make sure the password is at least 5 characters long.
*  9/24 12:12pm - Extended the deadline to 10/3.
*  9/22  9:05pm - Added documentation on how to run a [script to generate fake data](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#generating-sample-data).
*  9/19 10:29pm - Added a clarification on the [relationship between tables and models](https://github.com/cs186-fa12/fa12/blob/master/hw2/RailsBackground.md#relationship-between-database-tables-and-models), and a section on how [CS186 topics related to Rails](https://github.com/cs186-fa12/fa12/blob/master/hw2/RailsBackground.md#how-does-this-relate-to-cs186-concepts), to the Rails Background page.
*  9/17  6:54pm - Clarify what a "post" is.
*  9/16  8:10pm - Added clarification for what the keys and values of the hashes should be, to the end of Part II.

##Table Of Contents
*  [Important](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#important)
*  [Description](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#description)
*  [Your Mission](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#your-mission)
*  [Development Environment](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#development-environment)
*  [Rails Background](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#rails-background)
*  [Specifications](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#specifications)
*  [Part I: Database Schema Design (Rails Migrations and Models)](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#part-i-database-schema-design-rails-migrations-and-models)
*  [Part II: Web Application Server (Rails Controllers)](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#part-ii-web-application-server-rails-controllers)
*  [Part III: Analytic Queries (SQL Queries)](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#part-iii-analytic-queries-sql-queries)
*  [Submission](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#submission)
*  [Acknowledgements](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#acknowledgements)

##IMPORTANT!
*  Use the virtual machine for this project. Details are in the [Development Environment](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#development-environment) section.
*  Read our [Rails Background](https://github.com/cs186-fa12/fa12/blob/master/hw2/README.md#rails-background). It discusses all the major concepts needed for this project.
*  The official [Rails Guide](http://guides.rubyonrails.org/) is also your friend. It was my best friend last week.

##Description
You have just been hired by a hot new start-up, loCALee! Congratulations!

loCALee hired you because they want you to head their development team, and need your expertise in database schema design.
You are to implement their backend service implementation before their release on October 3, 2012.
loCALee is a Twitter variant, but it is heavily focused on locations (loCALee ~ locally).
All users post updates to locations, and all users follow locations, not other users.
For this assignment, you will implement this functionality to open up the service to the public soon!

##Your Mission
Design and implement loCALee, a fully functional Twitter variant, where all updates are associated with locations, and all users follow locations.
Also, write several analytical SQL queries to gain insight on how loCALee is being used.

Your main tasks include:
*  Design and implement the database schema which supports the functionality of loCALee.
*  Implement the app server with Ruby on Rails to connect the UI with the database.
*  Write several SQL queries which for reporting interesting statistics.

##Development Environment
These are the steps to get your development environment set up.

###Virtual Machine
For this assignment, you will be using a virtual machine to develop for this web application.
Follow the instructions at http://alpha.saasbook.info/bookware-vm-instructions#TOC-Downloading-and-running-the-courseware-on-your-own-computer to install [VirtualBox](https://www.virtualbox.org/), and the virtual machine image.
The virtual machine image already includes all the software necessary to develop this Rails application.

You may optionally only develop on the inst machines, but for this option, the rails app will not run locally.
The only way to see the app is to deploy it using [heroku](http://www.heroku.com/).

**We HIGHLY, HIGHLY recommend using the virtual machine for this assignment. Please try as hard as possible to use the VM.**

###Getting the base code
In a fresh virtual machine, you will have to clone the git repo with all the files.

    % cd
    % git clone git://github.com/cs186-fa12/fa12.git

If you have already cloned the repo before, you can run `git pull` to get the new files in the `hw2/` directory.
All the files relevant to this project will be in the `fa12/hw2/localee` directory.

###Running the app in a Virtual Machine
Running the web app for the first is very simple within the virtual machine.  In the `fa12/hw2/localee` directory, simply run:

    % rails server

This will start the rails server and you can see the app running locally at: [http://localhost:3000](http://localhost:3000)

The first time you run the server, you may be instructed to run:

    % bundle install

This will not work on the inst machines, so you must use heroku.

###Running the app on Heroku
**These instructions are only required if you are not using a virtual machine for the project. However, you may choose to run on heroku to be able to publicly access your implementation of loCALee.**

Go to [http://www.heroku.com/](http://www.heroku.com/) and sign up for a free account.
You may also have to install the [heroku toolbelt](heroku toolbelt).
Then you have to login into heroku with the command:

    % heroku login

If you are running on an inst machine you must do the following steps (on a vm you can ignore this):

    % ssh-keygen -t rsa
    % heroku keys:add

Enter your login info when prompted (that you used to sign up at heroku.com) and respond 'yes' when it asks to create a public key.

You can create a heroku app with:

    % heroku create --stack cedar
    
After the heroku app is created, you can start pushing new changes with:

    % git add <the new files>
    % git commit -m "your commit message"
    % git push heroku master
    
This will display what the url is for your app, so you can visit it with any browser.

You may have to run the migration once to create the initial set of tables with the command:

    % heroku run rake db:migrate

####Sharing with Heroku
If you would like to collaborate with your partner on the same heroku app, this is very straightforward.
Simply have one of you partners follow the steps above then do:

    % heroku sharing:add otherPartner@whatever.com

Then the otherPartner (after performing heroku login) can execute:

    % git clone -o heroku git@heroku.com:theirapp.git

theirapp is the name of the app you creating this will be the name that is something like "flying-dove-1234" or "shivering-pine-5678" something.
If you get a publickey error at that point execute the ssh-keygen and heroku keys:add steps described above.

And you will both have access to the app/git repo!!
If you would like more info check out: http://devcenter.heroku.com/articles/sharing

##Rails Background

We created a [Rails background](https://github.com/cs186-fa12/fa12/blob/master/hw2/RailsBackground.md) page for you to learn some of the concepts of Rails.

**Read the background page to learn about everything you need to know for this project.
It will really help to understand how to complete this project.
I did not know Rails before doing this project, so everything I had to learn, I put in the background page.**

You will also need to refer to the [Rails Guide](http://guides.rubyonrails.org/) to read about the details.

##Specifications
These are the specifications for the loCALee project:

*  Users must create accounts to use loCALee
   *  Users must have unique emails
   *  Users must have a name
   *  Users must have a password
   *  All the logging in/signing in and session management has already been implemented for you
*  Users can create locations
   *  Locations must have a name
   *  Locations must also have GPS coordinates (latitude and longitude)
   *  The locations page show all the posts to that location, with the latest post first
*  Users can create posts to locations
   *  A post is a piece of text the user creates for the particular location
   *  Posts are always associated with a single location
   *  Posts are always associated with the user who posted it
*  Users can follow or unfollow locations
   *  A user can only follow a location at most once
   *  Following a location means the user sees all posts from that location in their stream
   *  The user does not have to be following a location in order to create a post to that location
   *  Users can follow 0 or more locations
   *  Users' homepages show their stream of all the posts from all the locations they follow, with the latest post first
      * For example: if a user follows location A and location B, and A has 2 posts and B has 3 posts, their stream will show 5 posts, with the latest post first

##Part I: Database Schema Design (Rails Migrations and Models)
Since you are an expert in ER models and schema design, your first task is to design the database for this project that will support all the functionality in the specifications above.
You will need to design your database schema and create migrations and models to represent your design.
Working `Users` migration and model have already been created for you.
It is not necessary to modify either the `Users` migration or the model to complete the assignment.
However, you might want to add associations and/or methods to the `Users` model, so that can be done by adding code to the allowable section of the model file.

##Part II: Web Application Server (Rails Controllers)
The second task for this project is to the actually implement the loCALee backend code in Rails.
For this part, you will only need to modify the file: `app/controllers/app_query.rb`

In that file, there are several functions which need your implementation of the queries in order to create the functional web application.
Do not modify the parts of the file which explicitly forbid any modification.

You are free to use any method of querying the database as you like.
As long as the proper variables are set in the correct way, you may use Rails querying or SQL queries.
The comments in the code for each method has more detail on what must be performed.

**Note: For this part of the project, you may write SQL queries. Writing associations and Rails-style queries are not required (but may be easier).**

The methods you will need to implement are:

*  `get_following_locations(user_id)`
   *  Returns all the locations being followed by the current user
*  `get_posts_for_location(location_id)`
   *  Returns the location information and all posts for a given location
*  `get_stream_for_user(user_id)`
   *  Returns the current user's stream of posts from all the locations the user follows
*  `get_nearby_locations(nelat, nelng, swlat, swlng, user_id)`
   *  Retrieves the locations within a GPS bounding box
*  `create_location(location_hash)`
   *  Creates a new location
*  `follow_location(user_id, location_id)`
   *  Makes the current user follow a location
*  `unfollow_location(user_id, location_id)`
   *  Makes the current user unfollow a location
*  `create_post(user_id, post_hash)`
   *  The current user creates a post for a location
*  `create_user(user_hash={})`
   *  Creates a new user
*  `get_all_posts`
   * Returns all the posts
*  `get_all_users`
   * Returns all the users
*  `get_all_locations`
   * Returns all the locations

More detailed specifications are in the comments for each method.
In the comments, most of the return types will be array of hashes, or hashes.
The comments specify what the keys and values of the hashes should be.
For example, if it says a hash should include ":name - the name of the location", it means the key is `:name` and the value is the value of the name.
Therefore `h[:name]` will be the name of the location.

####Running SQL Queries Directly on the Database

To run SQL queries directly on the database, you can run:

```ruby
ActiveRecord::Base.connection.execute("SELECT ...")
```

This will execute the SQL statement and return an array of rows.
Each row is represented as a Ruby hash, where the keys are the string representation of the column names, and the values are the values for that column.

####Debugging
The UI for loCALee always provides good input data, but in order to verify your schema and implementation, we will test your code with potentially bad or missing data.
To debug your code and schema and models, it may be useful to be able to run the methods.
You can run those methods in the rails console:

```
% rails console
  # create a new AppQuery instance
> aq = AppQuery.new
 => #<AppQuery:0x000001047ba778> 
  # now you can call any of those methods
> aq.get_stream_for_user(...)
```

Use the console to make sure your implementation/schema prevents the database from being corrupted.

####Generating Sample Data
We have provide you with a simple script which generates data by using the methods in the file `app/controllers/app_query.rb`.
It should be run with an empty database, so you will have to drop the database (erases all data!) before running this script.
Here is how you can generate the data:

```
> rake db:drop # drop all the tables from the database
> rake db:migrate # re-create the tables/schema from your migrations
> rake generate_fake_data # our script to generate data for your app
```

The script generates 15 users and 15 loations, where each user has the name/email/password `userX` (where X is 1 to 15), so you can login with a generated user.
Hopefully, this script will be helpful in testing your implementation.

##Part III: Analytic Queries (SQL Queries)
In addition to the interactive web application backend implementation, you also need to write some analytics queries in order to see how the service is being used.
For this part, you will only need to modify the file: `app/controllers/app_query.rb`
In the file `app/controllers/app_query.rb`, you will need to write SQL queries for the reports queries.

You will have to implement methods which return strings of the SQL query.
The methods you will have to implement are:

*  `top_users_posts_sql`
  * Retrieve the top 5 users who created the most posts.
  * Do not retrieve users who created 0 posts.
  * Retrieve at most 5 rows.
  * Returns a string of the SQL query.
  * The resulting columns names must include (but are not limited to):
     * `name` - name of the user
     * `num_posts` - number of posts the user has created
*  `top_locations_unique_users_sql`
  * Retrieve the top 5 locations with the most unique posters. Only retrieve locations with at least 2 unique posters.
  * Retrieve at most 5 rows.
  * Returns a string of the SQL query.
  * The resulting columns names must include (but are not limited to):
     * `name` - name of the location
     * `num_users` - number of unique users who have posted to the location
*  `top_users_locations_sql`
  * Retrieve the top 5 users who follow the most locations, where each location has at least 2 posts
  * Do not retrieve users who follow 0 locations.
  * Retrieve at most 5 rows.
  * Returns a string of the SQL query.
  * The resulting columns names must include (but are not limited to):
     * `name` - name of the user
     * `num_locations` - number of locations (has at least 2 posts) the user follows

####Sample Results of generate_fake_data

If you use the `generate_fake_data` script above, the results of the queries should look similar to these.

**Note: Since the queries are only returning the top 5, the last row(s) may be different in other correct implementations because of potential ties.**

```
Top 5 Users With the Most # of Posts
User   | # of Posts
-------+-----------
user5  | 26
user12 | 22
user1  | 20
user9  | 20
user4  | 19

Top 5 Locations With Posts From the Most # of Unique Users (at least 2 unique users)
Location Name | # Unique Users
--------------+---------------
location1     | 11
location9     | 11
location2     | 10
location14    | 10
location5     | 9

Top 5 Users Following the Most # of Locations With at Least 2 Posts
User   | # of Locations
-------+---------------
user8  | 6
user2  | 5
user9  | 5
user14 | 5
user11 | 4
```

##Submission
We will drop/erase and migrate the database before testing your implementation, so make sure that works.
To test it out (**this will delete all your data**):

```
> rake db:drop # drop all the tables from the database
> rake db:migrate # re-create the tables/schema from your migrations
```

The files you need to submit are:
*  hw2.tar
   *  This file has to be created in your virtual machine (or where you developed from), because that is where your implementation is.
   *  To be extra nice to your GSI's, you can delete the `hw2/localee/tmp/` directory. =)
   *  In the `fa12/hw2/` directory, run `tar -cvf hw2.tar localee` to generate the file.
   *  It is good to check the tar file by simply extracting in some other location, and running the app.
   *  You can transfer the file to the inst machines with `scp hw2.tar cs186-XX@hive1.cs.berkeley.edu:/path/to/where/you/want/the/file/`
*  README
   *  If you are using slip days, your README should contain a single digit indicating the number of slip days you wish to use.
      For example, if you wanted to use two slip days, the README would consist of only one line with the number: `2`
   *  If you are not using any slip days, the README should be empty.
*  MY.PARTNERS
   *  This is auto-generated for you when you run the submit hw2 script.

**Note: The simplest way to create your submission is to create a directory on the inst machines, with just the files above.**

On an inst machine, run `submit hw2`:

```
% submit hw2
Please enter the logins of your partner(s), if any.
Enter '.' to stop.
...
...
Created MY.PARTNERS file.
Looking for files to turn in....
Submitting hw2.tar.
Submitting README.
The files you have submitted are:
    ./MY.PARTNERS ./README ./hw2.tar 
Is this correct? [yes/no] y
Copying submission of assignment hw2....
Submission complete.

```



##Acknowledgements
Special thanks to Denny Britz for teaching me Rails!
