var _div;
var _img;

(function($) {
  Drupal.behaviors.globallink = {
    attach: function() {
      if (Drupal.settings.globallink == undefined) {
        return;
      }

      var popup = Drupal.settings.globallink.popup;
      var previewpath = Drupal.settings.globallink.previewpath;
      var rids = Drupal.settings.globallink.rids;

      _img = Drupal.settings.globallink.ajax_image;

      $.each(popup, function(link, div) {
        $('#' + link).click(function() {
          _div = div;

          $('#' + div).dialog({
            modal: true,
            show: {
              effect: "blind",
              duration: 100
            },
            width: 700,
            height : 400
          });

          $('#' + div).empty();

          $('#' + div).append('<div style="width: 100%; height:100%; text-align:center;"><div class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div></div></div>');

          $.ajax({
            type: 'POST',
            url: previewpath,
            dataType: 'json',
            data: 'rid=' + rids[div],
            success: ajax_completed,
            error: function(xhr, textStatus, errorThrown) {
              $('#' + _div).empty();
              $('#'+div).html(textStatus);
            }
          });
        });
      });
    }
  }
})(jQuery);

function escape_html(string) {
  return jQuery('<pre>').text(string).html();
}

function ajax_completed($data) {
    if ($data['source'] == '') {
        content = 'There was some error while generating the preview. Please try again after some time.';
        jQuery('#' + _div).empty();
        jQuery('#' + _div).append(content);
        return true;
    }
    var content = '<TABLE class="tpt_popup_table"><TR><TH>&nbsp;</TH><TH>Source Content</TH><TH>Translated Content</TH></TR>';
    error = $data['error'];
    target = $data['target'];
    source_obj = $data['source'];
    if (error != null && error != undefined) {
        content += '<TR><TD colspan="3"><span style="color: red;text-align: center;">' + error + '</span></TD></TR>';
        content += '</TABLE>';
        jQuery('#' + _div).empty();
        jQuery('#' + _div).append(content);
        return true;
    }
    if (source_obj == null || source_obj == undefined || source_obj == '') {
        return true;
    }

    jQuery.each(target, function ($field_name, $lang_arr) {
        if ($field_name !== 'bid' && $field_name !== 'metatags' && $field_name !== 'path') {
            jQuery.each($lang_arr, function ($lang_code, $delta_arr) {
                jQuery.each($delta_arr, function ($delta, $field_obj) {
                    var label = '';
                    if($field_obj['fieldLabel'] !== null && $field_obj['fieldLabel'] !== undefined) {
                        label = $field_obj['fieldLabel'];
                    } else {
                        label = $field_obj['fieldName'];
                    }
                    var source_text = '';
                    var target_text = '';
                    if (source_obj[$field_name] !== null && source_obj[$field_name] !== undefined) {
                        if (source_obj[$field_name][$lang_code] !== null && source_obj[$field_name][$lang_code] !== undefined) {
                            if (source_obj[$field_name][$lang_code][$delta] !== null && source_obj[$field_name][$lang_code][$delta] !== undefined) {
                                source_text = escape_html(source_obj[$field_name][$lang_code][$delta]['translatedContent']);
                            }
                        }
                    }
                    if (source_text === '') {
                        source_text = '<span style="color:red;">Field Empty</span>';
                    }
                    if ($field_obj !== null && $field_obj !== undefined) {
                        if ($field_obj['translatedContent'] !== null && $field_obj['translatedContent'] !== undefined) {
                            target_text = escape_html($field_obj['translatedContent']);
                            if (target_text !== '') {
                                content += '<TR><TD><b>' + label + '</b></TD><TD>' + source_text + '</TD><TD>' + target_text + '</TD></TR>';
                            }
                        }
                    }
                });
            });
        }

        if ($field_name === 'metatags') {
            jQuery.each($lang_arr, function ($mt_field_name, $arr) {
                jQuery.each($arr, function ($key, $field_obj) {
                    var label = '';
                    if($field_obj['fieldLabel'] !== null && $field_obj['fieldLabel'] !== undefined) {
                        label = $field_obj['fieldLabel'];
                    } else {
                        label = $field_obj['fieldName'];
                    }
                    var source_text = '';
                    var target_text = '';
                    if (source_obj[$field_name] !== null && source_obj[$field_name] !== undefined) {
                        if (source_obj[$field_name][$mt_field_name] !== null && source_obj[$field_name][$mt_field_name] !== undefined) {
                            if (source_obj[$field_name][$mt_field_name][$key] !== null && source_obj[$field_name][$mt_field_name][$key] !== undefined) {
                                source_text = escape_html(source_obj[$field_name][$mt_field_name][$key]['translatedContent']);
                            }
                        }
                    }
                    if (source_text === '') {
                        source_text = '<span style="color:red;">Field Empty</span>';
                    }
                    if ($field_obj !== null && $field_obj !== undefined) {
                        if ($field_obj['translatedContent'] !== null && $field_obj['translatedContent'] !== undefined) {
                            target_text = escape_html($field_obj['translatedContent']);
                            if (target_text !== '') {
                                content += '<TR><TD><b>' + label + '</b></TD><TD>' + source_text + '</TD><TD>' + target_text + '</TD></TR>';
                            }
                        }
                    }
                });
            });
        }
        if ($field_name === 'path') {
            var source_text = '';
            var target_text = '';
            var label = '';
            if ($lang_arr['label'] !== null && $lang_arr['label'] !== undefined) {
                label = $lang_arr['label'];
            } else {
                label = $lang_arr['name'];
            }
            if ($lang_arr['translation'] !== null && $lang_arr['label'] !== undefined) {
                target_text = escape_html($lang_arr['translation']);
            }
            if (source_obj['path']['translation'] !== null && source_obj['path']['translation'] !== undefined) {
                source_text = escape_html($lang_arr['translation']);
            }
            content += '<TR><TD><b>' + label + '</b></TD><TD>' + source_text + '</TD><TD>' + target_text + '</TD></TR>';  
        }
    });

    content += '</TABLE>';
    jQuery('#' + _div).empty();
    jQuery('#' + _div).append(content);

    return true;
}
