jQuery.noConflict();
(function ($) {
    $(function() {
        var isErrorOnTab2 = false;
        //When page loads...
        $(".tab_content").hide(); //Hide all content

        //Check if error messages are present
        if ($('.messages.error').html()) {
            isErrorOnTab2 = true;
        } else {
            isErrorOnTab2 = false;
        }

        //Switch tab based on 'tab' parameter in URL query string
        var tab = getURLParameter('tab');
        if (tab == 3) {
            tab = 1;
        }
        else if (tab == 1) {
            tab = 2;
        }
        else if (tab == 2) {
            window.location.replace("/contactus");
        }
        if (tab == null || isErrorOnTab2) { //If no 'tab' parameter found OR errors messages present, show 2nd tab if errors present else show first tab
            activateDefaultTab(isErrorOnTab2);
        }
        else if (tab >= 1 && tab <= 3) { //If 'tab' parameter found in valid range, activate corresponding tab
            $("ul.tabs li:nth-child(" + tab + ")").addClass("active").show();
            $(".tab_content:nth-child(" + tab + ")").show();
        }
        else { //If 'tab' parameter has invalid value, show 2nd tab if errors present else show first tab
            activateDefaultTab(isErrorOnTab2);
        }

        //On Click Event
        $("ul.tabs li").click(function () {

            $("ul.tabs li").removeClass("active"); //Remove any "active" class
            $(this).addClass("active"); //Add "active" class to selected tab
            if ($('.messages.success').html()) {
                $('.messages.success').html('');
                $('.messages.success').slideUp();
            }
            if (isErrorOnTab2 == true) {
                if ($("ul.tabs li.active").hasClass("second"))
                    $(".messages.error").slideDown();
                else
                    $(".messages.error").slideUp();
            }
            $(".tab_content").hide(); //Hide all tab content

            var activeTab = $(this).find("a").attr("href"); //Find the href attribute value to identify the active tab + content
            $(activeTab).fadeIn('fast'); //Fade in the active ID content
            return false;
        });
    });

//Default tab activation functionality
    function activateDefaultTab(isErrorOnTab2) {
        if(isErrorOnTab2 == true) {
            $("ul.tabs li:nth-child(2)").addClass("active").show(); //Activate second tab
            $(".tab_content:nth-child(2)").show(); //Show second tab content
        } else {
            $("ul.tabs li:first").addClass("active").show(); //Activate first tab
            $(".tab_content:first").show(); //Show first tab content
        }
    }
})(jQuery);

//Read URL GET parameter by name
function getURLParameter(name) {
    return decodeURI(
        (RegExp(name + '=' + '(.+?)(&|$)').exec(location.search)||[,null])[1]
    );
}
