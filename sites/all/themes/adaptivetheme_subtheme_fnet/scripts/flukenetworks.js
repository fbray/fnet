// JavaScript Document
function searchArray(findValue, targetArray) {
    for (var i = 0; i < targetArray.length; i++) {
        if (findValue.indexOf(targetArray[i]) > -1) {
            return i;
        }
    }
    return -1;
}

var timeout = 100;
var closetimer = 0;
var ddmenuitem = 0;
var searchBoxSelect = 0;

function jsddm_open() {
    jsddm_canceltimer();
    jsddm_close();
    ddmenuitem = jQuery(this).find('div').css('visibility', 'visible');
}

function jsddm_close() {
    if ((ddmenuitem) && (searchBoxSelect == 0)) ddmenuitem.css('visibility', 'hidden');
}

function jsddm_timer() {
    closetimer = window.setTimeout(jsddm_close, timeout);
}

function jsddm_canceltimer() {
    if (closetimer) {
        window.clearTimeout(closetimer);
        closetimer = null;
    }
}

function populateCountry() {
    countryMenu = document.region.regionCountry;
    countryOptionCount = 2;
    for (key in countryArr) {
        if (selectedCountry == key) {
            option = new Option(countryArr[key][0], key, true, true);
        } else {
            option = new Option(countryArr[key][0], key);
        }
        if (key == "US") {
            countryMenu.options[1] = option;
        } else if (key == "CA") {
            countryMenu.options[2] = option;
        } else {
            countryMenu.options[countryOptionCount + 1] = option;
            countryOptionCount++
        }
    }
}

function countryLanguage(countrySelected) {
    if (countrySelected) {
        languageMenu = document.region.language;
        while (languageMenu.options.length) languageMenu.options[0] = null;
        for (i = 1; i < countryArr[countrySelected].length; i++) {
            if (selectedLanguage == countryArr[countrySelected][i][0]) {
                option = new Option(countryArr[countrySelected][i][1], countryArr[countrySelected][i][0], true, true);
            } else {
                option = new Option(countryArr[countrySelected][i][1], countryArr[countrySelected][i][0]);
            }
            languageMenu.options[i - 1] = option;
        }
        languageMenu.disabled = false;
    } else {
        while (languageMenu.options.length) languageMenu.options[0] = null;
        option = new Option("-- language --", "");
        languageMenu.options[0] = option;
        languageMenu.disabled = true;
    }
}

function grayOut(vis, options) {

    var options = options || {};
    var zindex = options.zindex || 999;
    var opacity = options.opacity || 75;
    var opaque = (opacity / 100);
    var bgcolor = options.bgcolor || '#000000';
    var dark = document.getElementById('darkenScreenObject');

    if (!dark) {
        var tbody = document.getElementsByTagName("body")[0];
        var tnode = document.createElement('div');
        tnode.style.position = 'absolute';
        tnode.style.top = '0px';
        tnode.style.left = '0px';
        tnode.style.overflow = 'hidden';
        tnode.style.display = 'none';
        tnode.id = 'darkenScreenObject';
        tbody.appendChild(tnode);
        dark = document.getElementById('darkenScreenObject');
    }
    if (vis) {
        if (document.body && ( document.body.scrollWidth || document.body.scrollHeight )) {
            var pageWidth = document.body.scrollWidth + 'px';
            var pageHeight = document.body.scrollHeight + 'px';
        } else if (document.body.offsetWidth) {
            var pageWidth = document.body.offsetWidth + 'px';
            var pageHeight = document.body.offsetHeight + 'px';
        } else {
            var pageWidth = '100%';
            var pageHeight = '100%';
        }

        var curWidth = grayOutGetWidth();
        var curHeight = grayOutGetHeight();

        //alert("current height: "+curHeight+" | actual height: "+pageHeight);

        if (pageWidth != "100%") {
            if (pageWidth < curWidth) pageWidth = curWidth;
            if (pageHeight < curHeight) pageHeight = curHeight;
        }
        //var pageWidth='100%';
        //var pageHeight='100%';

        dark.style.opacity = opaque;
        dark.style.MozOpacity = opaque;
        dark.style.filter = 'alpha(opacity=' + opacity + ')';
        dark.style.zIndex = zindex;
        dark.style.backgroundColor = bgcolor;
        dark.style.width = pageWidth;
        dark.style.height = pageHeight;
        dark.style.display = 'block';
    } else {
        dark.style.display = 'none';
    }
}

