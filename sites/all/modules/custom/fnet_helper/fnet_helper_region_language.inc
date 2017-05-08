<?php
// $Id$

/**
 * @file
 * Region Language codes by country
 *
 */

/**
 * Return default region language for a country
 * @param $country_code
 * @return string
 */
function fnet_helper_get_region_language_from_country($country_code) {
  $region_language = fnet_helper_region_language();
  if (array_key_exists(strtoupper($country_code), $region_language)) {
    return $region_language[$country_code][1][0];
  }
  else {
    return 'EN-US';
  }
}

/**
 * Region language array for fnet_helper_get_region_language_from_country
 * @return array
 */
function fnet_helper_region_language() {

  $region_language = array();

  //Afghanistan
  $region_language['AF'] = array();
  $region_language['AF'][0] = 'Afghanistan';
  $region_language['AF'][1] = array('EN-EU', 'English');


  //Albania
  $region_language['AL'] = array();
  $region_language['AL'][0] = 'Albania';
  $region_language['AL'][1] = array('EN-EU', 'English');


  //Algeria
  $region_language['DZ'] = array();
  $region_language['DZ'][0] = 'Algeria';
  $region_language['DZ'][1] = array('FR-EU', 'French');
  $region_language['DZ'][2] = array('EN-EU', 'English');

  //Andorra
  $region_language['AD'] = array();
  $region_language['AD'][0] = 'Andorra';
  $region_language['AD'][1] = array('ES-EU', 'Spanish');
  $region_language['AD'][2] = array('EN-EU', 'English');

  //Angola
  $region_language['AO'] = array();
  $region_language['AO'][0] = 'Angola';
  $region_language['AO'][1] = array('EN-EU', 'English');


  //Argentina
  $region_language['AR'] = array();
  $region_language['AR'][0] = 'Argentina';
  $region_language['AR'][1] = array('ES-LN', 'Spanish');


  //Armenia
  $region_language['AM'] = array();
  $region_language['AM'][0] = 'Armenia';
  $region_language['AM'][1] = array('EN-EU', 'English');
  $region_language['AM'][2] = array('RU-RU', 'Russian');

  //Australia
  $region_language['AU'] = array();
  $region_language['AU'][0] = 'Australia';
  $region_language['AU'][1] = array('EN-AU', 'English');

  //Austria
  $region_language['AT'] = array();
  $region_language['AT'][0] = 'Austria';
  $region_language['AT'][1] = array('DE-EU', 'German');
  $region_language['AT'][2] = array('EN-EU', 'English');

  //Azerbaijan
  $region_language['AZ'] = array();
  $region_language['AZ'][0] = 'Azerbaijan';
  $region_language['AZ'][1] = array('EN-EU', 'English');
  $region_language['AZ'][2] = array('RU-RU', 'Russian');

  //Bahrain
  $region_language['BH'] = array();
  $region_language['BH'][0] = 'Bahrain';
  $region_language['BH'][1] = array('EN-EU', 'English');


  //Bangladesh
  $region_language['BD'] = array();
  $region_language['BD'][0] = 'Bangladesh';
  $region_language['BD'][1] = array('EN-IN', 'English');


  //Belarus
  $region_language['BY'] = array();
  $region_language['BY'][0] = 'Belarus';
  $region_language['BY'][1] = array('RU-RU', 'Russian');
  $region_language['BY'][2] = array('EN-EU', 'English');

  //Belgium
  $region_language['BE'] = array();
  $region_language['BE'][0] = 'Belgium';
  $region_language['BE'][1] = array('FR-EU', 'French');
  $region_language['BE'][2] = array('EN-EU', 'English');

  //Benin
  $region_language['BJ'] = array();
  $region_language['BJ'][0] = 'Benin';
  $region_language['BJ'][1] = array('FR-EU', 'French');
  $region_language['BJ'][2] = array('EN-EU', 'English');

  //Bhutan
  $region_language['BT'] = array();
  $region_language['BT'][0] = 'Bhutan';
  $region_language['BT'][1] = array('EN-SU', 'English');


  //Bosnia and Herzegovina
  $region_language['BA'] = array();
  $region_language['BA'][0] = 'Bosnia and Herzegovina';
  $region_language['BA'][1] = array('EN-EU', 'English');


  //Botswana
  $region_language['BW'] = array();
  $region_language['BW'][0] = 'Botswana';
  $region_language['BW'][1] = array('EN-EU', 'English');


  //Brazil
  $region_language['BR'] = array();
  $region_language['BR'][0] = 'Brazil';
  $region_language['BR'][1] = array('PT-BR', 'Portuguese');


  //Brunei
  $region_language['BN'] = array();
  $region_language['BN'][0] = 'Brunei';
  $region_language['BN'][1] = array('EN-SU', 'English');
  $region_language['BN'][2] = array('CN-ZH', 'Chinese');

  //Bulgaria
  $region_language['BG'] = array();
  $region_language['BG'][0] = 'Bulgaria';
  $region_language['BG'][1] = array('EN-EU', 'English');


  //Burkina Faso
  $region_language['BF'] = array();
  $region_language['BF'][0] = 'Burkina Faso';
  $region_language['BF'][1] = array('FR-EU', 'French');
  $region_language['BF'][2] = array('EN-EU', 'English');

  //Burundi
  $region_language['BI'] = array();
  $region_language['BI'][0] = 'Burundi';
  $region_language['BI'][1] = array('FR-EU', 'French');
  $region_language['BI'][2] = array('EN-EU', 'English');

  //Cambodia
  $region_language['KH'] = array();
  $region_language['KH'][0] = 'Cambodia';
  $region_language['KH'][1] = array('EN-SU', 'English');


  //Cameroon
  $region_language['CM'] = array();
  $region_language['CM'][0] = 'Cameroon';
  $region_language['CM'][1] = array('EN-EU', 'English');
  $region_language['CM'][2] = array('FR-EU', 'French');

  //Canada
  $region_language['CA'] = array();
  $region_language['CA'][0] = 'Canada';
  $region_language['CA'][1] = array('EN-CA', 'English');
  $region_language['CA'][2] = array('FR-CA', 'French');

  //Cape Verde
  $region_language['CV'] = array();
  $region_language['CV'][0] = 'Cape Verde';
  $region_language['CV'][1] = array('EN-EU', 'English');


  //Central African Republic
  $region_language['CF'] = array();
  $region_language['CF'][0] = 'Central African Republic';
  $region_language['CF'][1] = array('FR-EU', 'French');
  $region_language['CF'][2] = array('EN-EU', 'English');

  //Chad
  $region_language['TD'] = array();
  $region_language['TD'][0] = 'Chad';
  $region_language['TD'][1] = array('FR-EU', 'French');
  $region_language['TD'][2] = array('EN-EU', 'English');

  //Chile
  $region_language['CL'] = array();
  $region_language['CL'][0] = 'Chile';
  $region_language['CL'][1] = array('ES-LN', 'Spanish');


  //China
  $region_language['CN'] = array();
  $region_language['CN'][0] = 'China';
  $region_language['CN'][1] = array('CN-ZH', 'Chinese');


  //Colombia
  $region_language['CO'] = array();
  $region_language['CO'][0] = 'Colombia';
  $region_language['CO'][1] = array('ES-LN', 'Spanish');


  //Comoros
  $region_language['KM'] = array();
  $region_language['KM'][0] = 'Comoros';
  $region_language['KM'][1] = array('FR-EU', 'French');
  $region_language['KM'][2] = array('EN-EU', 'English');

  //Congo
  $region_language['CG'] = array();
  $region_language['CG'][0] = 'Congo';
  $region_language['CG'][1] = array('FR-EU', 'French');
  $region_language['CG'][2] = array('EN-EU', 'English');

  //Congo, Democratic Republic of the
  $region_language['CD'] = array();
  $region_language['CD'][0] = 'Congo, Democratic Republic of the';
  $region_language['CD'][1] = array('FR-EU', 'French');
  $region_language['CD'][2] = array('EN-EU', 'English');

  //Costa Rica
  $region_language['CR'] = array();
  $region_language['CR'][0] = 'Costa Rica';
  $region_language['CR'][1] = array('ES-LN', 'Spanish');


  //Côte d'Ivoire
  $region_language['CI'] = array();
  $region_language['CI'][0] = 'Côte d\'Ivoire';
  $region_language['CI'][1] = array('FR-EU', 'French');
  $region_language['CI'][2] = array('EN-EU', 'English');

  //Croatia
  $region_language['HR'] = array();
  $region_language['HR'][0] = 'Croatia';
  $region_language['HR'][1] = array('EN-EU', 'English');


  //Cyprus
  $region_language['CY'] = array();
  $region_language['CY'][0] = 'Cyprus';
  $region_language['CY'][1] = array('EN-EU', 'English');


  //Czech Republic
  $region_language['CZ'] = array();
  $region_language['CZ'][0] = 'Czech Republic';
  $region_language['CZ'][1] = array('EN-EU', 'English');


  //Denmark
  $region_language['DK'] = array();
  $region_language['DK'][0] = 'Denmark';
  $region_language['DK'][1] = array('EN-EU', 'English');
  $region_language['DK'][2] = array('EN-EU', 'English');

  //Djibouti
  $region_language['DJ'] = array();
  $region_language['DJ'][0] = 'Djibouti';
  $region_language['DJ'][1] = array('FR-EU', 'French');
  $region_language['DJ'][2] = array('EN-EU', 'English');

  //East Timor
  $region_language['TP'] = array();
  $region_language['TP'][0] = 'East Timor';
  $region_language['TP'][1] = array('EN-SU', 'English');

  //Ecuador
  $region_language['EC'] = array();
  $region_language['EC'][0] = 'Ecuador';
  $region_language['EC'][1] = array('ES-LN', 'Spanish');

  //Egypt
  $region_language['EG'] = array();
  $region_language['EG'][0] = 'Egypt';
  $region_language['EG'][1] = array('EN-EU', 'English');
  $region_language['EG'][2] = array('FR-EU', 'French');

  //Equatorial Guinea
  $region_language['GQ'] = array();
  $region_language['GQ'][0] = 'Equatorial Guinea';
  $region_language['GQ'][1] = array('ES-EU', 'Spanish');
  $region_language['GQ'][2] = array('FR-EU', 'French');
  $region_language['GQ'][3] = array('EN-EU', 'English');

  //Eritrea
  $region_language['ER'] = array();
  $region_language['ER'][0] = 'Eritrea';
  $region_language['ER'][1] = array('EN-EU', 'English');


  //Estonia
  $region_language['EE'] = array();
  $region_language['EE'][0] = 'Estonia';
  $region_language['EE'][1] = array('EN-EU', 'English');


  //Ethiopia
  $region_language['ET'] = array();
  $region_language['ET'][0] = 'Ethiopia';
  $region_language['ET'][1] = array('EN-EU', 'English');


  //Finland
  $region_language['FI'] = array();
  $region_language['FI'][0] = 'Finland';
  $region_language['FI'][1] = array('EN-EU', 'English');


  //France
  $region_language['FR'] = array();
  $region_language['FR'][0] = 'France';
  $region_language['FR'][1] = array('FR-EU', 'French');


  //Gabon
  $region_language['GA'] = array();
  $region_language['GA'][0] = 'Gabon';
  $region_language['GA'][1] = array('FR-EU', 'French');
  $region_language['GA'][2] = array('EN-EU', 'English');

  //Gambia
  $region_language['GM'] = array();
  $region_language['GM'][0] = 'Gambia';
  $region_language['GM'][1] = array('EN-EU', 'English');


  //Georgia
  $region_language['GE'] = array();
  $region_language['GE'][0] = 'Georgia';
  $region_language['GE'][1] = array('EN-EU', 'English');


  //Germany
  $region_language['DE'] = array();
  $region_language['DE'][0] = 'Germany';
  $region_language['DE'][1] = array('DE-EU', 'German');


  //Ghana
  $region_language['GH'] = array();
  $region_language['GH'][0] = 'Ghana';
  $region_language['GH'][1] = array('EN-EU', 'English');


  //Greece
  $region_language['GR'] = array();
  $region_language['GR'][0] = 'Greece';
  $region_language['GR'][1] = array('EN-EU', 'English');


  //Guatemala
  $region_language['GT'] = array();
  $region_language['GT'][0] = 'Guatemala';
  $region_language['GT'][1] = array('ES-LN', 'Spanish');


  //Guinea
  $region_language['GN'] = array();
  $region_language['GN'][0] = 'Guinea';
  $region_language['GN'][1] = array('FR-EU', 'French');
  $region_language['GN'][2] = array('EN-EU', 'English');

  //Guinea-Bissau
  $region_language['GW'] = array();
  $region_language['GW'][0] = 'Guinea-Bissau';
  $region_language['GW'][1] = array('FR-EU', 'French');
  $region_language['GW'][2] = array('EN-EU', 'English');

  //Hong Kong
  $region_language['HK'] = array();
  $region_language['HK'][0] = 'Hong Kong';
  $region_language['HK'][1] = array('EN-SU', 'English');

  //Hungary
  $region_language['HU'] = array();
  $region_language['HU'][0] = 'Hungary';
  $region_language['HU'][1] = array('EN-EU', 'English');


  //Iceland
  $region_language['IS'] = array();
  $region_language['IS'][0] = 'Iceland';
  $region_language['IS'][1] = array('EN-EU', 'English');


  //India
  $region_language['IN'] = array();
  $region_language['IN'][0] = 'India';
  $region_language['IN'][1] = array('EN-IN', 'English');


  //Indonesia
  $region_language['ID'] = array();
  $region_language['ID'][0] = 'Indonesia';
  $region_language['ID'][1] = array('EN-IN', 'English');


  //Iraq
  $region_language['IQ'] = array();
  $region_language['IQ'][0] = 'Iraq';
  $region_language['IQ'][1] = array('EN-EU', 'English');


  //Ireland
  $region_language['IE'] = array();
  $region_language['IE'][0] = 'Ireland';
  $region_language['IE'][1] = array('EN-EU', 'English');


  //Israel
  $region_language['IL'] = array();
  $region_language['IL'][0] = 'Israel';
  $region_language['IL'][1] = array('EN-EU', 'English');


  //Italy
  $region_language['IT'] = array();
  $region_language['IT'][0] = 'Italy';
  $region_language['IT'][1] = array('EN-EU', 'English');


  //Jamaica
  $region_language['JM'] = array();
  $region_language['JM'][0] = 'Jamaica';
  $region_language['JM'][1] = array('EN-LN', 'English');


  //Japan
  $region_language['JP'] = array();
  $region_language['JP'][0] = 'Japan';
  $region_language['JP'][1] = array('JP-JA', 'Japanese');


  //Jordan
  $region_language['JO'] = array();
  $region_language['JO'][0] = 'Jordan';
  $region_language['JO'][1] = array('EN-EU', 'English');


  //Kazakhstan
  $region_language['KZ'] = array();
  $region_language['KZ'][0] = 'Kazakhstan';
  $region_language['KZ'][1] = array('RU-RU', 'Russian');
  $region_language['KZ'][2] = array('EN-EU', 'English');

  //Kenya
  $region_language['KE'] = array();
  $region_language['KE'][0] = 'Kenya';
  $region_language['KE'][1] = array('EN-EU', 'English');


  //Korea South
  $region_language['KR'] = array();
  $region_language['KR'][0] = 'Korea South';
  $region_language['KR'][1] = array('KO-KR', 'Korean');


  //Kosovo
  $region_language['XK'] = array();
  $region_language['XK'][0] = 'Kosovo';
  $region_language['XK'][1] = array('EN-EU', 'English');


  //Kuwait
  $region_language['KW'] = array();
  $region_language['KW'][0] = 'Kuwait';
  $region_language['KW'][1] = array('EN-EU', 'English');


  //Kyrgyzstan
  $region_language['KG'] = array();
  $region_language['KG'][0] = 'Kyrgyzstan';
  $region_language['KG'][1] = array('RU-RU', 'Russian');
  $region_language['KG'][2] = array('EN-EU', 'English');

  //Laos
  $region_language['LA'] = array();
  $region_language['LA'][0] = 'Laos';
  $region_language['LA'][1] = array('EN-SU', 'English');


  //Latvia
  $region_language['LV'] = array();
  $region_language['LV'][0] = 'Latvia';
  $region_language['LV'][1] = array('EN-EU', 'English');


  //Lebanon
  $region_language['LB'] = array();
  $region_language['LB'][0] = 'Lebanon';
  $region_language['LB'][1] = array('EN-EU', 'English');
  $region_language['LB'][2] = array('FR-EU', 'French');

  //Lesotho
  $region_language['LS'] = array();
  $region_language['LS'][0] = 'Lesotho';
  $region_language['LS'][1] = array('EN-EU', 'English');


  //Liberia
  $region_language['LR'] = array();
  $region_language['LR'][0] = 'Liberia';
  $region_language['LR'][1] = array('EN-EU', 'English');


  //Libya
  $region_language['LY'] = array();
  $region_language['LY'][0] = 'Libya';
  $region_language['LY'][1] = array('EN-EU', 'English');


  //Liechtenstein
  $region_language['LI'] = array();
  $region_language['LI'][0] = 'Liechtenstein';
  $region_language['LI'][1] = array('DE-EU', 'German');
  $region_language['LI'][2] = array('EN-EU', 'English');

  //Lithuania
  $region_language['LT'] = array();
  $region_language['LT'][0] = 'Lithuania';
  $region_language['LT'][1] = array('EN-EU', 'English');


  //Luxembourg
  $region_language['LU'] = array();
  $region_language['LU'][0] = 'Luxembourg';
  $region_language['LU'][1] = array('DE-EU', 'German');
  $region_language['LU'][2] = array('FR-EU', 'French');

  //Macau
  $region_language['MO'] = array();
  $region_language['MO'][0] = 'Macau';
  $region_language['MO'][1] = array('EN-SU', 'English');

  //Macedonia
  $region_language['MK'] = array();
  $region_language['MK'][0] = 'Macedonia';
  $region_language['MK'][1] = array('EN-EU', 'English');


  //Madagascar
  $region_language['MG'] = array();
  $region_language['MG'][0] = 'Madagascar';
  $region_language['MG'][1] = array('FR-EU', 'French');
  $region_language['MG'][2] = array('EN-EU', 'English');

  //Malawi
  $region_language['MW'] = array();
  $region_language['MW'][0] = 'Malawi';
  $region_language['MW'][1] = array('EN-EU', 'English');


  //Malaysia
  $region_language['MY'] = array();
  $region_language['MY'][0] = 'Malaysia';
  $region_language['MY'][1] = array('EN-SU', 'English');


  //Mali
  $region_language['ML'] = array();
  $region_language['ML'][0] = 'Mali';
  $region_language['ML'][1] = array('FR-EU', 'French');
  $region_language['ML'][2] = array('EN-EU', 'English');

  //Malta
  $region_language['MT'] = array();
  $region_language['MT'][0] = 'Malta';
  $region_language['MT'][1] = array('EN-EU', 'English');


  //Mauritania
  $region_language['MR'] = array();
  $region_language['MR'][0] = 'Mauritania';
  $region_language['MR'][1] = array('EN-EU', 'English');
  $region_language['MR'][2] = array('FR-EU', 'French');

  //Mauritius
  $region_language['MU'] = array();
  $region_language['MU'][0] = 'Mauritius';
  $region_language['MU'][1] = array('FR-EU', 'French');
  $region_language['MU'][2] = array('EN-EU', 'English');

  //Mexico
  $region_language['MX'] = array();
  $region_language['MX'][0] = 'Mexico';
  $region_language['MX'][1] = array('ES-LN', 'Spanish');


  //Moldova
  $region_language['MD'] = array();
  $region_language['MD'][0] = 'Moldova';
  $region_language['MD'][1] = array('RU-RU', 'Russian');
  $region_language['MD'][2] = array('EN-EU', 'English');

  //Monaco
  $region_language['MC'] = array();
  $region_language['MC'][0] = 'Monaco';
  $region_language['MC'][1] = array('FR-EU', 'French');
  $region_language['MC'][2] = array('EN-EU', 'English');

  //Mongolia
  $region_language['MN'] = array();
  $region_language['MN'][0] = 'Mongolia';
  $region_language['MN'][1] = array('RU-RU', 'Russian');
  $region_language['MN'][2] = array('EN-EU', 'English');

  //Montenegro
  $region_language['ME'] = array();
  $region_language['ME'][0] = 'Montenegro';
  $region_language['ME'][1] = array('EN-EU', 'English');


  //Morocco
  $region_language['MA'] = array();
  $region_language['MA'][0] = 'Morocco';
  $region_language['MA'][1] = array('FR-EU', 'French');
  $region_language['MA'][2] = array('EN-EU', 'English');

  //Mozambique
  $region_language['MZ'] = array();
  $region_language['MZ'][0] = 'Mozambique';
  $region_language['MZ'][1] = array('EN-EU', 'English');


  //Myanmar (Burma)
  $region_language['MM'] = array();
  $region_language['MM'][0] = 'Myanmar (Burma)';
  $region_language['MM'][1] = array('EN-SU', 'English');


  //Namibia
  $region_language['NA'] = array();
  $region_language['NA'][0] = 'Namibia';
  $region_language['NA'][1] = array('EN-EU', 'English');


  //Nepal
  $region_language['NP'] = array();
  $region_language['NP'][0] = 'Nepal';
  $region_language['NP'][1] = array('EN-SU', 'English');


  //Netherlands
  $region_language['NL'] = array();
  $region_language['NL'][0] = 'Netherlands';
  $region_language['NL'][1] = array('EN-EU', 'English');

  //New Zealand
  $region_language['NZ'] = array();
  $region_language['NZ'][0] = 'New Zealand';
  $region_language['NZ'][1] = array('EN-AU', 'English');


  //Niger
  $region_language['NE'] = array();
  $region_language['NE'][0] = 'Niger';
  $region_language['NE'][1] = array('FR-EU', 'French');
  $region_language['NE'][2] = array('EN-EU', 'English');

  //Nigeria
  $region_language['NG'] = array();
  $region_language['NG'][0] = 'Nigeria';
  $region_language['NG'][1] = array('EN-EU', 'English');


  //Norway
  $region_language['NO'] = array();
  $region_language['NO'][0] = 'Norway';
  $region_language['NO'][1] = array('EN-EU', 'English');


  //Oman
  $region_language['OM'] = array();
  $region_language['OM'][0] = 'Oman';
  $region_language['OM'][1] = array('EN-SU', 'English');


  //Pakistan
  $region_language['PK'] = array();
  $region_language['PK'][0] = 'Pakistan';
  $region_language['PK'][1] = array('EN-EU', 'English');


  //Panama
  $region_language['PA'] = array();
  $region_language['PA'][0] = 'Panama';
  $region_language['PA'][1] = array('ES-LN', 'Spanish');


  //Peru
  $region_language['PE'] = array();
  $region_language['PE'][0] = 'Peru';
  $region_language['PE'][1] = array('ES-LN', 'Spanish');


  //Philippines
  $region_language['PH'] = array();
  $region_language['PH'][0] = 'Philippines';
  $region_language['PH'][1] = array('EN-SU', 'English');


  //Poland
  $region_language['PL'] = array();
  $region_language['PL'][0] = 'Poland';
  $region_language['PL'][1] = array('EN-EU', 'English');


  //Portugal
  $region_language['PT'] = array();
  $region_language['PT'][0] = 'Portugal';
  $region_language['PT'][1] = array('PT-EU', 'Portuguese');
  $region_language['PT'][2] = array('EN-EU', 'English');


  //Qatar
  $region_language['QA'] = array();
  $region_language['QA'][0] = 'Qatar';
  $region_language['QA'][1] = array('EN-EU', 'English');


  //Romania
  $region_language['RO'] = array();
  $region_language['RO'][0] = 'Romania';
  $region_language['RO'][1] = array('EN-EU', 'English');


  //Russia
  $region_language['RU'] = array();
  $region_language['RU'][0] = 'Russia';
  $region_language['RU'][1] = array('RU-RU', 'Russian');
  $region_language['RU'][2] = array('EN-EU', 'English');

  //Rwanda
  $region_language['RW'] = array();
  $region_language['RW'][0] = 'Rwanda';
  $region_language['RW'][1] = array('FR-EU', 'French');
  $region_language['RW'][2] = array('EN-EU', 'English');

  //San Marino
  $region_language['SM'] = array();
  $region_language['SM'][0] = 'San Marino';
  $region_language['SM'][1] = array('EN-EU', 'English');


  //Sao Tome and Principe
  $region_language['ST'] = array();
  $region_language['ST'][0] = 'Sao Tome and Principe';
  $region_language['ST'][1] = array('EN-EU', 'English');


  //Saudi Arabia
  $region_language['SA'] = array();
  $region_language['SA'][0] = 'Saudi Arabia';
  $region_language['SA'][1] = array('EN-EU', 'English');


  //Senegal
  $region_language['SN'] = array();
  $region_language['SN'][0] = 'Senegal';
  $region_language['SN'][1] = array('FR-EU', 'French');
  $region_language['SN'][2] = array('EN-EU', 'English');

  //Serbia
  $region_language['RS'] = array();
  $region_language['RS'][0] = 'Serbia';
  $region_language['RS'][1] = array('EN-EU', 'English');


  //Seychelles
  $region_language['SC'] = array();
  $region_language['SC'][0] = 'Seychelles';
  $region_language['SC'][1] = array('EN-EU', 'English');

  //Sierra Leone
  $region_language['SL'] = array();
  $region_language['SL'][0] = 'Sierra Leone';
  $region_language['SL'][1] = array('EN-EU', 'English');

  //Singapore
  $region_language['SG'] = array();
  $region_language['SG'][0] = 'Singapore';
  $region_language['SG'][1] = array('EN-SU', 'English');

  //Slovakia
  $region_language['SK'] = array();
  $region_language['SK'][0] = 'Slovakia';
  $region_language['SK'][1] = array('EN-EU', 'English');

  //Slovenia
  $region_language['SI'] = array();
  $region_language['SI'][0] = 'Slovenia';
  $region_language['SI'][1] = array('EN-EU', 'English');

  //Somalia
  $region_language['SO'] = array();
  $region_language['SO'][0] = 'Somalia';
  $region_language['SO'][1] = array('EN-EU', 'English');

  //South Africa
  $region_language['ZA'] = array();
  $region_language['ZA'][0] = 'South Africa';
  $region_language['ZA'][1] = array('EN-EU', 'English');

  //Spain
  $region_language['ES'] = array();
  $region_language['ES'][0] = 'Spain';
  $region_language['ES'][1] = array('ES-EU', 'Spanish');

  //Sri Lanka
  $region_language['LK'] = array();
  $region_language['LK'][0] = 'Sri Lanka';
  $region_language['LK'][1] = array('EN-SU', 'English');

  //Sudan
  $region_language['SD'] = array();
  $region_language['SD'][0] = 'Sudan';
  $region_language['SD'][1] = array('EN-EU', 'English');

  //Swaziland
  $region_language['SZ'] = array();
  $region_language['SZ'][0] = 'Swaziland';
  $region_language['SZ'][1] = array('EN-EU', 'English');

  //Sweden
  $region_language['SE'] = array();
  $region_language['SE'][0] = 'Sweden';
  $region_language['SE'][1] = array('EN-EU', 'English');

  //Switzerland
  $region_language['CH'] = array();
  $region_language['CH'][0] = 'Switzerland';
  $region_language['CH'][1] = array('DE-EU', 'German');
  $region_language['CH'][2] = array('FR-EU', 'French');
  $region_language['CH'][3] = array('EN-EU', 'English');

  //Taiwan
  $region_language['TW'] = array();
  $region_language['TW'][0] = 'Taiwan';
  $region_language['TW'][1] = array('EN-SU', 'English');

  //Tajikistan
  $region_language['TJ'] = array();
  $region_language['TJ'][0] = 'Tajikistan';
  $region_language['TJ'][1] = array('EN-EU', 'English');

  //Tanzania
  $region_language['TZ'] = array();
  $region_language['TZ'][0] = 'Tanzania';
  $region_language['TZ'][1] = array('EN-EU', 'English');

  //Thailand
  $region_language['TH'] = array();
  $region_language['TH'][0] = 'Thailand';
  $region_language['TH'][1] = array('EN-SU', 'English');

  //Togo
  $region_language['TG'] = array();
  $region_language['TG'][0] = 'Togo';
  $region_language['TG'][1] = array('FR-EU', 'French');
  $region_language['TG'][2] = array('EN-EU', 'English');

  //Tunisia
  $region_language['TN'] = array();
  $region_language['TN'][0] = 'Tunisia';
  $region_language['TN'][1] = array('FR-EU', 'French');
  $region_language['TN'][2] = array('EN-EU', 'English');

  //Turkey
  $region_language['TR'] = array();
  $region_language['TR'][0] = 'Turkey';
  $region_language['TR'][1] = array('EN-EU', 'English');

  //Turkmenistan
  $region_language['TM'] = array();
  $region_language['TM'][0] = 'Turkmenistan';
  $region_language['TM'][1] = array('EN-EU', 'English');
  $region_language['TM'][2] = array('RU-RU', 'Russian');

  //Uganda
  $region_language['UG'] = array();
  $region_language['UG'][0] = 'Uganda';
  $region_language['UG'][1] = array('EN-EU', 'English');

  //Ukraine
  $region_language['UA'] = array();
  $region_language['UA'][0] = 'Ukraine';
  $region_language['UA'][1] = array('RU-RU', 'Russian');
  $region_language['UA'][2] = array('EN-EU', 'English');

  //United Arab Emirates
  $region_language['AE'] = array();
  $region_language['AE'][0] = 'United Arab Emirates';
  $region_language['AE'][1] = array('EN-EU', 'English');

  //United Kingdom
  $region_language['GB'] = array();
  $region_language['GB'][0] = 'United Kingdom';
  $region_language['GB'][1] = array('EN-EU', 'English');

  //United States
  $region_language['US'] = array();
  $region_language['US'][0] = 'United States';
  $region_language['US'][1] = array('EN-US', 'English');

  //Uzbekistan
  $region_language['UZ'] = array();
  $region_language['UZ'][0] = 'Uzbekistan';
  $region_language['UZ'][1] = array('RU-RU', 'Russian');
  $region_language['UZ'][2] = array('EN-EU', 'English');

  //Vatican City (Holy See)
  $region_language['VA'] = array();
  $region_language['VA'][0] = 'Vatican City (Holy See)';
  $region_language['VA'][1] = array('EN-EU', 'English');

  //Venezuela
  $region_language['VE'] = array();
  $region_language['VE'][0] = 'Venezuela';
  $region_language['VE'][1] = array('ES-LN', 'Spanish');

  //Vietnam
  $region_language['VN'] = array();
  $region_language['VN'][0] = 'Vietnam';
  $region_language['VN'][1] = array('EN-SU', 'English');
  $region_language['VN'][2] = array('CN-ZH', 'Chinese');

  //Yemen
  $region_language['YE'] = array();
  $region_language['YE'][0] = 'Yemen';
  $region_language['YE'][1] = array('EN-EU', 'English');

  //Zambia
  $region_language['ZM'] = array();
  $region_language['ZM'][0] = 'Zambia';
  $region_language['ZM'][1] = array('EN-EU', 'English');

  //Zimbabwe
  $region_language['ZW'] = array();
  $region_language['ZW'][0] = 'Zimbabwe';
  $region_language['ZW'][1] = array('EN-EU', 'English');

  return $region_language;

}
