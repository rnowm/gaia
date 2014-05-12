'use strict';

mocha.globals(['NfcManagerUtils']);

/* globals MocksHelper, NfcManagerUtils, NDEF, NfcUtils */

require('/shared/test/unit/mocks/mock_moz_ndefrecord.js');
require('/shared/js/nfc_utils.js');
requireApp('system/js/nfc_manager_utils.js');

var mocksForNfcUtils = new MocksHelper([
  'MozNDEFRecord'
]).init();

suite('NfcManagerUtils tests', function() {

  mocksForNfcUtils.attachTestHelpers();

  suite('Helper functions tests', function() {
    test('parseMAC()', function() {
      assert.isNull(NfcManagerUtils.parseMAC(null));
      assert.isNull(NfcManagerUtils.parseMAC(''));
      assert.isNull(NfcManagerUtils.parseMAC('lorem ipsum'));
      assert.isNull(NfcManagerUtils.parseMAC('ab:cd:ef:gh:ij:kl'));
      assert.isNull(NfcManagerUtils.parseMAC('ab:cd:ef:12:34'));
      assert.isNull(NfcManagerUtils.parseMAC(':::::'));
      assert.isNull(NfcManagerUtils.parseMAC('0:12:12:12:12:12'));

      assert.isNotNull(NfcManagerUtils.parseMAC('01:23:45:67:89:AB'));
      assert.isNotNull(NfcManagerUtils.parseMAC('01:23:45:67:89:ab'));
    });

    test('validateCPS()', function() {
      assert.isFalse(NfcManagerUtils.validateCPS(-1));
      assert.isFalse(NfcManagerUtils.validateCPS(4));

      for (var cps = 0; cps <= 3; cps += 1) {
        assert.isTrue(NfcManagerUtils.validateCPS(cps));
      }
    });
  });

  suite('encodeHandoverRequest() tests', function() {

    var btMac;
    var stubMathRandom;

    setup(function() {
      btMac = '00:0D:44:E7:95:AB';

      stubMathRandom = this.sinon.stub(Math, 'random');
      stubMathRandom.onCall(0).returns(0.1234567);
      stubMathRandom.onCall(1).returns(0.7654321);
    });

    teardown(function() {
      stubMathRandom.restore();
    });

    test('Encodes CPS', function() {
      var records, cps;

      cps = 0;
      records = NfcManagerUtils.encodeHandoverRequest(btMac, cps);
      assert.equal(records[0].payload[13], cps);

      cps = 1;
      records = NfcManagerUtils.encodeHandoverRequest(btMac, cps);
      assert.equal(records[0].payload[13], cps);
    });

    test('Encodes MAC', function() {
      var records = NfcManagerUtils.encodeHandoverRequest(btMac, 1);

      var mac = '';
      for (var m = 7; m >= 2; m -= 1) {
        var n = records[1].payload[m];
        mac += (n < 0x10 ? '0' : '' ) + n.toString(16);
        if (m > 2) {
          mac += ':';
        }
      }

      assert.equal(mac.toUpperCase(), btMac);
    });

    test('Encodes random number for collision detection', function() {
      var request = NfcManagerUtils.encodeHandoverRequest(btMac, 1);

      assert.isTrue(stubMathRandom.calledTwice);

      var rndMSB = request[0].payload[6];
      var rndLSB = request[0].payload[7];

      assert.equal(rndMSB, 31);
      assert.equal(rndLSB, 195);
    });

    test('Returns null when MAC invalid', function() {
      var invalidMAC = 'AB:CD';
      var records = NfcManagerUtils.encodeHandoverRequest(invalidMAC, 1);
      assert.isNull(records);
    });

    test('Returns null when CPS invalid', function() {
      var invalidCPS = 5;
      var records = NfcManagerUtils.encodeHandoverRequest(btMac, invalidCPS);
      assert.isNull(records);
    });
  });

  suite('encodeHandoverSelect() tests', function() {

    var btMac;
    var btName;
    var recordsDefault;

    setup(function() {
      /*
       * The following NDEF message contains a static handover request
       * from a Motorola UE Mini Boom. The NDEF message encodes the
       * MAC address(00:0D:44:E7:95:AB) and its name (UE MINI BOOM).
       */
      btMac = '00:0D:44:E7:95:AB';
      btName = NfcUtils.fromUTF8('UE MINI BOOM');

      recordsDefault = [{
        tnf: NDEF.TNF_WELL_KNOWN,
        type: new Uint8Array([72, 115]),
        id: new Uint8Array(),
        payload: new Uint8Array([18, 209, 2, 4, 97, 99, 1, 1, 48, 0])
      }, {
        tnf: NDEF.TNF_MIME_MEDIA,
        type: new Uint8Array([97, 112, 112, 108, 105, 99, 97, 116, 105,
                              111, 110, 47, 118, 110, 100, 46, 98, 108, 117,
                              101, 116, 111, 111, 116, 104, 46, 101, 112,
                              46, 111, 111, 98]),
        id: new Uint8Array([48]),
        payload: new Uint8Array([22, 0, 171, 149, 231, 68, 13, 0, 13, 9, 85,
                                 69, 32, 77, 73, 78, 73, 32, 66, 79,
                                 79, 77])
      }];
    });

    test('With MAC, CPS and device name', function() {
      var records = NfcManagerUtils.encodeHandoverSelect(btMac, 1, btName);
      assert.deepEqual(records, recordsDefault);
    });

    test('With MAC and CPS only', function() {
      recordsDefault[1].payload =
        new Uint8Array([8, 0, 171, 149, 231, 68, 13, 0]);
      var records = NfcManagerUtils.encodeHandoverSelect(btMac, 1);
      assert.deepEqual(records, recordsDefault);
    });

    test('Encodes CPS', function() {
      var records, cps;

      cps = 0;
      records = NfcManagerUtils.encodeHandoverSelect(btMac, cps, btName);
      assert.equal(records[0].payload[6], cps);

      cps = 2;
      records = NfcManagerUtils.encodeHandoverSelect(btMac, cps, btName);
      assert.equal(records[0].payload[6], cps);
    });

    test('Returns null when MAC invalid', function() {
      var invalidMAC = 'AB:CD';
      var records = NfcManagerUtils.encodeHandoverSelect(invalidMAC, 1);
      assert.isNull(records);
    });

    test('Returns null when CPS invalid', function() {
      var invalidCPS = 5;
      var records = NfcManagerUtils.encodeHandoverSelect(btMac, invalidCPS);
      assert.isNull(records);
    });
  });

});
