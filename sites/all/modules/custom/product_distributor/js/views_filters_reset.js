(function ($) {
    // START jQuery

    Drupal.productDistributor = Drupal.productDistributor || {};

    Drupal.behaviors.productDistributor = function(context) {
        $.each(Drupal.settings.productDistributor, function(form_id, url) {
            $('form#'+form_id+' input#edit-reset', context).click(function() {
                if (url) {
                    window.location = url+'?op=reset';
                }
                else {
                    $('form#'+form_id, context).clearForm();
                    $('form#'+form_id+' input#edit-reset-hidden', context).val('reset');
                    $('form#'+form_id, context).submit();
                }
            });
        });
    }

    Drupal.productDistributor.ajaxViewResponse = function(target, response) {
        $('form#'+response.exposed_form_id).replaceWith(response.exposed_form);
        Drupal.attachBehaviors($('form#'+response.exposed_form_id).parent());
    }
    
    // END jQuery
})(jQuery);
