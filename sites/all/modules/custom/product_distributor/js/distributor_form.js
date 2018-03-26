jQuery.noConflict();
(function ($) {
    $(function () {
        var isRegionRequired = false;
        var isBuyOnlineURLRequired = false;
        var oldCountryVal = null;
        var oldProvinceVal = null;
        oldCountryVal = $('#edit-locations-0-country').val();
        oldProvinceVal = $('#edit-locations-0-province').val();

        //Show GSA checkbox only if country is US
        $('#edit-locations-0-country').change(function () {
            //Normalize initial init by country change event firing.
            if (oldCountryVal == $(this).val()) {
                $('#edit-locations-0-province').val(oldProvinceVal);
            } else {
                oldCountryVal = $('#edit-locations-0-country').val();
                oldProvinceVal = $('#edit-locations-0-province').val();
            }
            //GSA Schedule checkbox hide/show
            if ($(this).val() == 'us') {
                $('#edit-field-gsa-schedule-value-wrapper').slideDown();
            }
            else {
                $('#edit-field-gsa-schedule-value-wrapper').slideUp();
            }

            //Region field compulsory if country not flagged to skip region
            var url = Drupal.settings.basePath + 'distributor_location_form_ajax/is_country_flagged';
            var urlData = 'country=' + $('#edit-locations-0-country').val();
            if ($('#edit-field-delivery-type-value-S').is(':checked')) {
                $.ajax({
                    type: "GET",
                    url: url,
                    data: urlData,
                    success: function (jdata) {
                        if (jdata.status) {
                            var html = 'State/Province:';
                            $('#edit-locations-0-province-wrapper label').html(html);
                            $('#edit-locations-0-province').attr('style', '');
                            isRegionRequired = false;
                        }
                        else {
                            var html = 'State/Province:<span class="form-required" title="This field is required.">*</span>';
                            $('#edit-locations-0-province-wrapper label').html(html);
                            isRegionRequired = true;
                        }
                    },
                    error: function (jqXHR, textStatus, errorThrown) {
                        alert('error: ' + textStatus);
                    },
                    dataType: 'json'
                });
            }
            else {
                //Region field not compulsory
                var html = 'State/Province:';
                $('#edit-locations-0-province-wrapper label').html(html);
                $('#edit-locations-0-province').attr('style', '');
                isRegionRequired = false;
            }
        });

        $('#edit-field-delivery-type-value-S').change(function () {
            oldProvinceVal = $('#edit-locations-0-province').val();
            $('#edit-locations-0-country').change();
        });

        $('#edit-field-delivery-type-value-O').change(function () {
            if ($(this).is(':checked')) {
                var html = 'Buy Online URL:<span class="form-required" title="This field is required.">*</span>';
                $('#edit-field-buy-online-url-0-value-wrapper label').html(html);
                isBuyOnlineURLRequired = true;
            }
            else {
                var html = 'Buy Online URL:';
                $('#edit-field-buy-online-url-0-value-wrapper label').html(html);
                isBuyOnlineURLRequired = false;
            }
        });

        $('#node-form').submit(function () {
            if (isRegionRequired) {
                if ($('#edit-locations-0-country').val() != '' && $('#edit-locations-0-country').val() != 'xx') {
                    if ($('#edit-locations-0-province').val() == '') {
                        $('#edit-locations-0-province').focus();
                        $('#edit-locations-0-province').attr('style', 'border:2px solid red');
                        alert('Please enter a province name');
                        return false;
                    }
                    else if (isBuyOnlineURLRequired) {
                        if ($('#edit-field-buy-online-url-0-value').val() == '') {
                            $('#edit-field-buy-online-url-0-value').focus();
                            $('#edit-field-buy-online-url-0-value').attr('style', 'border:2px solid red');
                            alert('Please enter a value for Buy Online URL');
                            return false;
                        } else {
                            return true;
                        }
                    }
                    else {
                        return true;
                    }
                }
                else if (isBuyOnlineURLRequired) {
                    if ($('#edit-field-buy-online-url-0-value').val() == '') {
                        $('#edit-field-buy-online-url-0-value').focus();
                        $('#edit-field-buy-online-url-0-value').attr('style', 'border:2px solid red');
                        alert('Please enter a value for Buy Online URL');
                        return false;
                    } else {
                        return true;
                    }
                }
            } else if (isBuyOnlineURLRequired) {
                if ($('#edit-field-buy-online-url-0-value').val() == '') {
                    $('#edit-field-buy-online-url-0-value').focus();
                    $('#edit-field-buy-online-url-0-value').attr('style', 'border:2px solid red');
                    alert('Please enter a value for Buy Online URL');
                    return false;
                } else {
                    return true;
                }
            }
            else {
                return true;
            }
        });
        $('#edit-locations-0-country').change();
        $('#edit-field-delivery-type-value-O').change();
    });
})(jQuery);