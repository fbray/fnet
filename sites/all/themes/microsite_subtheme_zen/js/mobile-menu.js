
$(document).ready(function(){

    $(function() {
        $("#header .block-menu.region-count-4 h2.block-title").click(function() {
            if ($("#header .block-menu.region-count-4").hasClass("expanded")) {
                $("#header .block-menu.region-count-4").removeClass("expanded");
            } else {
                $("#header .block-menu.region-count-4").addClass("expanded")
            }
        });

        $("#header .block-menu.region-count-4 ul.menu li a").click(function() {
            $("#header .block-menu.region-count-4").removeClass("expanded");
        });
    });

});