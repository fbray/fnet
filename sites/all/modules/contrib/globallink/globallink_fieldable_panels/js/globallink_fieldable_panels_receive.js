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

function ajax_completed (data) {
  var content = '<table class="tpt_popup_table"><tr><th>&nbsp;</th><th>Source Content</th><th>Translated Content</th></tr>';

  error = data['error'];
  target = data['target'];
  source_obj = data['source'];

  if (error != null && error != undefined) {
    content += '<tr><td colspan="3"><span style="color: red;text-align: center;">' + error + '</span></td></tr>';
    content += '</table>';

    jQuery('#' + _div).empty();
    jQuery('#' + _div).append(content);

    return true;
  }

  if (source_obj == null || source_obj == undefined || source_obj == '') {
    return true;
  }

  jQuery.each(target, function(field, f_object) {
    if (field == 'fpid') {
      return;
    }

    jQuery.each(f_object, function(t_und, t_obj) {
      jQuery.each(t_obj, function(delta, obj) {
        var source_text = '';
        var target_text = '';
        if (obj['type'] && obj['type'] == 'file_entity') {obj['subfield']
          source_text = source_obj[field][t_und][delta][obj['subfield']];
          target_text = obj[obj['subfield']];
          content += '<TR><TD><b>' + obj['label'] + ' ' + obj['subfield_label'] +'</b></TD><TD>' + source_text + '</TD><TD>' + target_text + '</TD></TR>';
          return true;
        }
        if (source_obj[field] != null && source_obj[field] != undefined) {
          source_text = escape_html(source_obj[field][t_und][delta]['translatedContent']);
        }

        if (source_text == '') {
          source_text = '<span style="color:red;">Field Deleted</span>';
        }

        if (obj != null && obj != undefined) {
          target_text = escape_html(obj['translatedContent']);

          if (target_text != '') {
            if (field == 'link_title') {
              label = 'Title';
            }

            content += '<tr><td><b>' + escape_html(obj['fieldName'])  + '</b></td><td>' + source_text + '</td><td>' + target_text + '</td></tr>';
          }
        }
      });
    });
  });

  content += '</table>';

  jQuery('#' + _div).empty();
  jQuery('#' + _div).append(content);

  return true;
}