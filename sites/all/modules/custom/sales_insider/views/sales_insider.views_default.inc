<?php

/**
 * Created by PhpStorm.
 * User: ryanositis
 * Date: 12/24/17
 * Time: 10:48 AM
 */
/**
 * Implementation of hook_views_default_views()
 */
function sales_insider_views_default_views() {
    $views = array();
    $files = file_scan_directory(drupal_get_path('module', 'sales_insider') . '/views', '/.*\.view.inc$/');
    foreach ($files as $filepath => $file) {
        require $filepath;
        if (isset($view)) {
            $views[$view->name] = $view;
        }
    }
    return $views;
}