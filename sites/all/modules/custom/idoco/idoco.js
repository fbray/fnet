$(document).ready(function () {
  "use strict";
  var section = _str2attr(Drupal.settings.idoco.section);
  var page = idoco_str2attr(2);
  // Open the menu that corresponds to the current page automatically
  $('#' + section).addClass('active');
  $('#' + page).addClass('active');
  $('#' + section).next().show();
  $('li > li').hide();

  // Click handler that does the expanding of section menus
  $('#accordion > div > h4').click(function(){
    if ($(this).attr('class') !== 'top-nav active') {
      $('#accordion > div > ul').slideUp(1000);
      $(this).next().slideToggle(1000);
      $('#accordion > div > h4').removeClass('active');
      $(this).addClass('active');
    }
    else {
      $(this).next().slideToggle(1000);
    }
  });

  // Click handler for child ul items
  $('#accordion > div > h4 li').hover(function(){
      $(this).slideDown();
  });
});

// Determine what page we're on so we can set the proper section of the
// navigation menu as .active
function idoco_str2attr(match) {
    "use strict";
  // 1 = section
  // 2 = file
  var regex = /([^\/]*)\/([^\/]*)$/;
  var url = window.location.pathname;
  var className = url.match(regex)[match];

  // decode entities
  className = decodeURIComponent(className);

  className = className.toLowerCase();
  regex = /([^a-z0-9])+/g;
  className = className.replace(regex, '-');
  className = 'idoco-' + className;

  return className;
}

function _str2attr(str) {
    "use strict";
    // decode entities
    var className = decodeURIComponent(str);

    className = className.toLowerCase();
    var regex = /([^a-z0-9])+/g;
    className = className.replace(regex, '-');
    className = 'idoco-' + className;

    return className;
}