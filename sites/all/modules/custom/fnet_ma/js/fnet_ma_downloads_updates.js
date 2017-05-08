(function ($) {
    $(document).ready(function () {
        var l = window.location;
        // The below variable works on all the three tiers correctly: Dev, Test and PROD.
        var base_url = l.protocol + "//" + l.host + "/" + l.pathname.split('/')[0];

        // This is for my local set of Fluke Networks on my computer, so its commented -
        //var base_url = l.protocol + "//" + l.host + "/" + l.pathname.split('/')[1] + '/';

        // When user clicks the "Go" button on the Fluke Networks "Download and updates" form.
        $('#flukenetworks-submit-button').click(function () {
            var product_catgory_selected = $('#edit-download-and-updates-product-list').val()
            var url_to_fetch_result = base_url + "myaccount/get_downloads_ajax/" + product_catgory_selected;
            $('#loading-bar-image').show();
            $.ajax({
                type: "GET",
                url: url_to_fetch_result,
                success: function (jdata) {
                    $('#loading-bar-image').hide();
                    if (jdata.status == 'no_product_selected') {
                        $('#gold_support_section_wrapper').html(jdata.data);
                    }
                    else if (jdata.status == 'download_and_updates_found') {
                        $('#gold_support_section_wrapper').html(jdata.data);
                    }
                    else if (jdata.status == 'no_download_and_updates_found') {
                        $('#gold_support_section_wrapper').html(jdata.data);
                    }
                },
                dataType: 'json'
            });
        });
    });
})(jQuery);
