var $ = jQuery.noConflict();
function move_backward(process_div) {
    var show_div_with_ID = parseInt(process_div);
    var hide_div_with_ID = parseInt(show_div_with_ID) + 1;
    $('#div_number_' + hide_div_with_ID).hide(5);
    $('#div_number_' + show_div_with_ID).show(5);
}

function move_forward(process_div) {
    var show_div_with_ID = process_div;
    var hide_div_with_ID = show_div_with_ID - 1;
    $('#div_number_' + hide_div_with_ID).hide(5);
    $('#div_number_' + show_div_with_ID).show(5);
}

function toggle_sections(sections_div_id) {
    var div_id = sections_div_id;
    // alert(div_id);
    if (div_id == 'gold-contract-summary-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }

    if (div_id == 'downloads-and-updates-summary-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }

    if (div_id == 'support-incident-summary-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }

    if (div_id == 'registered-products-summary-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }

    if (div_id == 'ondemand-training-summary-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }

    if (div_id == 'registered-product-listing-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#helping-instruction-registered-product-listing-page").fadeOut("slow");
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#helping-instruction-registered-product-listing-page").fadeOut("slow");
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }

    if (div_id == 'all-support-incidents-listing-section') {
        if ($("#" + div_id + "-expanding-master-key-div").hasClass("my-account-header-minus-background")) {
            $("#helping-instruction-support-incidents-listing-page").fadeOut("slow");
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-minus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-plus-background")
        } else {
            $("#helping-instruction-support-incidents-listing-page").fadeOut("slow");
            $("#" + div_id + "-expanding-master-key-div").removeClass("my-account-header-plus-background")
            $("#" + div_id + "-expanding-master-key-div").addClass("my-account-header-minus-background")
        }
        $('#' + div_id).slideToggle("slow");
    }
}

function show_more_serial_number() {
    $("#product_registration_form_additional").slideDown("slow");
    $("#display_add_more_link").hide("slow");
    $("#edit-extra-section-open-status").val('1');
}

(function ($) {
    $(function() {
        $('#edit-number-days-passed').change(function () {
            $('form#flukenetworks-myaccont-support-incident-search-form').submit();
            /*
             var url = location.href;
             url = url.split("?");
             var days_selected = $('#edit-number-days-passed').val();
             window.location = url[0]+'?days='+days_selected;
             */
        });
        $('#register-product-clear-button').click(function () {
            // Clear all the Product Serial Number Text field.
            $("#edit-product-serial-number-1").val('');
            $("#edit-product-serial-number-2").val('');
            $("#edit-product-serial-number-3").val('');
            $("#edit-product-serial-number-4").val('');
            $("#edit-product-serial-number-5").val('');
            $("#edit-product-serial-number-6").val('');
            $("#edit-product-serial-number-7").val('');
            $("#edit-product-serial-number-8").val('');
            $("#edit-product-serial-number-9").val('');
            $("#edit-product-serial-number-10").val('');

            // Clear all the Product Purchase Date Text field.
            $("#edit-product-purchase-date-1").val('');
            $("#edit-product-purchase-date-2").val('');
            $("#edit-product-purchase-date-3").val('');
            $("#edit-product-purchase-date-4").val('');
            $("#edit-product-purchase-date-5").val('');
            $("#edit-product-purchase-date-6").val('');
            $("#edit-product-purchase-date-7").val('');
            $("#edit-product-purchase-date-8").val('');
            $("#edit-product-purchase-date-9").val('');
            $("#edit-product-purchase-date-10").val('');

        });
    });
})(jQuery);
