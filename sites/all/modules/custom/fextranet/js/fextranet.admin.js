(function($) {
    /**
     * Change multi-value dropdown to single-value dropdown and back (visually).
     */
    /*
     * TODO: Get the naming of the behaviors correct. Find a code example or something.
     */
    Drupal.behaviors.fextranet = {
        attach: function(context, settings) {
            $.each(Drupal.settings.fextranet.multiple_selects, function(name, settings) {
                // convert the name underscores to dashes.
                name = name.split('_').join('-');
                $('select#edit-' + name)
                    .once('collapsible-filter-multiple-rewrite')
                    .each(function() {

                        var selectionCount = $('option:selected', $(this)).length;
                        if (selectionCount <= 1) {
                            // Set size of select to 1 if there is not more than 1 selected.
                            $(this).attr('size', 1);
                            // Remove attribute "multiple".
                            $(this).removeAttr('multiple');
                            // Set default option.
                            if (selectionCount === 0 || $(this).val() === 'All') {
                                $(this).val('All');
                            }

                            // Add link to expand the dropdown.
                            $expand = $('<a>')
                                .addClass('select-expander')
                                .attr('href', '#')
                                .attr('title', Drupal.t('Expand selection'))
                                .html('[+]')
                                .click(function() {
                                    // Get corresponding select element.
                                    $select = $(this)
                                        .parent('.form-type-select')
                                        .find('.collapsible-filter-multiple-rewrite-processed');
                                    // Expand element.
                                    $select.attr('size', settings.size)
                                        .attr('multiple', 'multiple');
                                    $(this).remove();
                                })
                                .appendTo($(this).parent());
                        }
                    });
            });
        }
    };

})(jQuery);