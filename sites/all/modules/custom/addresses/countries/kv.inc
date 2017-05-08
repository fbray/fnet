<?php
// $Id$
/**
 * @file
 * "Kosovo" specific data
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
function addresses_province_list_kv() {
  return array(
    '01' => t('Komuna e Deçanit'),
    '02' => t('Komuna e Dragashit'),
    '03' => t('Komuna e Ferizajt'),
    '04' => t('Kosovo Polje'),
    '05' => t('Komuna e Gjakovës'),
    '06' => t('Komuna e Gjilanit'),
    '07' => t('Komuna e Drenasit'),
    '08' => t('Komuna e Istogut'),
    '09' => t('Komuna e Kaçanikut'),
    '10' => t('Kamenica'),
    '11' => t('Komuna e Klines'),
    '12' => t('Komuna e Leposaviqit'),
    '13' => t('Lipjan'),
    '14' => t('Komuna e Malisheves'),
    '15' => t('Komuna e Mitrovicës'),
    '16' => t('Novo Brdo'),
    '17' => t('Komuna e Obiliqit'),
    '18' => t('Komuna e Pejës'),
    '19' => t('Podujevo'),
    '20' => t('Komuna e Prishtinës'),
    '21' => t('Prizren'),
    '22' => t('Orahovac'),
    '23' => t('Opština Štrpce'),
    '24' => t('Komuna e Shtimes'),
    '25' => t('Komuna e Skenderajt'),
    '26' => t('Komuna e Thërandës'),
    '27' => t('Komuna e Vitisë'),
    '28' => t('Vushtrri'),
    '29' => t('Komuna e Zubin Potokut'),
    '30' => t('Opština Zvečan'),
    '31' => t('Komuna e Graçanicës'),
    '32' => t('Hani i Elezit'),
    '33' => t('Komuna e Junikut'),
    '34' => t('Komuna e Kllokotit'),
    '35' => t('Komuna e Mamushës'),
    '36' => t('Komuna e Parteshit'),
    '37' => t('Komuna e Ranillugut'),
  );
}