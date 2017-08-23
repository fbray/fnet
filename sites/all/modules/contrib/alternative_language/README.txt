CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Troubleshooting
 * Maintainers

INTRODUCTION
------------

The Alternative Language module was developed as an answer to a business
problem - the site has a dozen languages and we only need to translate two of
them. For nodes where translations exist, we didn't want to maintain ten copies
of the source translation so a fallback option was needed. Other modules that
said they could do it were tested and did not do what was needed.

 * For a full description of the module, visit the project page:
   https://www.drupal.org/project/alternative_language


 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/alternative_language

REQUIREMENTS
------------

This module requires the following core modules:
 * Block
 * Locale
 * Translation

This module requires the following contributed modules:
 * Internationalization (https://www.drupal.org/project/i18n)
 * Pathauto (https://www.drupal.org/project/pathauto)

INSTALLATION
------------

 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.

CONFIGURATION
------------

To apply and alternative language to a currently configured language, go to
the languages configuration page: admin/config/regional/language and edit the
desired language.

At the bottom of the edit screen there is an Alternative Language fieldset with
a toggle to enable/disable the alternative language for this language. If
checked, a select box will display allowing you to select the alternative
language.

TROUBLESHOOTING
---------------

 * If you have any issues, submit a bug report:
   https://www.drupal.org/project/alternative_language

MAINTAINERS
-----------

Current maintainers:
 * Scott Joudry (slydevil) https://www.drupal.org/u/slydevil
