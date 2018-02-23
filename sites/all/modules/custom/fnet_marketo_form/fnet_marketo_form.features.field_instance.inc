<?php
/**
 * @file
 * fnet_marketo_form.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function fnet_marketo_form_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_add_links'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_add_links'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add links to other pages within website or external website.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_add_links',
    'label' => 'Add Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_adtracker'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_adtracker'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_adtracker',
    'label' => 'Ad Tracking Code',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_banner_html'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_banner_html'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add HTML to display banner image in case if upload field is not used for banner image',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_banner_html',
    'label' => 'Banner HTML',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_banner_img'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_banner_img'] = array(
    'bundle' => 'fnet_marketo_form',
    'deleted' => 0,
    'description' => 'Upload banner image',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_banner_img',
    'label' => 'Banner Image (1000 pixel width)',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'images/marketo',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_image',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_disp_title'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_disp_title'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add title in this field also. This title will be visible to end user',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_disp_title',
    'label' => 'Display Title',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_export_ctrl'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_export_ctrl'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_export_ctrl',
    'label' => 'Export Control',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_form_btm_html'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_form_btm_html'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field can be used to add contact us information',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_form_btm_html',
    'label' => 'Contact us information',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_form_number'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_form_number'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The FORM NUMBER of the required Marketo Form. Ex: 1234',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_form_number',
    'label' => 'Marketo Form Number',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_form_prdimg_llnk'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_form_prdimg_llnk'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add URL to link the left side image',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_form_prdimg_llnk',
    'label' => 'Product Image Left Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_form_prdimg_rlnk'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_form_prdimg_rlnk'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add URL to link the right side image',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_form_prdimg_rlnk',
    'label' => 'Product Image Right Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-fnet_marketo_form-field_fnet_mkto_form_url'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_form_url'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The FOLLOW UP URL for after the submission of the Marketo Form. Ex: http://www.flukenetworks.com',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_form_url',
    'label' => 'Marketo Form Follow Up URL',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_main_content'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_main_content'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter main content in this field',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_main_content',
    'label' => 'Main Content',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_prod_img_left'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_prod_img_left'] = array(
    'bundle' => 'fnet_marketo_form',
    'deleted' => 0,
    'description' => 'Upload image to display it to the left side of the content',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_link_formatter',
        'settings' => array(
          'image_link' => 'field_fnet_mkto_form_prdimg_llnk',
          'image_style' => '',
        ),
        'type' => 'image_link_formatter',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image_link_formatter',
        'settings' => array(
          'image_link' => 'field_fnet_mkto_form_prdimg_llnk',
          'image_style' => '',
        ),
        'type' => 'image_link_formatter',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_prod_img_left',
    'label' => 'Product Image Left',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'images/marketo',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_image',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-fnet_marketo_form-field_fnet_mkto_prod_img_right'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_prod_img_right'] = array(
    'bundle' => 'fnet_marketo_form',
    'deleted' => 0,
    'description' => 'Upload image to display it to the right side of the content',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_link_formatter',
        'settings' => array(
          'image_link' => 'field_fnet_mkto_form_prdimg_rlnk',
          'image_style' => '',
        ),
        'type' => 'image_link_formatter',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image_link_formatter',
        'settings' => array(
          'image_link' => 'field_fnet_mkto_form_prdimg_rlnk',
          'image_style' => '',
        ),
        'type' => 'image_link_formatter',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_prod_img_right',
    'label' => 'Product Image Right',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'images/marketo',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
      ),
      'type' => 'image_image',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-fnet_marketo_form-field_fnet_mkto_title'.
  $field_instances['node-fnet_marketo_form-field_fnet_mkto_title'] = array(
    'bundle' => 'fnet_marketo_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add title for the marketo form',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fnet_mkto_title',
    'label' => 'Marketo Form title',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 17,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Ad Tracking Code');
  t('Add HTML to display banner image in case if upload field is not used for banner image');
  t('Add Links');
  t('Add URL to link the left side image');
  t('Add URL to link the right side image');
  t('Add links to other pages within website or external website.');
  t('Add title for the marketo form');
  t('Add title in this field also. This title will be visible to end user');
  t('Banner HTML');
  t('Banner Image (1000 pixel width)');
  t('Contact us information');
  t('Display Title');
  t('Enter main content in this field');
  t('Export Control');
  t('Main Content');
  t('Marketo Form Follow Up URL');
  t('Marketo Form Number');
  t('Marketo Form title');
  t('Product Image Left');
  t('Product Image Left Link');
  t('Product Image Right');
  t('Product Image Right Link');
  t('The FOLLOW UP URL for after the submission of the Marketo Form. Ex: http://www.flukenetworks.com');
  t('The FORM NUMBER of the required Marketo Form. Ex: 1234');
  t('This field can be used to add contact us information');
  t('Upload banner image');
  t('Upload image to display it to the left side of the content');
  t('Upload image to display it to the right side of the content');

  return $field_instances;
}