function grayOutGetWidth() {
    var x = 0;
    if (self.innerHeight) {
        x = self.innerWidth;
    } else if (document.documentElement && document.documentElement.clientHeight) {
        x = document.documentElement.clientWidth;
    } else if (document.body) {
        x = document.body.clientWidth;
    }
    return x;
}


function grayOutGetHeight() {
    var y = 0;
    if (self.innerHeight) {
        y = self.innerHeight;
    } else if (document.documentElement && document.documentElement.clientHeight) {
        y = document.documentElement.clientHeight;
    } else if (document.body) {
        y = document.body.clientHeight;
    }
    return y;
}

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

function selectRegion() {
    grayOut(true);
    jQuery('#selectRegionBox').slideDown(400);
    populateCountry();
}

/**
 *
 */
function setRegion() {
    var tempDomain = location.host;
    var domainName = tempDomain.split(".");
    var countTemp = domainName.length;
    var finalDomain = domainName[countTemp - 2] + "." + domainName[countTemp - 1];
    // Debugging
    console.log(finalDomain);
    selCountry = document.getElementById("regionCountry");
    regCountry = selCountry.options[selCountry.selectedIndex].value;
    if (regCountry == "") {
        alert("Please select a country");
        return;
    }
    setCookie("regCountry", regCountry, 365, "/", finalDomain);

    selLang = document.getElementById("language");
    regLang = selLang.options[selLang.selectedIndex].value;
    if (regLang == "") {
        alert("Please select a language");
        return;
    }
    setCookie("regLang", regLang, 365, "/", finalDomain);

    $('#selectRegionBox').slideUp(400);
    grayOut(false);

    var sHostname = regLang.split("-");
    var selectedLang = sHostname[0].toLowerCase();

    languageUrl = selectedLang + ".flukenetworks.com";
    if (languageUrl == "en.flukenetworks.com") languageUrl = "www.flukenetworks.com";

    setRegionAndLanguage(selectedLang);

    var includedSubs = ["www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com", "local.flukenetworks.com"];
    var includedSubsReturn = searchArray(document.domain, includedSubs);
    if ((includedSubsReturn > -1) && (languageUrl != document.domain)) {
        document.location.href = document.location.protocol + "//" + languageUrl + document.location.pathname + document.location.search;
    } else {
        location.reload();
    }
}

function setRegionAndLanguage(selectedLang) {
    var finalDomain = getFinalDomain();
    var languageCookie, regionCookie;
    console.log('Selected Language: ' + selectedLang);
    switch (selectedLang) {
        case "en":
            languageCookie = "en";
            regionCookie = "us";
            break;
        case "fr":
            languageCookie = "fr";
            regionCookie = "fr";
            break;
        case "de":
            languageCookie = "de";
            regionCookie = "de";
            break;
        case "es":
            languageCookie = "es";
            regionCookie = "es";
            break;
        case "cn":
            languageCookie = "zh";
            regionCookie = "cn";
            break;
        case "jp":
            languageCookie = "ja";
            regionCookie = "jp";
            break;
        case "ko":
            languageCookie = "ko";
            regionCookie = "kr";
            break;
        case "pt":
            languageCookie = "pt";
            regionCookie = "br";
            break;
        case "ru":
            languageCookie = "ru";
            regionCookie = "ru";
            break;
        default:
            languageCookie = "en";
            regionCookie = "us";
    }

    setCookie("language", languageCookie, 365, "/", finalDomain);
    setCookie("region", regionCookie, 365, "/", finalDomain);
}

var selectedLanguage;
var selectedCountry;

