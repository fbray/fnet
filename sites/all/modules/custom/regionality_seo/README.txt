Currently the module only supports replacement of the Description and Keywords meta tags although it would not be
difficult to other tags supported be the nodewords module.

When this module replaces either the Description or Keywords meta tags it also adds the "translate" attribute with a value
of "no".  It is anticipated that Translations.com could use this attribute as an instruction to not translate the
overridden meta tags.  Because t.com does not yet support the "translate" attribute, the module also send the t.com
X-OneLinkNoTx header for overridden titles and meta tags.

This module also uses the API of the page_title module to alter page title based on regionality.  In order for this to
work the page_title configuration need to be changed to enable the page title field on all of the 'language' sub types.

