jQuery.noConflict();
(function ($) {
    $(function() {
        $('form#user-login').submit(function (event) {
            var username = $('#edit-name').val();
            var includedSubs = [
                'www.flukenetworks.com',
                'd7.flukenetworks.com',
                'local.flukenetworks.com',
                'flukenetworksdev.danahertm.com',
                'flukenetworkstst.danahertm.com'];
            $('.messages').remove();
            if (($.inArray(document.domain.toLowerCase(), includedSubs) === -1) && (username.search('@') === -1)) {
                $('#tabs-wrapper').after('<div class="messages error">Sorry, unrecognized username or password. <a href="/user/password">Have you forgotten your password?</a></div>');
                username.focus();
                event.preventDefault();
            }
        });
    });
})(jQuery);