function getFinalDomain() {
    var tempDomain = location.host;
    var domainName = tempDomain.split(".");
    var countTemp = domainName.length;
    var finalDomain = domainName[countTemp - 2] + "." + domainName[countTemp - 1];
    console.log('Final Domain' + finalDomain);
    return finalDomain;
}

function getSubDomain() {
    var domain = location.host.split('.');
    return domain[0].toUpperCase();
}

function autoRegion(ipCountryCode) {
    var finalDomain = getFinalDomain(); // Test case: danahertm.com
    var autoRegLang;
    var sHostname;
    var selectedLang;
    if (ipCountryCode != null) {
        console.log('IP Country Code: ' + ipCountryCode);
        if (ipCountryCode in countryArr) {
            autoRegLang = countryArr[ipCountryCode][1][0];
            setCookie("regCountry", ipCountryCode, 365, "/", finalDomain);
            setCookie("regLang", autoRegLang, 365, "/", finalDomain);
            sHostname = autoRegLang.split("-");
            selectedLang = sHostname[0].toLowerCase();
            setRegionAndLanguage(selectedLang);
        }
        else {
            setCookie("regCountry", "US", 365, "/", finalDomain);
            setCookie("regLang", "EN-US", 365, "/", finalDomain);
        }
    }
}

var XMLHttpRequestObject;
if (window.XMLHttpRequest) {
    // code for IE7+, Firefox, Chrome, Opera, Safari
    XMLHttpRequestObject = new XMLHttpRequest();
} else {
    // code for IE6, IE5
    XMLHttpRequestObject = new ActiveXObject("Microsoft.XMLHTTP");
}

XMLHttpRequestObject.onreadystatechange = function () {
    var regLangResponse;
    var ipCountryCode;
    if (XMLHttpRequestObject.readyState == 4) {
        if (XMLHttpRequestObject.status == 200) {
            regLangResponse = XMLHttpRequestObject.response;
            if (typeof(regLangResponse) === "string") {
                regLangResponse = JSON.parse(regLangResponse);
            }
            ipCountryCode = regLangResponse.ipCountryCode;
            autoRegion(ipCountryCode);

            selectedCountry = getCookie("regCountry");
            selectedLanguage = getCookie("regLang");
            //if we can't get a cookie value don't do anything
            if (typeof selectedLanguage == 'undefined') {
                return;
            }
            var includedSubsReturn;
            var excludedSubs = ["/print/", "/doc_links_pdf/", "/admin", "/node", "/apps/", "/ppc/", "/co/"];
            var excludedSubsReturn = searchArray(window.location.href, excludedSubs);
            countryLanguage(selectedCountry);
            var regLangCookie = selectedLanguage.split("-");
            var languageUrl = regLangCookie[0].toLowerCase() + ".flukenetworks.com";
            if (languageUrl == "en.flukenetworks.com") languageUrl = "www.flukenetworks.com";
            var includedSubs = ["www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com"];
            includedSubsReturn = searchArray(document.domain, includedSubs);
            if ((excludedSubsReturn == -1) && (includedSubsReturn > -1) && (languageUrl != document.domain)) {
                document.location.href = document.location.protocol + "//" + languageUrl + document.location.pathname + document.location.search;
            }
        }
    }
};

selectedLanguage = getCookie("regLang");
if (typeof selectedLanguage == 'undefined') {
    console.log('selectedLanguage is undefined at this point.');
    var subDomain = getSubDomain();
    if (getSubDomain() == 'CN') {
        autoRegion(subDomain);
    }
    else {
        // Does a webservice call using the current user IP address.
        XMLHttpRequestObject.open("GET", "/reglang", true);
        XMLHttpRequestObject.send();
    }
} else {
    var regLangCookie = selectedLanguage.split("-");
    var cookieHost = regLangCookie[0].toLowerCase() + ".flukenetworks.com";
    if (cookieHost == "en.flukenetworks.com") cookieHost = "www.flukenetworks.com";
    var excludedPaths = ["/print/", "/doc_links_pdf/", "/admin", "/node", "/apps/", "/ppc/", "/co/"];
    var productionDomains = ["www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com"];
    if ((searchArray(window.location.href, excludedPaths) == -1) && (searchArray(document.domain, productionDomains) > -1) && (cookieHost != document.domain)) {
        document.location.href = document.location.protocol + "//" + cookieHost + document.location.pathname + document.location.search;
    }
}

