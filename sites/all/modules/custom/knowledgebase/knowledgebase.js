(function($) {
    // Initialize the nested "accordion" menus.
    $(".accordion").accordion({
        active: false, // Collapse all menus by default.
        collapsible: true,
        heightStyle: "content" // Let the height of each menu expand automatically.
    });

    // If necessary, expand the appropriate top-level accordion menu based on the current selection.
    var elem = $("#h4-active-panel"); // Fetch "active" menu heading element to be used in the "index" function.
    positionH4 = elem.closest(".accordion").find("h4").index(elem); // Determine the index position of the "active" menu element within the containing element.
    elem.closest(".accordion").accordion("option", "active", positionH4); // Activate (or open) the menu within which is contained the active link selection.

    $("#taxonomy-menu").fadeIn(200); // Since the accordion functionality of the menu is initialized/styled on the client side, display it only once this process completes.

    $('#kb-article-list .views-field a[href]').each(function () {
        var href = $(this).attr('href'); // Get the current href value of view links.
        $(this).attr('href', href);
    });
})(jQuery);
