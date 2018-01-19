# Modules

## clientside_validation

This is the core module, all it does is add data- attributes to the HTML
form elements. If an HTML5 attribute exists it is used as is.

## clientside_validation_jquery

This modules adds the [jQuery Validation Plugin](http://jqueryvalidation.org/).

If you use this module as-is and you do not download the library, it will be
automatically included by linking to the CDN version.

If you would prefer to download the library, you can either install it manually
or using Composer.

To install the library manually:

1. Download the jQuery Validation library from http://jqueryvalidation.org/ .
   jQuery Validation 1.17.0 or higher is recommended.

2. If it does not already exist, create a folder named `libraries` at the web
   root of your Drupal site. Then, create a folder named `jqueryvalidate`
   inside of the `libraries` folder (i.e.: `/libraries/jqueryvalidate`).

3. Extract the ZIP you downloaded in step 1 inside of the
   `/libraries/jqueryvalidate` folder (i.e.: so that the `jquery.validate.js`
   file is at `/libraries/jqueryvalidate/dist/jquery.validate.js`).

To install the library using Composer:

1. Add the proper repository to your `composer.json` file to be able to require
   the JS library:

    ```
        {
          "type": "package",
          "package": {
            "name": "jqueryvalidate",
            "version": "1.17.0",
            "type": "drupal-library",
            "dist": {
              "url": "https://github.com/jquery-validation/jquery-validation/releases/download/1.17.0/jquery-validation-1.17.0.zip",
              "type": "zip"
            }
          }
        }
    ```

    It is always good to download and use the latest version here but new 
    versions may not work as expected since those are not tested properly.

2. Run `composer require jqueryvalidate:~1.0`

3. Install module as usual.

# Extend

If you need support for other contrib modules, you can add a CvValidator plugin
to that module and it will be picked up by the base module.

If you require custom javascript, you can implement `hook_clientside_validation_validator_info_alter()`

# Contribute

See the [Drupal 8 port issue](https://www.drupal.org/node/2610804)

# Test it

On [simplytest.me](https://simplytest.me/project/clientside_validation/8.x-1.x)