(function ($) {
    $(function () {

        selectedCountry = getCookie("regCountry");
        if (typeof selectedCountry == 'undefined') {
            console.log('Selected Country is undefined here.');
            selectedCountry = 'US';
        }
        countryLanguage(selectedCountry);

        /*
        $('#utility_nav > ul > li').bind('mouseover', jsddm_open);
        $('#utility_nav > ul > li').bind('mouseout', jsddm_timer);
        */
        $('#topnav > ul > li').bind('mouseover', jsddm_open);
        $('#topnav > ul > li').bind('mouseout', jsddm_timer);

        $("a.fnet_fancybox").fancybox({
            'titlePosition': 'inside',
            'transitionIn': 'elastic',
            'transitionOut': 'elastic',
            'overlayColor': '#000',
            'overlayOpacity': 0.8
        });
        $("a.fnet_swf").fancybox({
            'padding': 0,
            'autoScale': false,
            'transitionIn': 'none',
            'transitionOut': 'none',
            'overlayColor': '#000',
            'overlayOpacity': 0.8
        });

        // START: EU Cookie Message **************
        // Display the EU cookie message for France, Netherlands.
        var hideEUCookie = getCookie("hideEUCookie") ? getCookie("hideEUCookie") : ""; // Look for the hideEUCookie cookie which, if it exists, should only be set to "true".
        var EUCookieDiv = document.getElementById("eucookie"); // Get the HTML element containing the cookie message for modification.

        if ( // Only show the EU cookie message for France or Netherlands and if the hideEUCookie is not set to "true".
        (selectedCountry == "FR" || selectedCountry == "NL")
        && hideEUCookie != "true") {

            EUCookieDiv.style.display = "block"; // Display the HTML element containing the message.
            EUCookieDiv.innerHTML = "\<p>We are using cookies to give you the best experience on our site. Cookies are files stored in your browser and are used by most websites to help personalise your web experience.</p><p>By continuing to use our website without changing the settings, you are agreeing to our use of cookies.</p><a href='/about/cookie-usage'>More Information</a><a href='javascript:void();' id='eucookieclose'>Close</a>";
        }
        else {
            EUCookieDiv.innerHTML = ""; // Clear the HTML content of the div (probably already empty but can't hurt).
        }

        // If the user clicks the "close" button in the EU cookie message, then set the hideEUCookie to "true".
        var EUCookieCloseButton = document.getElementById("eucookieclose");
        if (EUCookieCloseButton) { // If the button element is found, bind the setCookie function to the onclick event.
            EUCookieCloseButton.onclick = function () {
                var tempDomain = location.host;
                var domainName = tempDomain.split(".");
                var countTemp = domainName.length;
                var finalDomain = domainName[countTemp - 2] + "." + domainName[countTemp - 1];

                setCookie("hideEUCookie", "true", 365, "/", finalDomain);

                EUCookieDiv.style.display = "none";
                EUCookieDiv.innerHTML = "";
            }
        }
        // END: EU Cookie Message **************
    });
})(jQuery);

document.onclick = jsddm_close;

function showProductNav() {
    document.getElementById('topnav_products_sub').style.visibility = 'visible';
    searchBoxSelect = 1;
}

function hideProductNav() {
    searchBoxSelect = 0;
}

function faq_list(vlistaction, vlistsize, vname) {
    if (vlistaction == "open") vdisplayaction = "";
    else vdisplayaction = "none";

    for (i = 1; i <= vlistsize; i++) {
        tlayer = "faq" + i + "a";
        document.getElementById(tlayer).style.display = vdisplayaction;
    }
}

