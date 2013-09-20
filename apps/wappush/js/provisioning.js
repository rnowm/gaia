/* -*- Mode: js; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- /
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */

'use strict';

 var ProvisioningScreen = {
  /** Close button node */
  closeButton: null,
  /** Validate button node */
  validateButton: null,
  /** Cancel button node */
  dismisslButton: null,
  /** Confirm dialog node */
  confirmDialog: null,
  /** Title of the message, usually holds the sender's number */
  title: null,

  init: function ps_init() {
    var params = this.deserializeParameters(window.location.search);

    // Retrieve the various page elements
    this.closeButton = document.getElementById('close');
    this.validateButton = document.getElementById('validate');
    this.dismissButton = document.getElementById('dismiss');

    this.title = document.getElementById('title');

    this.closeButton.addEventListener('click', this.onclose);
    this.validateButton.addEventListener('click', this.onvalidate);
    this.dismissButton.addEventListener('click', this.ondismiss);

    // Populate the message
    this.title.innerHTML = params.sender;
  },

  onvalidate: function wps_onvalidate() {
//    this.confirmDialog.hidden = false;
    window.close();
  },

  ondismiss: function wps_ondismiss() {
    window.close();
  },

  /**
   * Closes the attention screen
   */
  onclose: function wps_onclose() {
    window.close();
  },

  /**
   * Retrieves the parameters from an URL and forms an object with them
   *
   * @param {String} input A string holding the parameters attached to an URL.
   *
   * @return {Object} An object built using the parameters.
   */
   deserializeParameters: function wpm_deserializeParameters(input) {
     var rparams = /([^?=&]+)(?:=([^&]*))?/g;
     var parsed = {};

     input.replace(rparams, function($0, $1, $2) {
       parsed[$1] = decodeURIComponent($2);
     });

     return parsed;
   }
};
