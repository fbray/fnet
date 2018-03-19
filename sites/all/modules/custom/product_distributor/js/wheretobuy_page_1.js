jQuery.noConflict();
(function ($) {
    $(function() {
        var infowindow = null;
        var preIwindow = null;
        var buyingMethodCount = 0;
        var submitCallback = null;
        var submitCallbackData = null;
        var buyingMethods = null;
        var storefrontsInCountry = null;
        var preservePostalCode = false;

        //Set global/default AJAX settings
        $.ajaxSetup({
            // Disable caching of AJAX responses
            cache: false
        });

        //---------------- Find A Reseller ----------------//
        //Google Map init.
        loadScript();

        // We're going to do quite a bit of manipulation, so we declare various elements as variables for caching. FTW!
        var editProducts = $('#edit-products');
        var editCountries = $('#edit-countries');
        var editProductsWrapper = $('#edit-products-wrapper');
        var editCitiesWrapper = $('#edit-cities-wrapper');

        //Bind JS events
        //Countries drop-down
        editCountries.change(function () {
            //reset default selection and visibility of form elements
            editProducts.val(0);
            $('#edit-postal-code').val('');
            $('#edit-regions').val(0);
            $('#edit-regions-wrapper').hide();

            editCitiesWrapper.html('').hide();

            $('#edit-postal-code-wrapper').hide();
            $('#edit-gsa-schedule-wrapper').hide();
            $('#pd-l1-form #edit-submit').hide();
            wtb_search_results(true);
            storefrontsInCountry = null;

            //If a valid country is selected
            if ($(this).val() != 0) {
                editProductsWrapper.fadeIn();
            }
            else {
                //If valid country is not selected then hide all visible form elements
                editProductsWrapper.hide();
                $('#edit-regions-wrapper-wrapper').hide();
            }
        });

        // Products dropdown: Check visibility of Sales channel radios and submit button on change
        editProducts.change(function () {
            if ($(this).val() != 0) {
                alert($(this).val());
                // Clear the existing elements.
                $('#edit-postal-code').val('');
                $('#edit-regions').val(0);
                $('#edit-regions-wrapper').hide();
                $('#edit-cities-wrapper').empty().hide();
                $('#edit-postal-code-wrapper').hide();
                $('#edit-gsa-schedule-wrapper').hide();
                buyingMethodCount = 0;
                wtb_search_results(true);
                storefrontsInCountry = null;

                // AJAX call to fetch delivery types available for the selected country.
                var url = Drupal.settings.basePath + 'wheretobuy_ajax/get_delivery_types';
                var urlData = 'country=' + $('#edit-countries').val();
                urlData += '&product=' + $('#edit-products').val();
console.log(urlData);
                $('#ajax-loader-wrapper').show();
                $.ajax({
                    type: "GET",
                    url: url,
                    data: urlData,
                    success: function (jdata) {
                        // Set buyingMethods
                        if (jdata.deliveryTypes)
                            buyingMethods = jdata.deliveryTypes;
                        else
                            buyingMethods = false;

                        // Deal with response data returned
                        if (jdata.submitCallback) {
                            // No region filters required. Show Go button.
                            console.log(jdata.submitCallbackData);
                            $('#pd-l1-form #edit-submit').fadeIn();
                            submitCallback = jdata.submitCallback;
                            submitCallbackData = jdata.submitCallbackData;
                        }
                        else {
                            // Display region & postal_code filters
                            $('#pd-l1-form #edit-submit').hide();
                            submitCallback = false;
                            submitCallbackData = false;

                            // Display the Price spider WTB button if country is US
                            if ($('#edit-countries').val() == 'US' && jdata.wtbcheck == 1) {
                                if(jdata.psmodel == null){
                                    jdata.psmodel= '';
                                }
                                alert('Cue the WTB button!');
                                $('#ps-widget-btn').html('<div class="ps-widget" ps-sku="'+jdata.psmodel+'"></div>');
                                PriceSpider.rebind();
                                $('.ps-widget').fadeIn();
                            }
                            else {
                                $('.ps-widget').remove();
                                $('#edit-regions-wrapper').html(jdata.data).fadeIn();
                                $('#edit-postal-code-wrapper').fadeOut();
                                $('#edit-gsa-schedule-wrapper').fadeOut();
                            }

                            //Bind Regions drop-down
                            $("#edit-regions").change(function () {
                                if (($(this).val() == 0) && ($('#edit-postal-code').val() == ''))
                                    $('#pd-l1-form #edit-submit').hide();

                                $('#edit-cities-wrapper').empty().hide();

                                //Clear postalcode value
                                if (($('#edit-postal-code').val() != '') && !preservePostalCode) {
                                    $('#edit-postal-code').val('');
                                }

                                wtb_search_results(false);
                                storefrontsInCountry = null;

                                //Check if valid region is selected
                                if ($('#edit-regions').val() != 0) {
                                    //AJAX to get cities specified in the selected country-region pair.
                                    var url = Drupal.settings.basePath + 'wheretobuy_ajax/get_cities';

                                    var urlData = 'country=' + $('#edit-countries').val();
                                    urlData += '&product=' + $('#edit-products').val();
                                    urlData += '&buying=' + encodeURIComponent(buyingMethods);
                                    urlData += '&region=' + $('#edit-regions').val();
                                    if (($('#edit-countries').val() == 'US') && ($('input#edit-gsa-schedule').is(':checked'))) {
                                        urlData += '&channel=1';
                                    }
                                    alert(url);
                                    alert(urlData);
                                    $('#ajax-loader-wrapper').show();
                                    $.ajax({
                                        type: "GET",
                                        url: url,
                                        data: urlData,
                                        success: function (jdata) {
                                            if (jdata.storefrontsInCountry > 0)
                                                storefrontsInCountry = jdata.storefrontsInCountry;

                                            if (jdata.submitCallback) { //No city filter required. Show Go button
                                                $('#pd-l1-form #edit-submit').fadeIn();
                                                submitCallback = jdata.submitCallback;
                                                submitCallbackData = jdata.submitCallbackData;
                                            }
                                            else { //Display city filter
                                                $('#pd-l1-form #edit-submit').fadeOut();
                                                //Show msg for no cities available
                                                $('#edit-cities-wrapper').html(jdata.data);
                                                //Show Cities form element
                                                $('#edit-cities-wrapper').fadeIn();
                                            }

                                            $('#ajax-loader-wrapper').hide();

                                            //Cities
                                            $('#edit-cities').change(function () {

                                                wtb_search_results(false);

                                                //Clear postalcode value
                                                if ($('#edit-postal-code').val() != '') {
                                                    $('#edit-postal-code').val('');
                                                }
                                                if ($(this).val() != 0) {
                                                    submitCallback = 'get_distributors';
                                                    $('#pd-l1-form #edit-submit').fadeIn();
                                                }
                                                else {
                                                    submitCallback = false;
                                                    $('#pd-l1-form #edit-submit').fadeOut();
                                                }
                                            });
                                        },
                                        error: function (jqXHR, textStatus, errorThrown) {
                                            // alert('error: ' + textStatus);
                                            // alert('The error is happening in the wheretobuy.js file.');
                                            console.log(errorThrown);
                                            $('#ajax-loader-wrapper').hide();
                                        },
                                        dataType: 'json'
                                    });
                                }
                                else {
                                    $('#edit-cities-wrapper').empty().hide();
                                }
                            });
                        }

                        //Product image
                        if (jdata.image) {
                            $('#pimg-wrapper').html(jdata.image).show();
                            $('#map-wrapper').hide();
                            $('#gmap-wrapper').hide();
                        }
                        else {
                            //wtb_search_results(true);
                            $('#pimg-wrapper').empty().hide();
                            $('#gmap-wrapper').hide();
                            $('#map-wrapper').show();
                        }
                        //Hide AJAX loader
                        $('#ajax-loader-wrapper').hide();
                    },
                    error: function (jqXHR, textStatus, errorThrown) {
                        // alert('error: ' + textStatus);
                        console.log(errorThrown);
                        $('#ajax-loader-wrapper').hide();
                        checkboxGSA();
                    },
                    dataType: 'json'
                });
            } else {
                $('#pd-l1-form #edit-submit').fadeOut();
                $('#edit-buying-methods').val(0);
                $('#edit-postal-code').val('');
                $('#edit-regions').val(0);
                $('#edit-buying-methods-wrapper').hide();
                $('#edit-cities-wrapper').html('');
                $('#edit-cities-wrapper').hide();
                $('#edit-regions-wrapper').hide();
                $('#edit-postal-code-wrapper').hide();
                $('#edit-gsa-schedule-wrapper').hide();
                wtb_search_results(true);
            }
        });


        //Postal code textbox: disable form submit on press of <enter> button
        $('#edit-postal-code').keydown(function (e) {

            var keyCode = e.keyCode ? e.keyCode : e.which ? e.which : e.charCode;
            //escape <enter> and <tab> keys
            if (keyCode == 13 || keyCode == 9) {
                e.cancelBubble = true;
                e.returnValue = false;

                if (e.stopPropagation) {
                    e.stopPropagation();
                    e.preventDefault();
                }
                return false;
            }
        });
        $('#edit-postal-code').keyup(function (e) {

            var keyCode = e.keyCode ? e.keyCode : e.which ? e.which : e.charCode;
            //escape <enter> and <tab> keys
            if (keyCode == 13 || keyCode == 9) {
                e.cancelBubble = true;
                e.returnValue = false;

                if (e.stopPropagation) {
                    e.stopPropagation();
                    e.preventDefault();
                }
                return false;
            }

            wtb_search_results(false);
            if ($(this).val() != '') {
                $('#pd-l1-form #edit-submit').fadeIn();
                submitCallback = 'get_distributors';
                submitCallbackData = false;
            }
            else {
                $('#pd-l1-form #edit-submit').fadeOut();
                submitCallback = false;
                submitCallbackData = false;
            }

            //Clear region and city drop-downs
            if ($('#edit-regions').val() != 0) {
                $('#edit-regions').val(0);
                $('#edit-cities').val(0);
                $('#edit-cities-wrapper').html('');
                $('#edit-cities-wrapper').hide();
            }
        });

        //Sales channel radios: disable form submit on press of <enter> button
        /*
        $('#edit-gsa-schedule').each(function () {
            $(this).keypress(function (e) {
                var keyCode = e.keyCode ? e.keyCode : e.which ? e.which : e.charCode;
                //escape <enter> key
                if (keyCode == 13) {
                    e.cancelBubble = true;
                    e.returnValue = false;

                    if (e.stopPropagation) {
                        e.stopPropagation();
                        e.preventDefault();
                    }
                    return false;
                }
            });
            var eventLabel = 'change'; // Set default event label.
            if (typeof $.browser != 'undefined') {
                if (typeof $.browser.msie != 'undefined') {
                    var eventLabel = 'propertychange'; // In some cases the label should instead be 'propertychange'.
                }
            }
            $(this).bind(eventLabel, function () {
                if ($('#edit-regions').is(':visible')) {
                    preservePostalCode = true;
                    $('#edit-regions').change();
                    preservePostalCode = false;
                }
                wtb_search_results(false);
            });
        }); */

        //Submit button: escape form submit and process form via AJAX
        $('#pd-l1-form #edit-submit').click(function () {
            if (submitCallback) {
                //Hide Airmagnet How-to-buy link
                $('#airmagnet-wtb-link').hide();
                var url = Drupal.settings.basePath + 'wheretobuy_ajax/' + submitCallback;
                var urlData = '';
                if (submitCallbackData)
                    urlData += submitCallbackData + '&';
                urlData += 'country=' + $('#edit-countries').val();
                urlData += '&product=' + $('#edit-products').val();
                urlData += '&buying=' + encodeURIComponent(buyingMethods);
                if (($('#edit-countries').val() == 'US') && ($('input#edit-gsa-schedule').is(':checked'))) {
                    urlData += '&channel=1';
                }

                //Special processing if "Storefront" buying method is selected
                if (buyingMethods && (buyingMethods.search("S") != -1)) {
                    //Give priority to postal-code text box else, use region-city information
                    if ($('#edit-postal-code').val() != '') {
                        urlData += '&postal=' + $('#edit-postal-code').val();
                    }
                    else {
                        if ($('#edit-regions').is(':visible')) {
                            urlData += '&region=' + $('#edit-regions').val();
                            if (storefrontsInCountry)
                                urlData += '&storefronts=' + storefrontsInCountry;
                            if ($('#edit-cities').is(':visible')) {
                                urlData += '&city=' + encodeURIComponent($('#edit-cities').val());
                            }
                        }
                    }
                }

                $('#ajax-loader-wrapper').show();
                //AJAX to search distributors with selected form settings
                console.log(url);
                console.log(urlData);
                $.ajax({
                    type: "GET",
                    url: url,
                    data: urlData,
                    success: function (jdata) {
                        $('#ajax-loader-wrapper').hide();
                        if (jdata.data != '') {
                            if (jdata.errorData) {
                                wtbSetErrorMessage(jdata.errorData);
                            }
                            else {
                                $('#dsearch-results').html(jdata.data);

                                if (jdata.storefrontData) {
                                    // process_google_map(jdata);
                                    alert('Process Google Map');
                                } else {
                                    //If buying method is not Storefront
                                    $('#gmap-wrapper').hide();
                                    if ($('#pimg-wrapper').html() == '') {
                                        $('#pimg-wrapper').hide();
                                        $('#map-wrapper').show();
                                    }
                                    else {
                                        $('#map-wrapper').hide();
                                        $('#pimg-wrapper').show();
                                    }
                                }
                            }
                            $('#dsearch-results').show();
                        }
                        else {
                            var msg = 'This product is not available through the buying method you chose. Please try again or contact Fluke Networks directly for more information.';
                            $('#dsearch-results').html(msg);
                        }
                    },
                    error: function (jqXHR, textStatus, errorThrown) {
                        alert('error: ' + textStatus);
                        $('#ajax-loader-wrapper').hide();
                        console.log(errorThrown);
                    },
                    dataType: 'json'
                });
                return false;
            }
            else
                alert('Error: callback missing');
        });
        $('#edit-countries').change();
        var product = decodeURIComponent(getURLParameter('product'));
        var tab = getURLParameter('tab');
        if (product != null && tab == 3) {
            $('#edit-products').val(product).change();
        }
        if (product != null && tab == 2) {
            $('#edit-C-Product').val(product).change();
        }
    });

    // Show/Hide Sales channel radios
    function checkboxGSA() {
        //Show only if country is US
        if(($('#edit-products').val() != 0) && ($('#edit-countries').val() == 'US')) {
            $('#edit-gsa-schedule-wrapper').fadeIn();
        }
        else {
            $('#edit-gsa-schedule-wrapper').hide();
        }
    }

    function wtb_search_results(isCountry) {
        $('#dsearch-results').empty();

        $('#gmap-wrapper').hide();
        if(isCountry == true) {
            $('#map-wrapper').show();
            $('#pimg-wrapper').hide();
        }
        else {
            if($('#pimg-wrapper').html() == '') {
                $('#map-wrapper').show();
                $('#pimg-wrapper').hide();
            }
            else  {
                $('#map-wrapper').hide();
                $('#pimg-wrapper').show();
            }
        }
    }

//Show WTB error message and contact form
    function wtbSetErrorMessage(message) {
        $('#dsearch-results').html(message);
        if($('#dsearch-results #wtb-contact-form-wrapper').html())
            $('#dsearch-results #wtb-contact-form-wrapper').html($('#wtb-contact-us-form-wrapper').html());
    }

    //Google Map JS
    function loadScript() {
        var script = document.createElement("script");
        script.type = "text/javascript";
        script.src = "https://maps.googleapis.com/maps/api/js?v=3&key=AIzaSyCWAo5Qs4sWdv5uNhVbCCY4HofIrC8NNbk"; // callback=initialize (Deprecated?)
        document.body.appendChild(script);
    }

    function externalGmapClick(i) {
        google.maps.event.trigger(marker[i], 'click');
        map.setZoom(16);
    }

    function process_google_map(jdata) {
        var map;
        var marker = [];
        //If buying method is Storefront//Google Map
        var lats = jdata.lats.split('|');
        var lons = jdata.lons.split('|');
        var gtitle = jdata.gtitle.split('|');
        var gaddress = jdata.gaddress.split('|');
        var clat = 0;
        var clon = 0;
        var tmpLatlng = [];

        //find the first valid lat-lon and use it to center map
        var counter = lats.length;
        for(i = 0; i<counter; i++) {
            if(lats[i] != 'NULL' && lons[i] != 'NULL') {
                clat = lats[i];
                clon = lons[i];
                break;
            }
        }
        //Check if ther is atleast one coordinate to display
        if(i == counter)
            return false;
        var myLatlng = new google.maps.LatLng(clat, clon);

        var myOptions = {
            mapTypeId: google.maps.MapTypeId.ROADMAP
        }

        //Show GMap Div
        $('#map-wrapper').hide();
        $('#pimg-wrapper').hide()
        $('#gmap-wrapper').show();

        map = new google.maps.Map(document.getElementById("gmap-wrapper"), myOptions);
        /*
         //Use Lat lang calculated by backend
         var minLatLng = new google.maps.LatLng(jdata.minLat, jdata.minLon);
         var maxLatLng = new google.maps.LatLng(jdata.maxLat, jdata.maxLon);
         var myBounds = new google.maps.LatLngBounds(minLatLng, maxLatLng);
         */
        //Use bounds calculated by google maps
        var myBounds = new google.maps.LatLngBounds();
        for(i = 0; i<counter; i++) {
            if(lats[i] != 'NULL' && lons[i] != 'NULL') {
                tmpLatlng[i] = new google.maps.LatLng(lats[i], lons[i]);
                //Use bounds calculated by extending bounds
                if(i < 10) {
                    myBounds.extend(tmpLatlng[i]);
                }
                marker[i] = new google.maps.Marker({
                    position: tmpLatlng[i],
                    title: gtitle[i],
                    html: '<b>'+gtitle[i]+'</b><br/>'+gaddress[i]
                });
                // To add the marker to the map, call setMap();
                marker[i].setMap(map);
                var mrkr = marker[i];
                google.maps.event.addListener(mrkr, 'click', function() {
                    infowindow = new google.maps.InfoWindow();
                    infowindow.setContent(this.html);
                    infowindow.open(map,this);
                    if(preIwindow) {
                        preIwindow.close();
                    }
                    preIwindow = infowindow;
                });
            }
        }
        //Add GMap listner to set zoom level to 16 if the zoom in higher than 16 after executing FitBounds()
        //This is listner removed after firing once.
        google.maps.event.addListenerOnce(map,'bounds_changed', function() {
            if(map.getZoom()) {
                if(map.getZoom() > 16)
                    map.setZoom(16);
            }
        });
        //Set viewport to calculated bounds
        map.fitBounds(myBounds);
        return true;
    }

//---------------- Email Us ----------------//
    function AirMagnetHowToBuy(element) {
        if($(element).is(':checked')) {
            window.open("http://www.flukenetworks.com/content/wlan-how-buy-form");
        }
    }
})(jQuery);



