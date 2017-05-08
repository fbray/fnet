/**
 * Created by jcaratoz on 9/4/14.
 */
(function ($) {
    $(document).ready(function () {

        // Bind click event for each of the "Buy Online" buttons on the product pages.
        $("#buy-online-links-list a.buy-online-link").click(function () {

            var linkTitle = $(this).attr("title"); // Fetch the link label to feed to the event data.
            var productName = $("#At_A_Glance_Wrapper h1.headline").attr("title"); // Fetch the product name to feed to the event data.

            // Register a click event with Google Analytics.
            ga("send", "event", "Buy Online Links", linkTitle, productName);

        });

        // Bind click event for each of the "Buy Online" buttons on the product pages.
        $("#At_A_Glance_Wrapper .at-a-glance-buttons td").click(function () {

            var linkTitle = $(this).attr("title"); // Fetch the link label to feed to the event data.
            var productName = $("#At_A_Glance_Wrapper h1.headline").attr("title"); // Fetch the product name to feed to the event data.

            // Register a click event with Google Analytics.
            ga("send", "event", "Call to Action Buttons", linkTitle, productName);

        });

        // Bind submit event for the "Find a Reseller" form submissions on the "Where to Buy" page.
        $('#pd-l1-form #edit-submit-go').click(function () {

            var countrySelected = $('#pd-l1-form #edit-countries option:selected').html(); // Fetch the selected value in the country field.
            var productSelected = $('#pd-l1-form #edit-products option:selected').html(); // Fetch the selected value in the product field.

            //alert(countrySelected + ", " + productSelected);

            // Register an event with Google Analytics.
            ga("send", "event", "Where to Buy", productSelected, countrySelected);

        });

    });
})(jQuery);
