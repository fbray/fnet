<?php
// $Id$
?>

<!DOCTYPE html >
<html xmlns="http://www.w3.org/1999/xhtml"
      xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0"
      dir="<?php print $language->dir; ?>">
<head>
  <?php print $head; ?>
  <base href='<?php print $url ?>'/>
  <title><?php print $print_title; ?></title>
  <?php print $css; ?>
  <style>
    /* Layout
------------------------- */
    #print_view .edocs_page_wrapper, #print_view .edocs_page_wrapper_first, #print_view .edocs_page_wrapper_last {
      clear: both; }

    #print_view .node-type-edoc {
      /* Offsets */ }
    #print_view .node-type-edoc .wrapper-container {
      width: 100%; }
    #print_view .node-type-edoc .row {
      width: 100%; }
    #print_view .node-type-edoc .one.column, #print_view .node-type-edoc .one.columns {
      width: 4.66666666667%; }
    #print_view .node-type-edoc .two.columns {
      width: 13.3333333333%; }
    #print_view .node-type-edoc .three.columns {
      width: 22%; }
    #print_view .node-type-edoc .four.columns {
      width: 30.6666666667%; }
    #print_view .node-type-edoc .five.columns {
      width: 39.3333333333%; }
    #print_view .node-type-edoc .six.columns {
      width: 48%; }
    #print_view .node-type-edoc .seven.columns {
      width: 56.6666666667%; }
    #print_view .node-type-edoc .eight.columns {
      width: 65.3333333333%; }
    #print_view .node-type-edoc .nine.columns {
      width: 74.0%; }
    #print_view .node-type-edoc .ten.columns {
      width: 82.6666666667%; }
    #print_view .node-type-edoc .eleven.columns {
      width: 91.3333333333%; }
    #print_view .node-type-edoc .twelve.columns {
      width: 100%;
      margin-left: 0; }
    #print_view .node-type-edoc .one-third.column {
      width: 30.6666666667%; }
    #print_view .node-type-edoc .two-thirds.column {
      width: 65.3333333333%; }
    #print_view .node-type-edoc .one-half.column {
      width: 48%; }
    #print_view .node-type-edoc .offset-by-one.column,
    #print_view .node-type-edoc .offset-by-one.columns {
      margin-left: 8.66666666667%; }
    #print_view .node-type-edoc .offset-by-two.column,
    #print_view .node-type-edoc .offset-by-two.columns {
      margin-left: 17.3333333333%; }
    #print_view .node-type-edoc .offset-by-three.column,
    #print_view .node-type-edoc .offset-by-three.columns {
      margin-left: 26%; }
    #print_view .node-type-edoc .offset-by-four.column,
    #print_view .node-type-edoc .offset-by-four.columns {
      margin-left: 34.6666666667%; }
    #print_view .node-type-edoc .offset-by-five.column,
    #print_view .node-type-edoc .offset-by-five.columns {
      margin-left: 43.3333333333%; }
    #print_view .node-type-edoc .offset-by-six.column,
    #print_view .node-type-edoc .offset-by-six.columns {
      margin-left: 52%; }
    #print_view .node-type-edoc .offset-by-seven.column,
    #print_view .node-type-edoc .offset-by-seven.columns {
      margin-left: 60.6666666667%; }
    #print_view .node-type-edoc .offset-by-eight.column,
    #print_view .node-type-edoc .offset-by-eight.columns {
      margin-left: 69.3333333333%; }
    #print_view .node-type-edoc .offset-by-nine.column,
    #print_view .node-type-edoc .offset-by-nine.columns {
      margin-left: 78.0%; }
    #print_view .node-type-edoc .offset-by-ten.column,
    #print_view .node-type-edoc .offset-by-ten.columns {
      margin-left: 86.6666666667%; }
    #print_view .node-type-edoc .offset-by-eleven.column,
    #print_view .node-type-edoc .offset-by-eleven.columns {
      margin-left: 95.3333333333%; }
    #print_view .node-type-edoc .offset-by-one-third.column,
    #print_view .node-type-edoc .offset-by-one-third.columns {
      margin-left: 34.6666666667%; }
    #print_view .node-type-edoc .offset-by-two-thirds.column,
    #print_view .node-type-edoc .offset-by-two-thirds.columns {
      margin-left: 69.3333333333%; }
    #print_view .node-type-edoc .offset-by-one-half.column,
    #print_view .node-type-edoc .offset-by-one-half.columns {
      margin-left: 52%; }

    /* Typography
    ------------------------- */
    #print_view .node-type-edoc h1 {
      font-size: 1.5em; }
    #print_view .node-type-edoc h2 {
      font-size: 1.35em;
      color: #293F6a;
      font-style: italic; }
    #print_view .node-type-edoc h3 {
      font-size: 1.25em; }
    #print_view .node-type-edoc h4 {
      font-size: 1.2em; }
    #print_view .node-type-edoc h5 {
      font-size: 1.15em; }
    #print_view .node-type-edoc h6 {
      font-size: 1.1em; }
    #print_view .node-type-edoc a {
      font-family: "Arial", Helvetica, sans-serif;
      font-size: .875em;
      font-weight: bold;
      text-decoration: none;
      color: #336699; }
    #print_view .node-type-edoc a:hover {
      color: #9ca1a7;
      text-decoration: none; }
    #print_view .node-type-edoc .body-copy {
      font-size: .938;
      line-height: 1.35em;
      font-weight: normal; }
    #print_view .node-type-edoc .overview-frame {
      position: relative;
      border: thin solid #293F6a;
      box-sizing: border-box;
      width: 100%; }
    #print_view .node-type-edoc .overview-frame p {
      font-family: "Arial", Helvetica, sans-serif;
      color: #000;
      font-style: italic;
      font-size: .938em;
      line-height: 1.3;
      margin: 8px 18px; }
    #print_view .node-type-edoc .overview-frame img {
      max-width: 100%;
      height: auto;
      position: absolute;
      left: 0;
      bottom: 0; }
    #print_view .node-type-edoc .body-copy {
      font-size: .938;
      line-height: 1.35em;
      font-weight: normal; }
    #print_view .node-type-edoc .overview-frame {
      position: relative;
      border: thin solid #293F6a;
      box-sizing: border-box;
      width: 100%; }
    #print_view .node-type-edoc .overview-frame p {
      font-family: "Arial", Helvetica, sans-serif;
      color: #000;
      font-style: italic;
      font-size: .938em;
      line-height: 1.3;
      margin: 8px 18px; }
    #print_view .node-type-edoc .overview-frame img {
      max-width: 100%;
      height: auto;
      position: absolute;
      left: 0;
      bottom: 0; }
    #print_view .node-type-edoc .headline {
      font-size: 1.125em;
      color: #293F6a;
      line-height: 1.25;
      font-weight: bold;
      text-align: left;
      margin: 24px 0px 3px 0px; }
    #print_view .node-type-edoc .subhead {
      font-weight: bold;
      font-size: 1.0em;
      line-height: 1.25;
      color: #293F6a;
      margin: 0px 0px 5px 0px; }
    #print_view .node-type-edoc .caption {
      font-size: .813em;
      line-height: 1.25;
      font-weight: normal;
      margin: 8px 0px 0px 0px; }
    #print_view .node-type-edoc table {
      width: 100%; }
    #print_view .node-type-edoc th {
      font-size: 1.0em;
      font-weight: bold;
      color: #FFF;
      background-color: #293F6a;
      padding: 8px 8px 8px 5px;
      border-bottom: medium solid #FFF;
      text-align: left;
      vertical-align: middle; }
    #print_view .node-type-edoc tr, #print_view .node-type-edoc td {
      font-size: .875em;
      line-height: 1.15em;
      font-weight: normal;
      padding: 5px; }
    #print_view .node-type-edoc .gray {
      color: #000;
      background-color: #e2e2e2;
      border-bottom: thin solid #000;
      border-right: thin solid #000;
      border-left: thin solid #000; }
    #print_view .node-type-edoc .dark-gray {
      color: #000;
      background-color: #9ca1a7;
      border-bottom: thin solid #000;
      border-right: thin solid #000;
      border-left: thin solid #000; }
    #print_view .node-type-edoc .blue {
      color: #FFF;
      background-color: #293F6a;
      border-bottom: thin solid #000;
      border-right: thin solid #000;
      border-left: thin solid #000; }
    #print_view .node-type-edoc .blank {
      color: #000;
      border: none; }
    #print_view .node-type-edoc .body-list {
      width: 95%; }
    #print_view .node-type-edoc .body-list ul {
      list-style: disc outside none;
      margin: 0px 0px 0px 18px; }
    #print_view .node-type-edoc .body-list ul ul {
      list-style: disc outside none;
      margin: 0px 0px 0px -20px; }
    #print_view .node-type-edoc .body-list ul ol {
      list-style: decimal outside none;
      margin: 0px 0px 0px -20px; }
    #print_view .node-type-edoc .body-list ol {
      list-style: decimal outside none;
      margin: 0px 0px 0px -20px; }
    #print_view .node-type-edoc .body-list ol ol {
      list-style: lower-roman outside none;
      margin: 0px 0px 0px -20px; }
    #print_view .node-type-edoc .body-list ol ul {
      list-style: disc outside none;
      margin: 0px 0px 0px 18px; }
    #print_view .node-type-edoc .body-list ol {
      list-style: decimal outside none;
      margin: 0px 0px 0px -20px; }
    #print_view .node-type-edoc .body-list ol ol {
      list-style: lower-roman outside none;
      margin: 0px 0px 0px -20px; }
    #print_view .node-type-edoc .body-list ol ul {
      list-style: disc outside none;
      margin: 0px 0px 0px 18px; }
    #print_view .node-type-edoc .body-list li {
      font-family: "Arial", Helvetica, sans-serif;
      font-size: 1em;
      line-height: 1.5;
      padding-left: 0px; }
    #print_view .node-type-edoc .body-list li::after {
      margin-bottom: 5px; }
    #print_view .node-type-edoc .overview-frame ol {
      padding: 0px 18px;
      display: block;
      list-style-position: outside; }
    #print_view .node-type-edoc .overview-frame ol li {
      font-size: .938em;
      line-height: 1.25;
      font-style: italic;
      margin: 10px 5px -10px 10px;
      padding-left: 0px; }
    #print_view .node-type-edoc .edoc_TOC {
      width: 100%; }
    #print_view .node-type-edoc .TOC-copy {
      font-family: "Arial", Helvetica, sans-serif;
      font-size: .875em;
      line-height: 1.5;
      font-style: italic;
      color: #000;
      display: inline-block; }
    #print_view .node-type-edoc .edoc_TOC ul {
      display: inline-block;
      list-style: none outside none; }
    #print_view .node-type-edoc .edoc_TOC ul li::before {
      content: "\00BB";
      color: #fdb924;
      font-weight: bold;
      list-style-image: none;
      list-style-type: none;
      margin-left: 10px;
      margin-right: 8px; }
    #print_view .node-type-edoc .edoc_TOC ul > p {
      font-family: "Arial", Helvetica, sans-serif;
      color: #293F6a;
      font-weight: bold;
      width: 250px;
      border: 1px solid #fdb924;
      display: block;
      text-align: center;
      padding: 8px 0px; }

    /* Extras
    ------------------------- */
    #print_view .node-type-edoc .fnet-box {
      border: 1pt solid #293F6a; }
    #print_view .node-type-edoc hr.style-one {
      border: 0;
      border-bottom: 1px dashed #9ca1a7;
      background: #e2e2e2; }
    #print_view .node-type-edoc hr.style-two {
      display: none; }
    #print_view .node-type-edoc .print-view-divider {
      border-bottom: thin solid #000;
      width: 100%;
      margin: 12px 0px 24px 0px; }

    #print_view .node-type-edoc .focus-content {
      width: 100%; }
    #print_view .node-type-edoc .focus-content-title {
      font-size: 1.125em;
      line-height: 1;
      font-weight: bold;
      color: #293F6a;
      margin: 0px 0px 18px 0px;
      border-bottom: thin solid #293F6a;
      padding-bottom: 3px; }
    #print_view .node-type-edoc .focus-content-subhead {
      font-size: .813em;
      line-height: .813em;
      text-transform: uppercase;
      color: #888;
      margin: 3px 0px 0px 0x;
      letter-spacing: 1px; }
    #print_view .node-type-edoc .focus-content-copy {
      font-size: 1em;
      line-height: 1;
      margin: -18px 0px 20px 0px; }
  </style>
</head>
<body class="<?php print $classes; ?>">
<!-- print--node--edoc.tpl.php -->
<?php print $edoc_brand_header; ?>
<div id="print_view">
  <?php if (isset($edoc_type)): ?>
  <div class="edocs_type_display">| <?php print t($edoc_type);?> |</div>
  <?php endif; ?>
  <div class="edocs_page_header">
    <div style="clear:both;">&nbsp;</div>
  </div>
  <?php if ($print_logo): ?>
    <div class="print-logo"><?php print $print_logo; ?></div>
  <?php endif; ?>
  <div class="ds_title"><?php print html_entity_decode($title); ?></div>
  <div class="ds_content">

    <?php print $content; ?></div>

  <div class="ds_footer">
    <?php print $ds_footer; ?>
  </div>
  <div class="print-footer"><?php print theme('print_footer'); ?></div>
  <hr class="print-hr"/>
</div>
<!-- end of print--node--edoc.tpl.php -->
</body>
</html>
