(function($) {
    $(function() {
        // Start: Search KB topics
        var kbtext = $('#search-kb-text');
        var kbform = $('#search-kb-form');
        kbtext.focus(function () {
            if ($(this).val() === 'Enter text here.') {
                $(this).css('color', 'black');
                $(this).val('');
            }
        });
        kbtext.blur(function () {
            if (jQuery.trim($(this).val()) === '') {
                $(this).css('color', 'gray');
                $(this).val('Enter text here.');
            }
        });
        $('#search-kb-btn').click(function () {
            kbform.submit();
        });
        kbform.submit(function () {
            if (kbtext.val() === 'Enter text here.') {
                kbtext.val('');
            }
            var selected_function = $('input[name=search_kb_radios]:checked', '#search-kb-form');
            var relArr = selected_function.attr('rel').split('<::>');
            kbform.attr('method', relArr[0]);
            kbform.attr('action', relArr[1]);
            kbform.attr('name', relArr[2]);
            return true;
        });

        // Start: Product Documentations and Downloads
        var training_form = $('#product-assets-training-form');
        var download_form = $('#product-assets-download-form');
        var manuals_form = $('#product-assets-manuals-form');

        training_form.find('select#edit-product').change(function () {
            if ($(this).val() !== 0) {
                training_form.submit();
            }
        });

        $('#software-by-product').change(function () {
            $('#product-manuals-form-wrapper').hide();
            $('#software-downloads-form-wrapper').show();
        });
        $('#manuals-by-product').change(function () {
            $('#software-downloads-form-wrapper').hide();
            $('#product-manuals-form-wrapper').show();
        });

        download_form.find('select#edit-product-1').change(function () {
            if ($(this).val() !== 0) {
                download_form.submit();
            }
        });

        manuals_form.find('select#edit-product-2').change(function () {
            if ($(this).val() !== 0) {
                manuals_form.submit();
            }
        });
    });
})(jQuery);

