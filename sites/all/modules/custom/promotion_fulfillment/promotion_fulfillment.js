/* $Id: promotion_fulfillment.js 4000 2012-09-21 22:08:05Z hslaught $ */

/**
 * Utility functions for inputs and things
 */

/**
 * Disable enter key on some of our form fields, else the AHAH submit responds
 * and adds more fields
 */
function disableEnterKey(e) {
  var key;
  if (window.event) {
    key = window.event.keyCode; //IE
  } else {
    key = e.which; //firefox
  }

  return (key != 13);
}

// Product category toggler
function promo_categories(show) {
  //$('#select_products_toggle a').preventDefault();
  if (show == 1) {
    $('.promo_fulfillment_choose_wrapper > fieldset').removeClass('collapsed');
  } else {
    $('.promo_fulfillment_choose_wrapper > fieldset').addClass('collapsed');
  }
}

// Ongoing calculation of remaining balance on promotion product selection
// page.
function changeRemainingBalance(id, priorSelection) {
  balanceValue = document.getElementById('edit-credit-total').value;
  startingBalance = parseFloat(balanceValue.substr(balanceValue.indexOf("$") + 1));

  // initialize workingBalance if not set
  if (typeof workingBalance === "undefined") {
    workingBalance = startingBalance;
  }

  priorAmountSelected = $('#' + id).data('priorstate');

  amountSelected = $('#' + id).val();
  // Get hidden form value for price
  itemValue = $('#' + id).parent().parent().find('input').eq(3).val();
  // Already added items don't count against the balance, credit balance those
  // items before adjusting for new selection
  if (typeof priorAmountSelected != "undefined") {
    workingBalance += itemValue * priorAmountSelected;
  }

  selectionCost = itemValue * amountSelected;

  if (selectionCost > workingBalance) {
    canAfford = Math.floor(workingBalance / itemValue);
    $('#' + id).val(canAfford);
    selectionCost = itemValue * canAfford;
    alert('You do not have enough remaining balance to select ' + amountSelected + ' of this product. Your selection has been adjusted to ' + canAfford + '.');
  }

  // Calculate new workingBalance from scratch
  workingBalance = startingBalance;
  $('.promo_fulfillment_choose_item select').each(function(idx, elmnt) {
    amountSelected = $(elmnt).val();
    $(elmnt).data('priorstate', amountSelected);

    // Get hidden form value for price
    itemValue = $(elmnt).parent().parent().find('input').eq(3).val();
    selectionCost = itemValue * amountSelected;
    workingBalance -= selectionCost;
  });

  if (workingBalance == 0) {
    alert("You have no balance remaining");
  }
  $('#edit-credit-available').val('$' + workingBalance.toFixed(2));
}

function allowIntOnly(id) {
  currentValue = $('#' + id).val();
  if (isNaN(currentValue) || currentValue < 1) {
    document.getElementById(id).value = 0;
    alert('Please enter a numeric value of 1 or more');
    document.getElementById(id).focus();
  }
}

// Simple float 2 currency formatter
function formatCurrency(id) {
  inputNumber = document.getElementById('edit-purchase-amount').value;
  cleanedNumber = inputNumber.match(/(\D*)([\d]*(\.\d{1,})?)\D?.*/)[2];
  document.getElementById('edit-purchase-amount').value = '$' + parseFloat(cleanedNumber).toFixed(2);
}

// Not 100% effective email address validator
function simpleEmailAddressChecker(id) {
  emailAddress = document.getElementById('edit-email');
  var regex = /^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\ ".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  if (!regex.test(emailAddress.value)) {
    alert('Please provide a valid email address');
    emailAddress.focus();
  }
}

// Since our initial form can take a while to submit (mostly because of Marketo
// submit), provide progress indicator on submit.click
function submitProgressIndicator(image) {
  $('#ajax-image-loader').show();
  $('body').fadeTo("fast", 0.5);
  return true;
}
