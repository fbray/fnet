// $Id: marketo_form.js 5380 2014-05-22 22:42:46Z sogden1 $
/**
 * Created by sogden1 on 4/1/14.
 */

if(typeof $jQ === 'undefined'){
    var $jQ = jQuery.noConflict();
}
function exportIsValid() {
    var validExport = false;
    var params = "FirstName=" + encodeURIComponent($jQ("#FirstName").val());
    params += "&LastName=" + encodeURIComponent($jQ("#LastName").val());
    if ($jQ("#Email").val()) {
        params += "&Email=" + encodeURIComponent($jQ("#Email").val());
    }
    if ($jQ("#Company").val()) {
        params += "&Company=" + encodeURIComponent($jQ("#Company").val());
    }
    if ($jQ("#Address").val()) {
        params += "&Address=" + encodeURIComponent($jQ("#Address").val());
    }
    if ($jQ("#City").val()) {
        params += "&City=" + encodeURIComponent($jQ("#City").val());
    }
    if ($jQ("#State").val()) {
        params += "&State=" + encodeURIComponent($jQ("#State").val());
    }
    if ($jQ("#Country").val()) {
        params += "&Country=" + encodeURIComponent($jQ("#Country").val());
    }
    if ($jQ("#PostalCode").val()) {
        params += "&Zip=" + encodeURIComponent($jQ("#PostalCode").val());
    }
    if ($jQ("input[name='retURL'][type='hidden']").val()) {
        var retUrl = $jQ("input[name='retURL'][type='hidden']").val();
        if (retUrl.indexOf("Document") > 0) {
            params += "&DocId=" + encodeURIComponent(retUrl.substring(retUrl.indexOf("Document") + 9));
        } else if ($jQ("#Document").val()) {
            params += "&DocId=" + encodeURIComponent($jQ("#Document").val());
        } else {
            params += "&DocId=" + encodeURIComponent(retUrl);
        }
    }
    $jQ.ajax({url: export_control_url,
        type: "GET",
        dataType: 'text',
        data: params,
        async: false,
        success: function (data) {
            if (data == 'CLEARED') {
                validExport = true;
            }
        }
    });
    return validExport;
}

//-- Start Marketo JS Overwrite
Mkto.formSubmit = function (elt) {
    for (var i = 0; i < elt.elements.length; i++) {
        Mkto.clearError(elt.elements[i]);
    }
    var submitButton = null;
    var allowSubmit = true;
    try {
        Mkto.recomputeMessages();
    } catch (e) {
    }
    for (var i = 0; i < elt.elements.length; i++) {
        var fld = elt.elements[i];
        if (!Mkto.validateField(fld)) {
            allowSubmit = false;
        }
        if (fld.name == "cr") {
            fld.value = Mkto.getUrlParam("cr");
        }
        if (fld.name == "kw") {
            fld.value = Mkto.getUrlParam("kw");
        }
        if (fld.name == "searchstr") {
            fld.value = Mkto.getReferrerParam("q");
        }
        if (fld.name == "submitButton") {
            submitButton = fld;
        }
        if (fld.name == '_marketo_comments') {
            Mkto.addField(elt, 'hidden', '_comments_marketo', fld.value);
        }
        if (fld.type == 'checkbox') {
            var hidden = null;

            // Try and find existing hidden input field that we might have created
            // on an earlier trip through formSubmit.
            var related = document.getElementsByName(fld.name);
            for (var j = 0; j < related.length; j++) {
                if (related[j].type == 'hidden') {
                    hidden = related[j];
                    break;
                }
            }

            if (fld.checked) {
                // If the field is checked, remove any lingering hidden field that
                // may have been created on a past form post which was aborted (perhaps
                // due to validation failure, etc).
                if (hidden) {
                    hidden.parentNode.removeChild(hidden);
                }
            }
            // Else, create hidden input field with value 0 for the unchecked checkbox as
            // unchecked checkboxes are not sent in form POST.
            else if (!hidden) {
                try {
                    // This form of createElement only works on IE and is needed to get the
                    // NAME attribute to stick as IE can't set name attr with setAttribute.
                    hidden = document.createElement("<input type='hidden' name='" + fld.name + "' value='0'>");
                }
                catch (e) {
                    // This createElement is for regular DOM implementations.
                    hidden = document.createElement("input");
                    hidden.setAttribute('type', 'hidden');
                    hidden.setAttribute('name', fld.name);
                    hidden.setAttribute('value', 0);
                }
                elt.appendChild(hidden);
            }
        }
    }
    if (allowSubmit) {
        if (!exportIsValid()) {
            alert("Export control check failed – please email support@flukenetworks.com");
            allowSubmit = false;
        }
    }
    Mkto.addField(elt, 'hidden', '_mkto_version', '2.4.7');

    //Capture the __cdrop cookie
    var syndicationId = Mkto.captureSyndicationId('__cdrop');
    if (syndicationId !== null) {
        Mkto.addField(elt, 'hidden', 'MarketoSocialSyndicationId', syndicationId);
    }
    if (allowSubmit) {
        if (!Mkto.pageSubmitted) {
            Mkto.pageSubmitted = true;

            // The tracking cookie is normally created by munchkin at initialization
            // except if you have the "cookieAnon" setting set to false.  In that
            // case we want to get the cookie created before submitting the form.  We
            // call createTrackingCookie and even if it was already called, it is safe
            // to call it again.
            try {
                if ((typeof Munchkin != 'undefined') && (typeof Munchkin.createTrackingCookie == 'function')) {
                    Munchkin.createTrackingCookie(true);
                }
            }
            catch (e) {
                // Ignore munchkin not found
            }

            elt.submit();
            if (submitButton != null) {
                var lang = typeof mktFormLanguage !== 'undefined' ? mktFormLanguage : 'English';
                submitButton.disabled = true;
                if (submitButton.value != 'Descargar') {
                    var msg = Mkto.messages[lang]['pleaseWait'];
                    if (lang === 'English' && msg == Mkto.defaultMessages[lang]['pleaseWait']) {
                        try {
                            msg = getPleaseWaitMessage(submitButton, lang);
                        } catch (e) {
                        }
                    }
                    submitButton.value = msg;
                }
            }
        } else {
            allowSubmit = false;
        }
    }
    if (allowSubmit) {
        //remove PURL Cookie on submit.
        var domain = Mkto.getLPDomain(document.location.hostname);
        Mkto.clearLPCookie('_mkto_purl', '/', domain);

    }
    return allowSubmit;
};
//-- End Marketo JS Overwrite

