/**
 * Created by jcaratoz on 9/3/14.
 */

// The JavaScript code within the following "immediately-invoked function expression"
// will set the "ls" cookie accordingly; either setting the value based on a matching
// URL parameter if available, or by looking at the http referrer and setting it to
// a string indicating from which search engine the user came.
(function () {

    // Form the domain string to be used when creating the "ls" cookie.
    var domainArray = document.domain ? document.domain.split(".") : []; // Split domain string into an array.
    var domainString = "." + domainArray.slice(-2).join("."); // Concatenate the last two items in the array to form something like "flukenetworks.com" essentially chopping off the "www".
    var documentReferrer = document.referrer ? document.referrer : "";

    // Set up some variables for passing as cookie parameters.
    var cookieString = ""; // Set the cookie value.
    var path = ";path=/";
    var age = ";max-age=" + (60 * 60 * 24 * 90); // Set the duration of the cookie in seconds.
    var domain = ";domain=" + domainString; // Set the domain of the cookie.

    // Set "ls" cookie to the value of the "ls" parameter in the URL if it exists.
    var lsValue = getQueryVariable("ls") ? getQueryVariable("ls") : "";
    if (lsValue != "") {
        cookieString = "ls=" + encodeURIComponent(lsValue); // Set the cookie value.
        document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        // If the user is coming from a search engine organically,
        // then set the "ls" cookie accordingly.
    } else if (documentReferrer != "") {

        // Check to see if the referrer domain belongs to Google, Bing, Yahoo or Ask.
        // Since Google is using ccTLDs but Yahoo, Ask and Bing do not, there is a difference in how they are tested.
        if (documentReferrer.search("google") != -1) {
            cookieString = "ls=gseo"; // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        } else if (documentReferrer.search("bing.com") != -1) {
            cookieString = "ls=bseo"; // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        }
        else if (documentReferrer.search("ask.com") != -1) {
            cookieString = "ls=aseo"; // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        }
        else if (documentReferrer.search("yahoo.com") != -1) {
            cookieString = "ls=yseo"; // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        }

    }

    // Always set the "lsd" cookie with any ppc value provided in the URL parameter if available.
    var lsdValue = getQueryVariable("lsd") ? getQueryVariable("lsd") : "";
    if (lsdValue != "") {
        cookieString = "lsd=" + encodeURIComponent(lsdValue); // Set the cookie value.
        document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        // Else if no "lsd" parameter is passed in the URL, then set the "lsd" cookie value to
        // the search query string found in the referrer URL parameters.
        // If no search query string is found, then store the entire referrer URL.
    } else if (documentReferrer != "") {

        // Now determine if the referrer is coming from a search engine.
        // Then look for a search query string in the URL (Parameter "q" for Google, Bing, Ask; Parameter "p" for Yahoo).
        // First we'll look for Google.
        if (documentReferrer.search("google") != -1 && getReferrerQueryVariable("q")) {
            cookieString = "lsd=" + encodeURIComponent(getReferrerQueryVariable("q")); // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

            // Now let's look for Bing.
        } else if (documentReferrer.search("bing.com") != -1 && getReferrerQueryVariable("q")) {
            cookieString = "lsd=" + encodeURIComponent(getReferrerQueryVariable("q")); // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

            // Now let's look for Yahoo.
        } else if (documentReferrer.search("yahoo.com") != -1 && getReferrerQueryVariable("p")) {
            cookieString = "lsd=" + encodeURIComponent(getReferrerQueryVariable("p")); // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

            // Now let's look for Ask.
        } else if (documentReferrer.search("ask.com") != -1 && getReferrerQueryVariable("q")) {
            cookieString = "lsd=" + encodeURIComponent(getReferrerQueryVariable("q")); // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

            // If no query string is found but referrer URL is still coming from search engine, then set cookie to entire referrer URL.
        } else if (
            documentReferrer.search("google") != -1
            || documentReferrer.search("bing.com") != -1
            || documentReferrer.search("yahoo.com") != -1
            || documentReferrer.search("ask.com") != -1
        ) {
            cookieString = "lsd=" + encodeURIComponent(documentReferrer); // Set the cookie value.
            document.cookie = cookieString + path + domain + age; // Form the string input in the expected format and set the cookie.

        }
    }

    // Function returning any URL parameter value associated
    // with a passed parameter name if available.
    function getQueryVariable(variable) {
        var query = window.location.search.substring(1);
        var vars = query.split("&");
        for (var i = 0; i < vars.length; i++) {
            var pair = vars[i].split("=");
            if (pair[0] == variable) {
                return pair[1];
            }
        }
        return (false);
    }

    // Function returning any cookie value associated
    // with a passed cookie name if available.
    function getCookieVariable(variable) {
        return decodeURIComponent(document.cookie.replace(new RegExp("(?:(?:^|.*;)\\s*" + encodeURIComponent(variable).replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=\\s*([^;]*).*$)|^.*$"), "$1")) || false;
    }

    // Function returning any URL parameter value associated
    // with a passed parameter name if available.
    function getReferrerQueryVariable(variable) {
        var documentReferrer = document.referrer;
        var query = documentReferrer.split("?")[1];
        var vars;
        if (query) {
            vars = query.split("&");
            for (var i = 0; i < vars.length; i++) {
                var pair = vars[i].split("=");
                if (pair[0] == variable) {
                    return pair[1];
                }
            }
        }
        return (false);
    }

})();