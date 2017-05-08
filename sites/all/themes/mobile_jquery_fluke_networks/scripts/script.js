// This function is used on expertise pages to display content based on drop down menu selection.
function showHideMenuSelect(menuItem) {
    if (menuItem.value == "") document.getElementById('menuselect_display').innerHTML = "";
    else document.getElementById('menuselect_display').innerHTML = document.getElementById('menuselect_' + menuItem.value).innerHTML;
}

function searchArray(findValue, targetArray) {
    for (var i = 0; i < targetArray.length; i++) {
        if (findValue.indexOf(targetArray[i]) > -1) {
            return i;
        }
    }
    return -1;
}

// A handy setCookie function.
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

// A handy getCookie function.
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

//
function selectRegion() {
    grayOut(true);
    $('#selectRegionBox').slideDown(400);
    populateCountry();
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

function setRegion() {

    var tempDomain = location.host;
    var domainName = tempDomain.split(".");
    var countTemp = domainName.length;
    var finalDomain = domainName[countTemp - 2] + "." + domainName[countTemp - 1];

    selCountry = document.getElementById("regionCountry");
    regCountry = selCountry.options[selCountry.selectedIndex].value;
    if (regCountry == "") {
        alert("Please select a country");
        exit;
    }
    setCookie("regCountry", regCountry, 365, "/", finalDomain);

    selLang = document.getElementById("language");
    regLang = selLang.options[selLang.selectedIndex].value;
    if (regLang == "") {
        alert("Please select a language");
        exit;
    }
    setCookie("regLang", regLang, 365, "/", finalDomain);

    //$('#selectRegionBox').slideUp(400);
    //grayOut(false);

    var sHostname = regLang.split("-");
    var selectedLang = sHostname[0].toLowerCase();

    languageUrl = selectedLang + ".flukenetworks.com";
    if (languageUrl == "en.flukenetworks.com") languageUrl = "www.flukenetworks.com";

    setRegionAndLanguage(selectedLang);

    var includedSubs = new Array("www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com", "local.flukenetworks.com");
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
    return finalDomain;
}

function autoRegion(ipCountryCode) {
    var finalDomain = getFinalDomain();
    var autoRegLang;
    var sHostname;
    var selectedLang;
    if (ipCountryCode != null) {
        if (ipCountryCode in countryArr) {
            autoRegLang = countryArr[ipCountryCode][1][0];
            setCookie("regCountry", ipCountryCode, 365, "/", finalDomain);
            setCookie("regLang", autoRegLang, 365, "/", finalDomain);
            sHostname = autoRegLang.split("-");
            selectedLang = sHostname[0].toLowerCase();
            setRegionAndLanguage(selectedLang);
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
            var includedSubsReturn;
            var excludedSubs = new Array("/print/", "/doc_links_pdf/", "/admin", "/node", "/apps/", "/ppc/", "/co/");
            var excludedSubsReturn = searchArray(window.location.href, excludedSubs);

            if (!(selectedLanguage)) {
                var includedSubs1 = new Array("www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com", "local.flukenetworks.com", "flukenetworksdev.danahertm.com", "flukenetworkstst.danahertm.com");
                includedSubsReturn = searchArray(document.domain, includedSubs1);
                if ((excludedSubsReturn == -1) && (includedSubsReturn > -1)) {
                    var regionTimer = window.setTimeout('selectRegion()', 2000);
                }
            } else {
                countryLanguage(selectedCountry);
                var regLangCookie = selectedLanguage.split("-");
                var languageUrl = regLangCookie[0].toLowerCase() + ".flukenetworks.com";
                if (languageUrl == "en.flukenetworks.com") languageUrl = "www.flukenetworks.com";
                var includedSubs = new Array("www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com");
                includedSubsReturn = searchArray(document.domain, includedSubs);
                if ((excludedSubsReturn == -1) && (includedSubsReturn > -1) && (languageUrl != document.domain)) {
                    document.location.href = document.location.protocol + "//" + languageUrl + document.location.pathname + document.location.search;
                }
            }
        }
    }
};

selectedLanguage = getCookie("regLang");
if (typeof selectedLanguage == 'undefined') {
    XMLHttpRequestObject.open("GET", "/reglang", true);
    XMLHttpRequestObject.send();
} else {
    var regLangCookie = selectedLanguage.split("-");
    var cookieHost = regLangCookie[0].toLowerCase() + ".flukenetworks.com";
    if (cookieHost == "en.flukenetworks.com") cookieHost = "www.flukenetworks.com";
    var excludedPaths = new Array("/print/", "/doc_links_pdf/", "/admin", "/node", "/apps/", "/ppc/", "/co/");
    var productionDomains = new Array("www.flukenetworks.com", "fr.flukenetworks.com", "de.flukenetworks.com", "es.flukenetworks.com", "pt.flukenetworks.com", "cn.flukenetworks.com", "jp.flukenetworks.com", "ko.flukenetworks.com", "ru.flukenetworks.com");
    if ((searchArray(window.location.href, excludedPaths) == -1) && (searchArray(document.domain, productionDomains) > -1) && (cookieHost != document.domain)) {
        document.location.href = document.location.protocol + "//" + cookieHost + document.location.pathname + document.location.search;
    }
}

$(document).ready(function () {
    selectedCountry = getCookie("regCountry");
    if (typeof selectedCountry == 'undefined') {
        selectedCountry = 'US';
    }
    countryLanguage(selectedCountry);

});