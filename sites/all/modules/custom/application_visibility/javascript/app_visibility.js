/**
 * $id: $
 */

var step1Empty = new Array();
var step2Empty = new Array();
var step3Empty = new Array();
var entries = 0;
var form = $("#app-visibility");
form.children("div").steps({
    headerTag: "h3",
    bodyTag: "section",
    transitionEffect: "slideLeft",
    onStepChanging: function (event, currentIndex, newIndex) {
        if (currentIndex == 0 && newIndex == 1) {
            var value = '';
            for (i = 1; i < 11; i++) {
                value = $("#application-" + i).val();
                if (value == '') {
                    step1Empty[i] = true;
                    step2Empty[i] = true;
                    $("#prob-row-" + i).hide();
                    step3Empty[i] = true;
                    $("#crit-row-" + i).hide();

                } else {
                    entries++
                    $("#app-prob-" + i).html(value);
                    $("#app-crit-" + i).html(value);
                }
            }
            if (entries < 4) {
                $('#message').html('You must enter at least four applications');
                return false;
            } else {
                $('#message').html('');
            }
        }
        if (currentIndex == 1 && newIndex == 2) {
            var allChecked = true;

            for (i = 1; i <= entries; i++) {
                var value = $("input[name=prob-" + i + "]:checked").val();
                if (value == undefined && !step2Empty[i]) {
                    allChecked = false;
                }
                if (value == 1) {
                    $("#crit-row-" + i).hide();
                    step3Empty[i] = true;
                } else {
                    $("#crit-row-" + i).show();
                    step3Empty[i] = false;
                }
            }
            if (!allChecked) {
                $("#message2").html("All questions must be answered");
                return false;
            } else {
                $("#message2").html("");
            }
        }
        if (currentIndex == 2 && newIndex == 3) {
            var allCritChecked = true;
            for (i = 1; i <= entries; i++) {
                if ($("input[name=crit-" + i + "]:checked").val() == undefined && !step3Empty[i]) {
                    allCritChecked = false;
                }
            }
            if (!allCritChecked) {
                $("#message3").html("All questions must be answered");
                return false;
            } else {
                $("#message3").html("");
            }
            var score = 0;
            var prob = 0;
            var crit = 0;
            for (i = 1; i <= entries; i++) {
                prob = parseInt($("input[name=prob-" + i + "]:checked").val(), 10);
                if (!step3Empty[i]) {
                    crit = parseInt($("input[name=crit-" + i + "]:checked").val(), 10);
                } else {
                    crit = 0;
                }
                score += prob;
                if (prob == 2 || prob == 3) {
                    score += crit;
                }
            }
            var level1 = 1.6 * entries;
            var level2 = 2.6 * entries;
            if (score < level1) {
                $("#results1").show();
            } else if (score < level2) {
                $("#results2").show();
            } else {
                $("#results3").show();
            }
            $('#results').html('Score = ' + score);
        }
        return true;
    },
    onFinishing: function (event, currentIndex) {
        return true;
    },
    onFinished: function (event, currentIndex) {
        window.location.assign("/truviewlive");
    }
});
