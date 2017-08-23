<?php
/**
 * @file
 * Alternative Language Views filter handler.
 */

/**
 * Filter by language (with alternative).
 */
class alternative_language_views_filter_handler extends views_handler_filter_in_operator {

  /**
   * Overriding views_handler_filter_in_operator->get_value_options().
   */
  public function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Language');
      $languages = array(
        '***CURRENT_LANGUAGE***'     => t("Current user's language"),
        '***DEFAULT_LANGUAGE***'     => t("Default site language"),
        '***ALTERNATIVE_LANGUAGE***' => t("Alternative language"),
        LANGUAGE_NONE => t('No language'),
      );
      $languages = array_merge($languages, views_language_list());
      $this->value_options = $languages;
    }
  }

  /**
   * Overriding views_handler_filter_in_operator->query().
   */
  public function query() {
    global $language_content;

    if (empty($this->value)) {
      return;
    }

    $default_language = language_default();

    // Get a list of all languages for the query.
    $languages = array();
    foreach ($this->value as $value) {
      switch ($value) {
        case '***CURRENT_LANGUAGE***':
          $languages[$language_content->language] = TRUE;
          break;

        case '***DEFAULT_LANGUAGE***':
          $languages[$default_language->language] = TRUE;
          break;

        case '***ALTERNATIVE_LANGUAGE***':
          if ($language_content->use_alternative && !empty($language_content->alternative)) {
            $languages[$language_content->alternative] = TRUE;
          }
          else {
            $languages[$language_content->language] = TRUE;
          }
          break;

        default:
          $languages[$value] = TRUE;
          break;
      }
    }

    $this->ensure_my_table();

    $this->query->add_where($this->options['group'], "$this->table_alias.language", array_keys($languages), $this->operator);
  }

}
