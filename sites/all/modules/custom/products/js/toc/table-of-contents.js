(function($){
    // Establish sticky page navigator.
    $("#stickynav").sticky({ topSpacing: 0 });

    var menuHeight = $("#stickynav-sticky-wrapper").height(); // Get page nav menu height in order to adjust scrolling offset.

    // Make sure all page anchor links scroll smoothly.
    $(function() {
        $('.toc-container a[href*=#]:not([href=#])').click(function() {
            if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
                var target = $(this.hash);
                target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
                if (target.length) {
                    $('html,body').animate({
                        scrollTop: target.offset().top - (menuHeight + 10)
                    }, 750);
                    return false;
                } else if (this.hash == "#topanchor") {
                    $('html,body').animate({
                        scrollTop: 0
                    }, 750);
                    return false;
                }
            }
        });
    });

    // Handle scrolling location offset if page loads with hash already set in URL.
    $(function() {
        if(getQueryVariable("td")) {
            var hashValue = getQueryVariable("td");
            hashValue = hashValue.replace(/_/gi, " ");
            hashValue = hashValue.toLowerCase();
            var target = $('[name=' + hashValue +']');
            if (target.length) {
                $('html,body').animate({
                    scrollTop: target.offset().top - (menuHeight + 10)
                }, 0);
                return false;
            }

        }else if(window.location.hash){
            var target = $('[name=' + window.location.hash.slice(1) +']');
            if (target.length) {
                $('html,body').animate({
                    scrollTop: target.offset().top - (menuHeight + 10)
                }, 0);
                return false;
            }

        }
    });

    function getQueryVariable(variable) {
        var query = window.location.search.substring(1);
        var vars = query.split("&");
        for (var i=0;i<vars.length;i++) {
            var pair = vars[i].split("=");
            if(pair[0] == variable){return pair[1];}
        }
        return(false);
    }

    toc({
        toc_DocAnchors: $(".toc-anchor"), // A jQuery object containing the DOM elements for all product page section anchors.
        toc_TriggerPoint: 100 // The vertical scrolling offset at which to trigger the "active" state of the corresponding menu item.
    });


    // We need to build a slider range.
    function toc(args){

        // Store passed arguments as local variables.
        var toc_DocAnchors = args.toc_DocAnchors; // A jQuery object containing the DOM elements for all product page section anchors.
        var toc_TriggerPoint = args.toc_TriggerPoint; // The vertical scrolling offset at which to trigger the "active" state of the corresponding menu item.

        // Initialize an array to hold "Anchor Objects" for quick access to
        // the TOC anchors and the corresponding product page section anchors.
        var toc_AnchorObjects = [];

        // Loop through the array of product page section anchors and
        // dynamically build TOC anchors in the sticky horizontal page nav.
        // Then store both corresponding objects into a single index in the
        // toc_AnchorObjects array.
        for(var i=0; i<toc_DocAnchors.length; i++){

            var anchorHref = "#" + toc_DocAnchors[i].attributes["name"].value;
            var anchorElement = $('a[href=' + anchorHref + ']');

            toc_AnchorObjects.push({
                toc_NavAnchor: anchorElement,
                toc_DocAnchor: toc_DocAnchors[i]
            });

        }

        // Fire the processScrollEvent() function once to set the
        // horizontal nav elements up in the starting position.
        processScrollEvent(toc_AnchorObjects);

        // This function, bound to the scroll event, will manipulate the elements in the
        // horizontal page nav according to the scroll progress through the page sections.
        function processScrollEvent(elems){

           var yRange; // Used for calculating the vertical range across each page section by which to calculate scroll progress.
            var yPos; // Used to calculate the scroll position in the yRange within each page section.

            // On each scroll event, loop through the elements to calculate
            // scroll position in relation to the page sections and to then
            // position the horizontal page nav tracker accordingly.
            for(var i=0; i<(elems.length); i++){

                // Calculate top position of page anchor and bottom position
                // of following section to arrive at a y-range of pixels across the section.
                var topPos = $(elems[i].toc_DocAnchor).offset().top;
                var bottomPos = $(elems[i].toc_DocAnchor).next(".section-container").offset().top + $(elems[i].toc_DocAnchor).next(".section-container").height();
                yRange = bottomPos - topPos; // Get the pixel height of the current page section.

                // Determine the scrolled position of section.
                var scrollPos = elems[i].toc_DocAnchor.getBoundingClientRect().top;

                // Check to see if the scroll position falls within the indexed elements y-range (adjusted by "toc_TriggerPoint" setting).
                if(scrollPos <= toc_TriggerPoint && yRange + scrollPos > toc_TriggerPoint){

                    // Set the corresponding horizontal page nav element to the active state.
                    $(elems[i].toc_NavAnchor).addClass("active");

                }else{
                    $(elems[i].toc_NavAnchor).removeClass("active"); // If indexed element is not current, then remove the "active" state.
                }
            }
        }

        var timeout = null;
        $(window).scroll(function(){ // Bind processScrollEvent() to scroll event.
            processScrollEvent(toc_AnchorObjects);

            // For buggy scroll event handling, fire processScrollEvent() again a split-second after last scroll event.
            clearTimeout(timeout);
            timeout = setTimeout(function() {
                processScrollEvent(toc_AnchorObjects);
            }, 200);

        });
    }
}(jQuery));
