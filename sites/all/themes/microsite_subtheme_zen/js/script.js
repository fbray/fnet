/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // Place your code here.

  }
};


})(jQuery, Drupal, this, this.document);

function searchArray(findValue, targetArray) {
    for (var i = 0; i < targetArray.length; i++) {
        if (findValue.indexOf(targetArray[i]) > -1) {
            return i;
        }
    }
    return -1;
}

// A handy setCookie function.
function setCookie(name, value, expires, path, domain, secure) {

    var today = new Date();
    today.setTime(today.getTime());

    if (expires) {
        expires = expires * 1000 * 60 * 60 * 24;
    }
    var expires_date = new Date(today.getTime() + (expires));

    document.cookie = name + "=" + encodeURI(value) +
        ( ( expires ) ? ";expires=" + expires_date.toGMTString() : "" ) +
        ( ( path ) ? ";path=" + path : "" ) +
        ( ( domain ) ? ";domain=" + domain : "" ) +
        ( ( secure ) ? ";secure" : "" );
}

// A handy getCookie function.
function getCookie(c_name) {
    var i, x, y, ARRcookies = document.cookie.split(";");
    for (i = 0; i < ARRcookies.length; i++) {
        x = ARRcookies[i].substr(0, ARRcookies[i].indexOf("="));
        y = ARRcookies[i].substr(ARRcookies[i].indexOf("=") + 1);
        x = x.replace(/^\s+|\s+$/g, "");
        if (x == c_name) {
            return decodeURI(y);
        }
    }
}

// Make sure this theme does not get redirected to m.flukenetworks.com
setCookie("fullweb", 1, 0, "/");

var autoScrolling = false;

$(document).ready(function(){

    // Make sure all page anchor links scroll smoothly.
    $(function() {
        $('a[href*=#]:not([href=#])').click(function() {
            if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
                var target = $(this.hash);
                target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
                if (target.length) {
                    autoScrolling = true; // Set to true so the manual scroll pageview event does not fire.
                    $('html,body').animate(
                        { scrollTop: target.offset().top - 45 },
                        750,

                        // Wait a fraction of a second to give the final auto-scroll event to finish,
                        //  then set the autoScrolling boolean to false so the manual scroll pageview
                        // event can once again fire if triggered.
                        function(){
                            setTimeout(function(){
                                autoScrolling = false;
                            }, 100);
                        }
                    );
                    return false;
                }
            }
        });
    });

});
