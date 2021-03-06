# Integrating import.io with Drupal

By Jon Peck, jpeck@fluxsauce.com

## Try it yourself!

Clone this repository somewhere local.

I've included a [Drupal VM](http://www.drupalvm.com/) environment which, with light configuration, should work. See their [Quick Start Guide](https://github.com/geerlingguy/drupal-vm#quick-start-guide) first to make sure you have everything you need.

Then, edit `config.yml` and change your `local_path` to wherever you've cloned this repository:

```yml
local_path: ~/projects/drupal_importio
```

Once all the requirements are fulfilled:

```bash
vagrant up
```

* Login - http://drupal-importio.dev/user/login - username "admin", password "admin"
* http://drupal-importio.dev/import
    * Click "California School Ratings"
    * Click Import
* Upper-left hand corner - HOME > Flush All Caches

Want to use the command-line?

```bash
composer install
./vendor/bin/drush @drupal-importio.drupal-importio.dev status
```

Want to be sure that everything is configured the way it was in the presentation?

```bash
./vendor/bin/drush @drupal-importio.drupal-importio.dev -y fra
./vendor/bin/drush @drupal-importio.drupal-importio.dev cc all
```

![Keep Calm](img/clear-cache.png)

### import.io extraction

* Go to New "Magic".
* Use URL: http://school-ratings.com/schoolRatings.php?zipOrCity=94606&schName=&lastOB=distance&qty=64&searchRadius=50&orderBy=rank&dir=
* Click "Get API"
* How would you like to use this API? Bulk Extract

```
http://school-ratings.com/schoolRatings.php?zipOrCity=94606&schName=&lastOB=distance&qty=64&searchRadius=50&orderBy=rank&dir=
http://school-ratings.com/schoolRatings.php?zipOrCity=94606&schName=&lastOB=rank&qty=64&searchRadius=50&startAt=64&orderBy=rank&dir=
http://school-ratings.com/schoolRatings.php?zipOrCity=94606&schName=&lastOB=rank&qty=64&searchRadius=50&startAt=128&orderBy=rank&dir=
http://school-ratings.com/schoolRatings.php?zipOrCity=94606&schName=&lastOB=rank&qty=64&searchRadius=50&startAt=192&orderBy=rank&dir=
http://school-ratings.com/schoolRatings.php?zipOrCity=94606&schName=&lastOB=rank&qty=64&searchRadius=50&startAt=256&orderBy=rank&dir=
```

* Export: Import.io Data Set
* Copy the ID

### Configuring the Drupal Content Type

http://drupal-importio.dev/admin/structure/types/add

* Name: School
* Save and Add Fields
    * State Rank - Float
    * API Score - Float
    * Location - Text Area
    * Class Sizes - Text Area
    * Parent Education - Float

Or, if you want to be a hacker:

```
./vendor/bin/drush @drupal-importio.drupal-importio.dev field-create school \
  class_sizes,text_long,text_textarea \
  parent_education,number_float,number \
  state_rank,number_float,number \
  api_score,number_float,number \
  location,text_long,text_textarea
```

### Configuring Feeds

* Structure > Feeds Importers > add Importers
    * California School Ratings
    * Ratings, ranking, test scores for schools
* Fetcher: change
    * import.io Fetcher
* import.io Fetcher: Settings
    * Specify Data Set ID, User ID, and API Key
* Parser: change
    * import.io Parser
* Node processor: Settings
    * Bundle: School
    * Update existing nodes: Update existing nodes
* Mapping
    * Hover over the data set headings to get the machine name.
    * number_1 - state_rank
    * number_2 - api_score
    * value_1 - title - click gear, [X] Unique, Update
    * content - location
    * values - class_sizes
    * alttext_value_numbers - parent_education
* Tamper
    * location
        * Add plugin: Find replace
        * Text to find: " map " (without the spaces)
        * Text to replace: ", " (without the spaces)

### Importing

* http://drupal-importio.dev/import
* Click "California School Ratings"
* Click Import
* Go to Content

### Configuring the View

* http://drupal-importio.dev/admin/structure/views/add
* View name: Schools
    * Show: Content of type School
    * [X] Create a page
    * [X] Create a menu link, Main menu
    * Display format: Table
* Add fields, filter criteria, save.

## Local presentation

```bash
npm install
grunt serve
```

Visit http://localhost:8000 to view.
