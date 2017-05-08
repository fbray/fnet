// Place all jQuery Mobile global settings here.
$(document).bind('mobileinit',function(){

    // Preventing jQuery Mobile from auto-initializing Marketo form elements.
    // Add element selectors to stop mobile jQuery from restyling elements.
    $.mobile.page.prototype.options.keepNative = "form.lpeRegForm label, form.lpeRegForm input, form.lpeRegForm textarea, form.lpeRegForm select, #support-content-wrapper input[type=radio], #gold-support-page-section-menu, #selectRegionBox #language, #selectRegionBox #regionCountry, form#pd-l1-form *";

    // Disable ajax navigation. When ajax navigation is enabled, various custom javascript has trouble
    // running as the $(document).ready() state does not fire as expected.
    $.mobile.ajaxEnabled = false;
});