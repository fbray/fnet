$(document).ready(function(){

    $(function() {

        // Get section nav element container.
        //var menu = document.getElementById('block-menu-menu-homepage-sections');
        // var origOffsetY = menu.offsetTop;

        // We have to hard code the height since the #block-menu-menu-homepage-sections div
        // is display:none during mobile/responsive view and cannot provide offsetTop value
        // causing the placeMenu() function to fail and not apply "sticky" class when needed.
        var origOffsetY = 87; // This should be set to the height value of the #header div.
        var btn = $('.menu-free-trial');
        // If page has scrolled beyond header, make section nav sticky at top of browser.
        function placeMenu() {
            if ($(window).scrollTop() >= origOffsetY) {
                $('#section-menu .block-menu').addClass('sticky');
                btn.show();
            } else {
                $('#section-menu .block-menu').removeClass('sticky');
                btn.hide();
            }
        }

        // This function checks to see if user has scrolled to a particular section,
        // then it highlights the active section nav link in the menu.
        function highlightMenuItem() {

            var offsetMargin = 50; // Give some margin to trigger active section before it reaches top of browser.

            $('#section-menu .block-menu ul.menu li a').each(function(){
                var anchorString = $(this).attr('href');
                anchorString = anchorString.split('#');
                anchorString = anchorString[anchorString.length - 1];

                var anchorElem = document.getElementById(anchorString);

                // Check to see if section is active.
                if (anchorElem) {
                    if (anchorElem.getBoundingClientRect()["top"] <= offsetMargin) {

                        $('#section-menu .block-menu ul.menu li a').each(function(){
                            $(this).removeClass("current");
                        });

                        $(this).addClass("current");

                        // Register a scroll event with Google Analytics.
                        // console.log("Scrolled: " + $(this).attr('href') + " = " + $(this).data('scrolled'));
                        if($(this).data('scrolled') != 'true'){

                            $(this).data('scrolled', 'true');

                            ga("send", "event", "Microsite", "scroll", $(this).attr('href')); // Register scroll event.
                            if(!autoScrolling){
                                viewedOverview = true;
                                ga("send", "pageview", $(this).attr('href')); // Register pageview if not auto-scrolled.
                            }
                        }

                    } else {
                        $(this).removeClass("current");
                    }
                }
            });

        }

        // Trigger these functions when user scrolls.
        window.onscroll = function(){
            placeMenu(); // Determine if section nav menu is sticky or not.
            highlightMenuItem(); // Determine active section in order to highlight corresponding menu item.
        }

        highlightMenuItem(); // Run this function on page load in order to highlight active menu item.

    });

});