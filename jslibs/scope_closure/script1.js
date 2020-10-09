function showHelp(help) {
  document.getElementById("help").innerHTML = help;
}

const helpText = [
  {'id': 'email', 'help': 'Your e-mail address'},
  {'id': 'name', 'help': 'Your full name'},
  {'id': 'age', 'help': 'Your age (you must be over 16)'}
];

function setupHelpCase1() {
  for (var i = 0; i < helpText.length; i++) {
    var item = helpText[i];
    document.getElementById(item.id).onfocus = function () {
      showHelp(item.help);
    }
  }
}

function makeHelpFunc(help) {
  return function () {
    showHelp(help);
  }
}

function setupHelpCase2() {
  for (var i = 0; i < helpText.length; i++) {
    var item = helpText[i];
    document.getElementById(item.id).onfocus = makeHelpFunc(item.help);
  }
}
