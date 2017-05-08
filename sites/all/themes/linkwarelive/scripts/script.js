/**
 * Created by mositis on 8/28/2015.
 */
jQuery.noConflict();
(function ($) {

  $(function() {
    $("#faq-inner").accordion();

    var  mn = $("#block-responsive-dropdown-menus-menu-microsite-linkware-live-top");
    mns = "main-nav-scrolled";
    hdr = $('#branding').height();
    btn = $('.menu-sign-in');

    $(window).scroll(function() {
      if( $(this).scrollTop() > hdr ) {
        mn.addClass(mns);
        btn.show();
      } else {
        mn.removeClass(mns);
        btn.hide()
      }
    });
  });

})(jQuery);