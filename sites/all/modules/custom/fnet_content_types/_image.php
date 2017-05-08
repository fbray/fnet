<?php

// single image for base content
// would be appropriate for teaser



  // Exported field_instance: 'node-industry-field_industry_image'
  $field_instances['node-industry-field_industry_image'] = array(
    'bundle' => 'industry',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 7,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 7,
    ),
    'widget_type' => 'imagefield_widget',
  );




  // Exported field_instance: 'node-exp_ind-field_exp_ind_banner_image'
  $field_instances['node-exp_ind-field_exp_ind_banner_image'] = array(
    'bundle' => 'exp_ind',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optionally, provide an image that will be displayed above the content area. The image must be 1000px wide.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_banner_image',
    'label' => 'Banner image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/industry_banners',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x10000',
      'min_resolution' => '1000x10',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 0,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-exp_ind-field_exp_ind_thumbnail'
  $field_instances['node-exp_ind-field_exp_ind_thumbnail'] = array(
    'bundle' => 'exp_ind',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optional thumbnail image for Expertise/Topic summary view.  Image must be 300px by 132px.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_thumbnail',
    'label' => 'Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/industry_thumbnails',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '300x132',
      'min_resolution' => '300x132',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => -1,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-exp_ind_lng-field_exp_ind_lng_banner_image'
  $field_instances['node-exp_ind_lng-field_exp_ind_lng_banner_image'] = array(
    'bundle' => 'exp_ind_lng',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optionally, provide an image that will be displayed above the content area. The image must be 1000px wide.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_lng_banner_image',
    'label' => 'Banner image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x10000',
      'min_resolution' => '1000x10',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-exp_ind_lng-field_exp_ind_lng_exp_ind'
  $field_instances['node-exp_ind_lng-field_exp_ind_lng_exp_ind'] = array(
    'bundle' => 'exp_ind_lng',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 54,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_lng_exp_ind',
    'label' => 'Expertise Industry',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -3,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-exp_rle-field_exp_rle_banner_image'
  $field_instances['node-exp_rle-field_exp_rle_banner_image'] = array(
    'bundle' => 'exp_rle',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optionally, provide an image that will be displayed above the content area. The image must be 1000px wide.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_banner_image',
    'label' => 'Banner image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/rle_banners',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x10000',
      'min_resolution' => '1000x10',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 0,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-exp_rle-field_exp_rle_thumbnail'
  $field_instances['node-exp_rle-field_exp_rle_thumbnail'] = array(
    'bundle' => 'exp_rle',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optional thumbnail image used in the Expertise/Role summary view.  Should be 300px x 132px.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_thumbnail',
    'label' => 'Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/role_thumbnails',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '300x132',
      'min_resolution' => '300x132',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => -1,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-exp_rle_lng-field_exp_rle_lng_banner_image'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_banner_image'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optionally, provide an image that will be displayed above the content area. The image must be 1000px wide.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_banner_image',
    'label' => 'Banner image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x10000',
      'min_resolution' => '1000x10',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-exp_rle_lng-field_exp_rle_lng_rle'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_rle'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_rle',
    'label' => 'Expertise Role',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -3,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-exp_tpc-field_exp_tpc_banner_image'
  $field_instances['node-exp_tpc-field_exp_tpc_banner_image'] = array(
    'bundle' => 'exp_tpc',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optionally, provide an image that will be displayed above the content area. The image must be 1000px wide.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_banner_image',
    'label' => 'Banner image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/topic_banners',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x10000',
      'min_resolution' => '1000x10',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 0,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-exp_tpc-field_exp_tpc_thumbnail'
  $field_instances['node-exp_tpc-field_exp_tpc_thumbnail'] = array(
    'bundle' => 'exp_tpc',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optional thumbnail image for summary view. Must be 300x132.',
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
        'weight' => -1,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_thumbnail',
    'label' => 'Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/topic_thumbnails',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '300x132',
      'min_resolution' => '300x132',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => -1,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-exp_tpc_lng-field_exp_tpc_lng_banner_image'
  $field_instances['node-exp_tpc_lng-field_exp_tpc_lng_banner_image'] = array(
    'bundle' => 'exp_tpc_lng',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optionally, provide an image that will be displayed above the content area. The image must be 1000px wide.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_lng_banner_image',
    'label' => 'Banner image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1000x10000',
      'min_resolution' => '1000x10',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-expertise-field_expertise_image'
  $field_instances['node-expertise-field_expertise_image'] = array(
    'bundle' => 'expertise',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_expertise_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 0,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-family-field_family_background_img'
  $field_instances['node-family-field_family_background_img'] = array(
    'bundle' => 'family',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 57,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_background_img',
    'label' => ' Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1200x410',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 5,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-family-field_family_hub_img'
  $field_instances['node-family-field_family_hub_img'] = array(
    'bundle' => 'family',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_hub_img',
    'label' => 'Hub Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '146x116',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 8,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 8,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-family-field_family_image'
  $field_instances['node-family-field_family_image'] = array(
    'bundle' => 'family',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-industry-field_ind_background_img'
  $field_instances['node-industry-field_ind_background_img'] = array(
    'bundle' => 'industry',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ind_background_img',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1200x410',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 8,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 8,
    ),
    'widget_type' => 'imagefield_widget',
  );



