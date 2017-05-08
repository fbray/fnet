<?php
// $Id$

/**
 * @file
 * "Slovenia" specific data
 */

/**
 * Implementation of hook_province_list().
 *
 * Its a hook from Addresses module to list all
 * states/provinces/teritories of a given country
 *
 * @return
 *   Array. states where the keys are the state
 *   code and the value is the state name
 */
function addresses_province_list_si() {
  return array(
    '01' => t('Pomurska'),
    '02' => t('Podravska'),
    '03' => t('Koroška'),
    '04' => t('Savinjska'),
    '05' => t('Zasavska'),
    '06' => t('Spodnjeposavska'),
    '07' => t('Dolenjska'),
    '08' => t('Osrednjeslovenska'),
    '09' => t('Gorenjska'),
    '10' => t('Notranjsko-kraška'),
    '11' => t('Goriška'),
    '12' => t('Obalno-kraška'),
  );
}

