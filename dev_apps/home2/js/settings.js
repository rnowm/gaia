'use strict';

(function(exports) {

  function Settings() {
    this.done = document.getElementById('done');
    
    this.done.addEventListener('click', function() {
      window.close();
    });
  }

  Settings.prototype = {

    
  };

  exports.settings = new Settings();
  exports.settings.init();

}(window));
