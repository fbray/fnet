// Enable product features accordion
jQuery(function() {
    jQuery(".ui-accordion").accordion({
        active: false,
        collapsible: true,
        heightStyle: 'content',
        icons: {"header": "ui-icon-plus", "activeHeader": "ui-icon-minus"},
        animate: false,
        activate: function (event, ui) {
            try {
                theOffset = ui.newHeader.offset();
                $('body,html').animate({
                    scrollTop: theOffset.top - 70
                });
            } catch (err) {
            }
        }
    });
    jQuery(".support-link").click(function () {
        jQuery(this).closest("tr").next().find(".support-options").toggle();
    });
    jQuery("a.fnet_fancybox").fancybox({
        'titlePosition': 'inside',
        'transitionIn': 'elastic',
        'transitionOut': 'elastic',
        'overlayColor': '#000',
        'overlayOpacity': 0.8
    });
});