function faq_display(vlayer) {
    vlayer = vlayer + "a";
    if (document.getElementById(vlayer).style.display == 'none') document.getElementById(vlayer).style.display = '';
    else document.getElementById(vlayer).style.display = 'none';
}

function support_display(vlayer) {
    if (document.getElementById(vlayer).style.display == 'none') document.getElementById(vlayer).style.display = '';
    else document.getElementById(vlayer).style.display = 'none';
}

function list_open_close(vlistaction, vlistsize, vname) {
    if (vlistaction == "open") vdisplayaction = "";
    else vdisplayaction = "none";

    for (i = 1; i <= vlistsize; i++) {
        tlayer = vname + i + "a";
        document.getElementById(tlayer).style.display = vdisplayaction;
    }
}

function wa_list(vlistaction, vlistsize) {
    if (vlistaction == "open") vdisplayaction = "";
    else vdisplayaction = "none";

    for (i = 1; i <= vlistsize; i++) {
        tlayer = "adapt" + i + "a";
        document.getElementById(tlayer).style.display = vdisplayaction;
    }
}


function globalSearch(formName, linkFlag) {

    if (formName == "global") SearchVal = document.globalSearchForm.query.value;
    else if (formName == "products") SearchVal = document.productSearchForm.productSearch.value;

    if (SearchVal == "") {
        alert("Please enter in your search term");
        if (formName == "global") document.globalSearchForm.query.focus();
        else if (formName == "products") document.productSearchForm.productSearch.focus();
        if (linkFlag != 1) return false;
    } else {
        //window.location = "/baynote_search/"+SearchVal;
        //window.location = "/search/apachesolr_search/"+SearchVal;
        //window.location = "/search/node/" + SearchVal;
        window.location = "/site-search?term=" + SearchVal;
        return false;
    }
}


// This function is for a page-level content sensitive implementation
function OneLink(sHostname) {
    languageUrl = sHostname + ".flukenetworks.com";
    switch (sHostname) {
        case "www":
            languageCookie = "en";
            regionCookie = "us";
            break;
        case "fr":
            languageCookie = "fr";
            regionCookie = "fr";
            break;
        case "de":
            languageCookie = "de";
            regionCookie = "de";
            break;
        case "es":
            languageCookie = "es";
            regionCookie = "es";
            break;
        case "cn":
            languageCookie = "zh";
            regionCookie = "cn";
            break;
        case "jp":
            languageCookie = "ja";
            regionCookie = "jp";
            break;
        case "ko":
            languageCookie = "ko";
            regionCookie = "kr";
            break;
        case "pt":
            languageCookie = "pt";
            regionCookie = "br";
            break;
        case "ru":
            languageCookie = "ru";
            regionCookie = "ru";
            break;
        default:
            languageCookie = "en";
            regionCookie = "us";
    }
    var tempDomain = location.host;
    var domainName = tempDomain.split(".");
    var countTemp = domainName.length;
    var finalDomain = domainName[countTemp - 2] + "." + domainName[countTemp - 1];
    setCookie("language", languageCookie, 365, "/", finalDomain);
    setCookie("region", regionCookie, 365, "/", finalDomain);
    document.location.href = document.location.protocol + "//" +
        languageUrl + document.location.pathname + document.location.search;
}

function showSignIn() {
    ddmenuitem = $('#utilitynav_std_sub_signin').css('visibility', 'visible');
}

function showHideMenuSelect(menuItem) {
    if (menuItem.value == "") document.getElementById('menuselect_display').innerHTML = "";
    else document.getElementById('menuselect_display').innerHTML = document.getElementById('menuselect_' + menuItem.value).innerHTML;
}

(function ($) {
    $(function() {
        /* About Us Page tabs */
        $('#about-us-tabs td').click(function () {
            /* hide all the sections. */
            $('.suites-tab-desc-box').hide();
            /* Mark the tab as active */
            $('#about-us-tabs td').removeClass('active');
            $(this).addClass('active');
            /* Get the identifier from the tab */
            var tab = $(this).attr('id').replace('tab-', '#box-');
            $(tab).fadeIn();
        });
    });
})(jQuery);
