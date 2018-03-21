jQuery.noConflict();
(function ($) {
    $(function () {
        var isNADChecked = false;

        $('#edit-field-not-available-value').change(function () {

            var chtml;
            var phtml;
            if ($(this).is(':checked')) {
                chtml = 'Country: <span title="This field is required." class="form-required"> * </span>';
                phtml = 'Phone Number: <span title="This field is required." class="form-required"> * </span>';
                isNADChecked = true;
            }
            else {
                chtml = 'Country: ';
                phtml = 'Phone Number: ';
                isNADChecked = false;
                $('#edit-locations-0-country').val('');
                $('#edit-locations-0-phone').val('');
            }
            $('#edit-locations-0-country-wrapper label').html(chtml);
            $('#edit-locations-0-phone-wrapper label').html(phtml);
        });

        $('form#node-form').submit(function () {
            if (isNADChecked) {
                if ($('#edit-locations-0-country').val() != '' && $('#edit-locations-0-country').val() != 'xx') {
                    $('#edit-locations-0-country').attr('style', '');
                    if ($.trim($('#edit-locations-0-phone').val()) != '') {
                        $('#edit-locations-0-phone').attr('style', '');
                        return true;
                    } else {
                        $('#edit-locations-0-phone').focus();
                        $('#edit-locations-0-phone').attr('style', 'border:2px solid red');
                        alert('Phone number field is required if "Not available for distribution" is selected');
                        return false;
                    }
                } else {
                    $('#edit-locations-0-country').focus();
                    $('#edit-locations-0-country').attr('style', 'border:2px solid red');
                    alert('Country is required if "Not available for distribution" is selected');
                    return false;
                }
            } else {
                $('#edit-locations-0-country').attr('style', '');
                $('#edit-locations-0-phone').attr('style', '');
                return true;
            }
        });
        $('#edit-field-not-available-value').change();
    });
})(jQuery);