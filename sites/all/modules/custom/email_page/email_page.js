$(document).ready(function () {
    $("#submit").click(function () {
        var content = $("#main").html();
        $("#emailbody").val(content);

    });
});