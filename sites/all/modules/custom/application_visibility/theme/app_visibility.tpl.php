<?php
// $Id$

/**
 * @file
 * Template file for the Application visibility app
 *
 */
?>
<div id="pages">
  <form id="app-visibility" action="#">
    <div>
      <h3>List Applications</h3>
      <section id="page-1">
        <ledgend>List 10 widely used applications in your business (on premise,
          cloud-hosted, or SaaS).*
        </ledgend>
        <table>
          <thead>
          <tr>
            <td colspan="2" style="text-align: center;"><span
                id="message"></span></td>
          </tr>
          <tr class="even">
            <td>#</td>
            <td>Applications</td>
          </tr>
          </thead>
          <tbody>

          <tr class="odd">
            <td>1.&nbsp;</td>
            <td><input type="text" name="application-1" id="application-1"
                       size="60"></td>
          </tr>
          <tr class="even">
            <td>2.&nbsp;</td>
            <td><input type="text" name="application-2" id="application-2"
                       size="60"></td>
          </tr>
          <tr class="odd">
            <td>3.&nbsp;</td>
            <td><input type="text" name="application-3" id="application-3"
                       size="60"></td>
          </tr>
          <tr class="even">
            <td>4.&nbsp;</td>
            <td><input type="text" name="application-4" id="application-4"
                       size="60"></td>
          </tr>
          <tr class="odd">
            <td>5.&nbsp;</td>
            <td><input type="text" name="application-5" id="application-5"
                       size="60"></td>
          </tr>
          <tr class="even">
            <td>6.&nbsp;</td>
            <td><input type="text" name="application-6" id="application-6"
                       size="60"></td>
          </tr>
          <tr class="odd">
            <td>7.&nbsp;</td>
            <td><input type="text" name="application-7" id="application-7"
                       size="60"></td>
          </tr>
          <tr class="even">
            <td>8.&nbsp;</td>
            <td><input type="text" name="application-8" id="application-8"
                       size="60"></td>
          </tr>
          <tr class="odd">
            <td>9.&nbsp;</td>
            <td><input type="text" name="application-9" id="application-9"
                       size="60"></td>
          </tr>
          <tr class="even">
            <td>10.&nbsp;</td>
            <td><input type="text" name="application-10" id="application-10"
                       size="60"></td>
          </tr>
          </tbody>
        </table>
        <p>*Your data will remain anonymous</p>
      </section>
      <h3>Identify Problems</h3>
      <section id="page-2">
        <ledgend>Rate your ability to identify problems*</ledgend>
        <table>
          <thead>
          <tr>
            <td colspan="5" style="text-align: center;"><span
                id="message2"></span></td>
          </tr>
          <tr>
            <td>#</td>
            <td>Applications</td>
            <td>I know about<br>the issue first</td>
            <td>I find about<br>problems when a<br>user calls</td>
            <td>I have no idea<br><span style="font-size: small">This is a cloud<br>application, maybe even<br>a shadow IT project</span>
            </td>
          </tr>
          </thead>
          <tbody>
          <tr id="prob-row-1" class="odd">
            <td>1.</td>
            <td><span id="app-prob-1"></span></td>
            <td><input type="radio" name="prob-1" value="1"></td>
            <td><input type="radio" name="prob-1" value="2"></td>
            <td><input type="radio" name="prob-1" value="3"></td>
          </tr>
          <tr id="prob-row-2" class="even">
            <td>2.</td>
            <td><span id="app-prob-2"></span></td>
            <td><input type="radio" name="prob-2" value="1"></td>
            <td><input type="radio" name="prob-2" value="2"></td>
            <td><input type="radio" name="prob-2" value="3"></td>
          </tr>
          <tr id="prob-row-3" class="odd">
            <td>3.</td>
            <td><span id="app-prob-3"></span></td>
            <td><input type="radio" name="prob-3" value="1"></td>
            <td><input type="radio" name="prob-3" value="2"></td>
            <td><input type="radio" name="prob-3" value="3"></td>
          </tr>
          <tr id="prob-row-4" class="even">
            <td>4.</td>
            <td><span id="app-prob-4"></span></td>
            <td><input type="radio" name="prob-4" value="1"></td>
            <td><input type="radio" name="prob-4" value="2"></td>
            <td><input type="radio" name="prob-4" value="3"></td>
          </tr>
          <tr id="prob-row-5" class="odd">
            <td>5.</td>
            <td><span id="app-prob-5"></span></td>
            <td><input type="radio" name="prob-5" value="1"></td>
            <td><input type="radio" name="prob-5" value="2"></td>
            <td><input type="radio" name="prob-5" value="3"></td>
          </tr>
          <tr id="prob-row-6" class="even">
            <td>6.</td>
            <td><span id="app-prob-6"></span></td>
            <td><input type="radio" name="prob-6" value="1"></td>
            <td><input type="radio" name="prob-6" value="2"></td>
            <td><input type="radio" name="prob-6" value="3"></td>
          </tr>
          <tr id="prob-row-7" class="odd">
            <td>7.</td>
            <td><span id="app-prob-7"></span></td>
            <td><input type="radio" name="prob-7" value="1"></td>
            <td><input type="radio" name="prob-7" value="2"></td>
            <td><input type="radio" name="prob-7" value="3"></td>
          </tr>
          <tr id="prob-row-8" class="even">
            <td>8.</td>
            <td><span id="app-prob-8"></span></td>
            <td><input type="radio" name="prob-8" value="1"></td>
            <td><input type="radio" name="prob-8" value="2"></td>
            <td><input type="radio" name="prob-8" value="3"></td>
          </tr>
          <tr id="prob-row-9" class="odd">
            <td>9.</td>
            <td><span id="app-prob-9"></span></td>
            <td><input type="radio" name="prob-9" value="1"></td>
            <td><input type="radio" name="prob-9" value="2"></td>
            <td><input type="radio" name="prob-9" value="3"></td>
          </tr>
          <tr id="prob-row-10" class="even">
            <td>10.</td>
            <td><span id="app-prob-10"></span></td>
            <td><input type="radio" name="prob-10" value="1"></td>
            <td><input type="radio" name="prob-10" value="2"></td>
            <td><input type="radio" name="prob-10" value="3"></td>
          </tr>
          </tbody>
        </table>
        <p>*Your data will remain anonymous</p>
      </section>
      <h3>Rate Importance</h3>
      <section>
        <ledgend>Is this application Mission Critical?*</ledgend>
        <table>
          <thead>
          <tr>
            <td colspan="4" style="text-align: center;"><span
                id="message3"></span></td>
          </tr>
          <tr>
            <td>#</td>
            <td>Application</td>
            <td>Yes</td>
            <td>No</td>
          </tr>
          </thead>
          <tbody>
          <tr id="crit-row-1">
            <td>1.</td>
            <td><span id="app-crit-1"></span></td>
            <td><input type="radio" name="crit-1" value="5"></td>
            <td><input type="radio" name="crit-1" value="0"></td>
          </tr>
          <tr id="crit-row-2">
            <td>2.</td>
            <td><span id="app-crit-2"></span></td>
            <td><input type="radio" name="crit-2" value="5"></td>
            <td><input type="radio" name="crit-2" value="0"></td>
          </tr>
          <tr id="crit-row-3">
            <td>3.</td>
            <td><span id="app-crit-3"></span></td>
            <td><input type="radio" name="crit-3" value="5"></td>
            <td><input type="radio" name="crit-3" value="0"></td>
          </tr>
          <tr id="crit-row-4">
            <td>4.</td>
            <td><span id="app-crit-4"></span></td>
            <td><input type="radio" name="crit-4" value="5"></td>
            <td><input type="radio" name="crit-4" value="0"></td>
          </tr>
          <tr id="crit-row-5">
            <td>5.</td>
            <td><span id="app-crit-5"></span></td>
            <td><input type="radio" name="crit-5" value="5"></td>
            <td><input type="radio" name="crit-5" value="0"></td>
          </tr>
          <tr id="crit-row-6">
            <td>6.</td>
            <td><span id="app-crit-6"></span></td>
            <td><input type="radio" name="crit-6" value="5"></td>
            <td><input type="radio" name="crit-6" value="0"></td>
          </tr>
          <tr id="crit-row-7">
            <td>7.</td>
            <td><span id="app-crit-7"></span></td>
            <td><input type="radio" name="crit-7" value="5"></td>
            <td><input type="radio" name="crit-7" value="0"></td>
          </tr>
          <tr id="crit-row-8">
            <td>8.</td>
            <td><span id="app-crit-8"></span></td>
            <td><input type="radio" name="crit-8" value="5"></td>
            <td><input type="radio" name="crit-8" value="0"></td>
          </tr>
          <tr id="crit-row-9">
            <td>9.</td>
            <td><span id="app-crit-9"></span></td>
            <td><input type="radio" name="crit-9" value="5"></td>
            <td><input type="radio" name="crit-9" value="0"></td>
          </tr>
          <tr id="crit-row-10">
            <td>10.</td>
            <td><span id="app-crit-10"></span></td>
            <td><input type="radio" name="crit-10" value="5"></td>
            <td><input type="radio" name="crit-10" value="0"></td>
          </tr>
          </tbody>
        </table>
        <p>*Your data will remain anonymous</p>
      </section>
      <h3>Results</h3>
      <section>
        <div id="results"></div>
        <div id="results1"><h2>Congratulations, you are seen as a resource to
            the business!</h2>

          <p>See how TruView&trade; Live can make your life easier by monitoring
            your entire network including all your apps.</p>
        </div>
        <div id="results2"><h2>Hmm&hellip; could be doing more?</h2>

          <p>See how TruView&trade; Live gives you visibility to your entire
            network including all apps, making it esy for you to identify the
            source of any problems!</p>
        </div>
        <div id="results3"><h2>You need a plan how to stay ahead of
            problems.</h2>

          <p>See how TruView&trade; Live gives you visibility to monitor all
            your apps, so you can identify problems before your users are
            affected!</p>
        </div>
      </section>
    </div>
  </form>
</div>
