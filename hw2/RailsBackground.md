# Ruby on Rails Background
#### This document is here to help you with hw2. Please fully read the document.
#### Most of the information here is from the [Rail Guide](http://guides.rubyonrails.org/index.html). It is the best reference and contains all the details for the concepts mentioned here.

##Rails Background
Rails makes it easier to create schemas and query the database for web apps.
The [Rails guide](http://guides.rubyonrails.org/index.html) is the best resource for all Rails features.
This section will discuss some of the main features relevant to this project.

In the Rails framework, schema design and database querying are achieved using ActiveRecord [Migrations and Models](http://guides.rubyonrails.org/migrations.html).
Migrations are basically fancy [DDL](http://en.wikipedia.org/wiki/Data_Definition_Language) statements in Ruby, and Models are basically ruby classes representing an entity.

##ActiveRecord Migrations
**Please refer to the [Migration guide](http://guides.rubyonrails.org/migrations.html) for more details.**

Migrations are how Ruby on Rails create tables and modify schemas in the database.
Instead of writing SQL statements, the DDL is written in Ruby.

Rails also allow query access to the tables through the Ruby language, in addition to SQL queries.
Database tables can be accessed through Models, which are just Ruby classes.

To create a new migration you can run:

    % rails generate migration Something
    
and that will generate the migration file

    db/migrate/[some_timestamp]_create_somethings.rb

However, if you also want to create the associated model along with the migration, you can run:

    % rails generate model Something
    
This will generate the model file and migration file for `Something`.
The files are:

    db/migrate/[some_timestamp]_create_somethings.rb
    app/models/something.rb

The create statements should be added to the `?_create_somethings.rb` migration file.
The [Migrations guide](http://guides.rubyonrails.org/migrations.html) has more examples on how to create columns.
We have already created the migration for Users, and the code is below:

```ruby
class CreateUsers < ActiveRecord::Migration
  def change
    create_table :users do |t|
      t.string :name
      t.string :email
      t.string :password_digest

      t.timestamps
    end
  end
end
```

This migration creates a `Users` table with the columns, `name`, `email`, and `password_digest`.
Each of the fields are of type string in the database.
The line `t.timestamps` auto-generates 2 additional fields `created_at` and `updated_at`, which are timestamps.
**Also, all generated migrations have an implicit field named `id` which is the primary key for that table.**
Therefore, this migration will create the `Users` table with 6 columns: `id`, `name`, `email`, `password_digest`, `created_at`, `updated_at`.

For this assignment, you will create additional migrations for the tables you want to create.
You do not have to modify the `Users` migration for this assignment.

###Foreign Keys
You may want to create foreign keys between tables in your database.
In order to reference another table for a foreign key, you can just add a column with a special name.
For example, say you have a `Students` table and an `Enrollments` table, and the `Enrollments` table needs to reference the `Students` table.
The `Enrollments` table will look like this:

```ruby
class CreateEnrollments < ActiveRecord::Migration
  def change
    create_table :enrollments do |t|
      t.integer :student_id
    end
  end
end
```

By specifying `student_id`, it is telling Rails that the column is a foreign key referencing the `id` field of the `Students` table.

**Note: the naming in important for Rails to figure out what to reference. The [Associations: Tips and Warnings](http://guides.rubyonrails.org/association_basics.html#tips-tricks-and-warnings) is another good resource in determining how columns should be named.**

###Running Migrations
In order to actually apply the migrations you create, you have to run them on the database.
To apply the migrations, run:

    % rake db:migrate

This will execute all the migration files not run since the last execution of `db:migrate`.

###Modifying Migrations
Sometimes you may have to change the schema of an existing table in the database.
There are 2 ways to do this.

The first way to change the schema is to just edit the migration file you want to change, and then run:

    % rake db:drop
    % rake db:migrate

Since this deletes all of your data, if you were already signed in with a user, the app will fail.
You may have to visit [http://localhost:3000/logout](http://localhost:3000/logout) to clear the session data.

**This is the simplest way, however, this WILL delete all the data in the database.**

The second way to change your schema is to actually create another migration.
The migration will not be a new `CREATE TABLE`, but some other operation.
Read section `2.2 Creating a Standalone Migration` in the [Migration guide](http://guides.rubyonrails.org/migrations.html).

From the guide:

> If the migration name is of the form “AddXXXToYYY” or “RemoveXXXFromYYY” and is followed by a list of column names and types then a migration containing the appropriate add_column and remove_column statements will be created.

    % rails generate migration AddPartNumberToProducts part_number:string

will generate

```ruby
class AddPartNumberToProducts < ActiveRecord::Migration
  def change
    add_column :products, :part_number, :string
  end
end
```

Similarly,

    % rails generate migration RemovePartNumberFromProducts part_number:string

can be used.

Once these new migrations are created, they can be applied to the database like above with: `rake db:migrate`.

**Note: this method of changing the schema will NOT delete the data from the database.**

##ActiveRecord Models
**Please refer to the [Validation guide](http://guides.rubyonrails.org/active_record_validations_callbacks.html) and the [Associations guide](http://guides.rubyonrails.org/association_basics.html) for more details.**

The models are just classes which can be used to access the associated tables in the database.
Models can also be used to enforce constraints (such as foreign key constraints) on the table.
In the example above, the generated model file is `app/models/something.rb`.

**Note: Models are not always required for every table/migration created in the database. This is a decision you can make.**

Since models are just Ruby classes, you can write methods for the class.
Also, the model is associated with the table in the database with the same name.
For example, the `User` model is mapped to the `Users` table in the database.

Since the `User` model is mapped to the `Users` table, all the columns of the table are accessible from the model.
For example, if `u` is an instance of the `User` class, you can access the columns with `u.id`, `u.name` and so on.

Within the model, you can specify [validations](http://guides.rubyonrails.org/active_record_validations_callbacks.html) and [associations](http://guides.rubyonrails.org/association_basics.html).

###Validations
[Validations](http://guides.rubyonrails.org/active_record_validations_callbacks.html) are used to specify constraints on the data in the model/table.
For example, you can define a validation to ensure that all email addresses exist and are unique for users.
In the `User` model provided for you, that validation is defined as:

    validates :email, :presence => true, :uniqueness => true

There are many types of [validation helpers](http://guides.rubyonrails.org/active_record_validations_callbacks.html#validation-helpers) and the guide lists and explains them all.
**You will need to use some of these validation helpers for your assignment.**

###Associations
[Associations](http://guides.rubyonrails.org/association_basics.html) are used to define the relationships between models.
In database terms, they can be thought of as foreign key constraints.
However, associations are not actually enforced by the underlying database.
They are mainly used as shortcuts for common query patterns.

There are 6 types of associations and some may be useful for this project.

*  belongs_to
*  has_one
*  has_many
*  has_many :through
*  has_one :through
*  has_and_belongs_to_many

**We HIGHLY recommend reading the [Association guide](http://guides.rubyonrails.org/association_basics.html) for more details on all of the associations. In particular, look at the diagrams of how the tables/table names work for each of these associations.**

There are many details on each of these associations in the guide.
The [Associations: Tips and Warnings](http://guides.rubyonrails.org/association_basics.html#tips-tricks-and-warnings) section is a very good section explaining how some of the naming and schema should look for associations to work well.

**We HIGHLY recommend reading the [Associations: Tips and Warnings](http://guides.rubyonrails.org/association_basics.html#tips-tricks-and-warnings) section to better understand how tables and foreign keys should be named.**

###Querying the Models
The [Querying guide](http://guides.rubyonrails.org/active_record_querying.html) has all the details on how to query Rails models.

You can query the data in the database through the models (Ruby classes) and not write SQL queries.
Along with associations, models can be very powerful in querying the tables.

Methods are defined on the ActiveRecord models which roughly correspond to different portions of a SQL query.
The methods are:
*  where
*  select
*  group
*  order
*  reorder
*  reverse_order
*  limit
*  offset
*  joins
*  includes
*  lock
*  readonly
*  from
*  having

These methods can be used in combination with each other to fully construct a query.
For example, Rails will take the following line:

```ruby
Client.where("orders_count = ?", 123)
```

and execute

```sql
SELECT * FROM Clients WHERE orders_count = 123;
```

Details on all of these methods are in the [Querying guide](http://guides.rubyonrails.org/active_record_querying.html).

Since associations define the foreign key relationships between models, Rails can use the association information to execute joins without explicitly defining the join.
This can sometimes make querying the models even easier.
Here is an example.

Say you have two models, `Client` and `Address`, and the `Client` table has a foreign key, `address_id`, referencing the `Address` table.
The associations in the models look like:

```ruby
class Client < ActiveRecord::Base
  has_one :address
end

class Address < ActiveRecord::Base
  belongs_to :client
end
```

There are two ways to get the address state from a client:

```ruby
# without using associations
c = Client.find_by_id(2)
# Have to access the address_id first, then find the address of that address_id.
addr = Address.find_by_id(c.address_id).state

# using associations
addr = Client.find_by_id(2).address.state
```

As you can see, by using the associations, you do not have to explictly find the address id, but have direct access to the associated object, defined in the `Client` model.

There are many other examples of querying in the [Querying guide](http://guides.rubyonrails.org/active_record_querying.html).

###Modifying the Models and Associations
To create a new instance of a model, and then save it to the database, you can call [`new`](http://api.rubyonrails.org/classes/ActiveRecord/Base.html#method-c-new) to create a new instance and [`save`](http://api.rubyonrails.org/classes/ActiveRecord/Persistence.html#method-i-save) to validate it and save it to the database.
```ruby
# create a new model
s = Something.new({...})
# you can do stuff to s
...
# save s to the database
s.save
```

To delete a model, just call [`destroy`](http://api.rubyonrails.org/classes/ActiveRecord/Persistence.html#method-i-destroy).

```ruby
s.destroy
```

If an association is `has_one`, that means the association is just a single object, so you can treat it as regular object.

If an association is `has_many` or `has_and_belongs_to_many`, the association is not a single object, but a collection of objects.
When the association is a collection of objects, you can add or delete to the collection by using:

*  `collection << obj_to_add`
*  `collection.delete(obj_to_delete)`

The guides for [`has_many`](http://guides.rubyonrails.org/association_basics.html#has_many-association-reference) and [`has_and_belongs_to_many`](http://guides.rubyonrails.org/association_basics.html#has_and_belongs_to_many-association-reference) have more details.

##How does this relate to CS186 concepts?
coming soon...

