$(document).ready(function(){

    // **************************************************************************************************************
    // Microsite Tracking: Link-Solutions
    // **************************************************************************************************************

    // Bind a pageview to all the section nav menu links.
    $("#block-menu-menu-msite-linksolutions-section ul.menu li a").click(function(){

        // Register a pageview with Google Analytics.
        ga("send", "pageview", $(this).attr("href"));

    });

    // Bind a pageview to all the section nav menu links. (mobile/responsive menu).
    $("body.front #block-menu-menu-msite-linksolutions-mobile ul.menu li a").click(function(){

        // Register a pageview with Google Analytics.
        ga("send", "pageview", $(this).attr("href"));

    });

    // Bind a click event to high-interest links on the site that may or may not also be registering as page views.
    $("a.microsite-tracking.link-solutions-event").click(function(){

        // Register a click event with Google Analytics.
        ga("send", "event", "Microsite: Link-Solutions", "click", $(this).attr("title"));

    });

    // **************************************************************************************************************
    // Microsite Tracking: TruView Live
    // **************************************************************************************************************

    // Bind a pageview to all the section nav menu links.
    $("#block-menu-menu-msite-truviewlive-sections ul.menu li a").click(function(){

        // Register a pageview with Google Analytics.
        ga("send", "pageview", $(this).attr("href"));

    });

    // Bind a click event to high-interest links on the site that may or may not also be registering as page views.
    $("a.microsite-tracking.truview-live-event").click(function(){

        // Register a click event with Google Analytics.
        ga("send", "event", "Microsite: TruView Live", "click", $(this).attr("title"));

    });

});