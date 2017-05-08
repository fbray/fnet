/**
 * Created by jcaratoz on 9/29/14.
 */

// The JavaScript code within the following "immediately-invoked function expression"
// can be used to process cookie information.
(function(){

    // Form the domain string to be used when creating the "ls" cookie.
    var domainArray = document.domain ? document.domain.split(".") : []; // Split domain string into an array.
    var domainString = "." + domainArray.slice(-2).join("."); // Concatenate the last two items in the array to form something like "linksprinter.com" essentially chopping off the "www".
    var documentReferrer = document.referrer ? document.referrer : "";

    // Set up some variables for passing as cookie parameters.
    var cookieString = ""; // Set the cookie value.
    var path = ";path=/";
    var age = ";max-age=" + (60 * 60 * 24 * 7); // Set the duration of the cookie in seconds.
    var domain = ";domain=" + domainString; // Set the domain of the cookie.

    // Set the "ls" cookie based on a matching URL parameter if available.
    var lsValue = getQueryVariable("ls") ? getQueryVariable("ls") : "";
    if(lsValue != ""){
        cookieString = "ls=" + encodeURIComponent(lsValue); // Set the cookie value.
        document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

    }

    // Function returning any URL parameter value associated
    // with a passed parameter name if available.
    function getQueryVariable(variable){
        var query = window.location.search.substring(1);
        var vars = query.split("&");
        for (var i=0;i<vars.length;i++) {
            var pair = vars[i].split("=");
            if(pair[0] == variable){return pair[1];}
        }
        return(false);
    }

    // Function returning any cookie value associated
    // with a passed cookie name if available.
    function getCookieVariable(variable){
        return decodeURIComponent(document.cookie.replace(new RegExp("(?:(?:^|.*;)\\s*" + encodeURIComponent(variable).replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=\\s*([^;]*).*$)|^.*$"), "$1")) || false;
    }

    // Function returning any URL parameter value associated
    // with a passed parameter name if available.
    function getReferrerQueryVariable(variable){
        var documentReferrer = document.referrer;
        var query = documentReferrer.split("?")[1];
        var vars;
        if(query){
            vars = query.split("&");
            for (var i=0;i<vars.length;i++) {
                var pair = vars[i].split("=");
                if(pair[0] == variable){return pair[1];}
            }
        }
        return(false);
    }

})();