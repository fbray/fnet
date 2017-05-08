<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="2.0"
                xmlns:html="http://www.w3.org/TR/REC-html40"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:output method="html" version="1.0" encoding="utf-8" indent="yes"/>

  <!-- Root template -->
  <xsl:template match="/">
    <html>
      <head>
        <title>Translations file</title>
          <style type="text/css">
              body {
              margin-top: 0;
              background-color: #fff;
              }

              body, td, th {
              font-family: arial,sans-serif;
              font-size: 13px;
              }

              h1 {
              font-size: 1.2em;
              margin-bottom: 1em;
              margin-top: 0;
              }

              h1 a {
              font-size: 0.8em;
              font-weight: normal;
              }

              h2 {
              font-weight: bold;
              font-size: 1.0em;
              color: #707070;
              padding-bottom: .5em;
              padding-top: 0px;
              margin: 1.5em 0 .5em 0;
              }

              h2 a {
              font-size: 1.0em;
              font-weight: normal;
              }

              p.sml {
              font-size: 0.8em;
              margin-top: 0;
              }

              a {
              color: #0000cc;
              text-decoration: none;
              }

              a:visited {
              color: #551a8b;
              }

              .header {
              font-weight: bold;
              font-size: 1.3em;
              margin-top: 30px;
              padding-left: 4px;
              border-bottom: 1px solid #dbe6de;
              }

              .data {
              border-collapse: collapse;
              border: 1px solid #BFC7D9;
              margin-top: 3px;
              width: 100%;
              _word-wrap: break-word;
              }

              .data td {
              border-bottom: 1px solid #BFC7D9;
              text-align: left;
              padding: 3px;
              }
          </style>
      </head>

      <!-- Body -->
      <body>

        <!-- Text and table -->
        <h1 id="head1">Translation map file:</h1>
        <xsl:call-template name="sitemapTable"/>
      </body>
    </html>
  </xsl:template>

  <!-- sitemapTable template -->
  <xsl:template name="sitemapTable">
    <table border="1" width="100%" class="data" id="table0">
      <tr class="header">
        <td>URL</td>
        <td>Node ID</td>
        <td>Languages</td>
      </tr>
      <xsl:apply-templates select="urlset/url">
      </xsl:apply-templates>
    </table>
  </xsl:template>

  <!-- sitemap:url template -->
  <xsl:template match="url">
    <tr>
      <td>
        <xsl:variable name="sitemapURL"><xsl:value-of select="loc"/></xsl:variable>
        <a href="{$sitemapURL}" target="_blank" ref="nofollow"><xsl:value-of select="$sitemapURL"></xsl:value-of></a>
      </td>
      <td><xsl:value-of select="nid"/></td>
      <td><xsl:value-of select="languages"/></td>
    </tr>
  </xsl:template>


</xsl:stylesheet>
