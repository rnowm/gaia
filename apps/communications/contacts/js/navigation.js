'use strict';

function navigationStack(currentView) {
  var transitions = {
    'right-left': {
      forwards: {
        next: 'appGoLeftIn'
      },
      backwards: {
        current: 'appGoLeftBackOut'
      }
    },
    'popup': {
      forwards: {
        next: 'appGoUpIn'
      },
      backwards: {
        current: 'appGoUpBackOut'
      }
    },
    'goDeeper': {
      forwards: {
        current: 'appGoDeeperOut',
        next: 'appGoDeeperIn'
      },
      backwards: {
        current: 'appGoDeeperBackOut',
        next: 'appGoDeeperBackIn'
      }
    }
  };

  var _currentView = currentView;
  var stack = [];

  stack.push({view: currentView, transition: 'popup'});

  var waitForAnimation = function ng_waitForAnimation(view, callback) {
    if (!callback)
      return;

    view.addEventListener('animationend', function ng_onAnimationEnd() {
      view.removeEventListener('animationend', ng_onAnimationEnd);
      setTimeout(callback, 0);
    });
  };

  this.go = function go(nextView, transition) {
    if (_currentView === nextView)
      return;

    // Remove items that match nextView from the stack to prevent duplicates.
    stack = stack.filter(function(item) {
      return item.view != nextView;
    });

    var current = document.getElementById(_currentView);
    if (transitions[transition].backwards.next) {
      current.classList.remove(transitions[transition].backwards.next);
    }
    if (transitions[transition].forwards.current) {
      current.classList.add(transitions[transition].forwards.current);
    }
    var next = document.getElementById(nextView);
    if (transitions[transition].backwards.current) {
      next.classList.remove(transitions[transition].backwards.current);
    }
    if (transitions[transition].forwards.next) {
      next.classList.add(transitions[transition].forwards.next);
    }
    stack.push({ view: nextView, transition: transition});
    next.style.zIndex = stack.length;
    _currentView = nextView;
  };

  this.back = function back(callback) {
    if (stack.length < 2) {
      if (typeof callback === 'function') {
        setTimeout(callback, 0);
      }
      return;
    }

    var currentView = stack.pop();
    var current = document.getElementById(currentView.view);
    var nextView = stack[stack.length - 1];
    var transition = currentView.transition;
    if (transitions[transition].forwards.next) {
      current.classList.remove(transitions[transition].forwards.next);
    }
    if (transitions[transition].backwards.current) {
      current.classList.add(transitions[transition].backwards.current);
      current.addEventListener('animationend',
        function ng_onCurrentBackwards() {
          current.removeEventListener('animationend', ng_onCurrentBackwards);
          current.classList.remove(transitions[transition].backwards.current);
        }
      );
    }
    var next = document.getElementById(nextView.view);
    if (transitions[transition].forwards.current) {
      next.classList.remove(transitions[transition].forwards.current);
    }
    if (transitions[transition].backwards.next) {
      next.classList.add(transitions[transition].backwards.next);
      next.addEventListener('animationend', function ng_onNextBackwards() {
        next.removeEventListener('animationend', ng_onNextBackwards);
        next.classList.remove(transitions[transition].backwards.next);
      });
    }
    waitForAnimation(current, callback);
    _currentView = nextView.view;
  };

  this.home = function home(callback) {
    if (stack.length < 2) {
      if (typeof callback === 'function') {
        setTimeout(callback, 0);
      }
      return;
    }

    while (stack.length > 1) {
      this.back(callback);
    }
  };

  this.currentView = function currentView() {
    return _currentView != null ? _currentView : '';
  };
}
