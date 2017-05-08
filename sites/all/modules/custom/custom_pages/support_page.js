if (Drupal.jsEnabled) {
    $(document).ready(function() {
        //Start: Search KB topics
        $('#search-kb-text').focus(function() {
            if($(this).val() == 'Enter text here.') {
                $(this).css('color','black');
                $(this).val('');
            }
        });
        $('#search-kb-text').blur(function() {
            if(jQuery.trim($(this).val()) == '') {
                $(this).css('color','gray');
                $(this).val('Enter text here.');
            }
        });
        $('#search-kb-btn').click(function() {
            $('#search-kb-form').submit();
        });
        $('#search-kb-form').submit(function() {
            if($('#search-kb-text').val() == 'Enter text here.') {
                $('#search-kb-text').val('');
            }
            var selected_function = $('input[name=search_kb_radios]:checked', '#search-kb-form');
            var relArr = selected_function.attr('rel').split('<::>');
            $('#search-kb-form').attr('method', relArr[0]);
            $('#search-kb-form').attr('action', relArr[1]);
            $('#search-kb-text').attr('name', relArr[2]);
            return true;
        });

        $('#product-assets-training-form select#edit-product').change(function() {
            if($(this).val() != 0) {
                $('#product-assets-training-form').submit();
            }
        });
        //End: Search KB topics

        //Start: Product Documentations and Downloads
        $('#software-by-product').click(function() {
            $('#product-manuals-form-wrapper').hide();
            $('#software-downloads-form-wrapper').show();
        });
        $('#manuals-by-product').click(function() {
            $('#software-downloads-form-wrapper').hide();
            $('#product-manuals-form-wrapper').show();
        });

        $('#product-assets-download-form select#edit-product-1').change(function() {
            if($(this).val() != 0) {
                $('#product-assets-download-form').submit();
            }
        });

        $('#product-assets-manuals-form select#edit-product-2').change(function() {
            if($(this).val() != 0) {
                $('#product-assets-manuals-form').submit();
            }
        });
        //End: Product Documentations and Downloads
    }); 
}