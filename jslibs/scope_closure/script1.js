function showHelp(help) {
  document.getElementById("help").innerHTML = help;
}

const helpText = [
  {'id': 'email', 'help': 'Your e-mail address'},
  {'id': 'name', 'help': 'Your full name'},
  {'id': 'age', 'help': 'Your age (you must be over 16)'}
];

/*
Three closures have been created by the loop, but each one shares the same
single lexical environment, which has a variable with changing values (item).
This is because the variable item is declared with var and thus has function
scope due to hoisting.
* */
function setupHelpCase1() {
  for (var i = 0; i < helpText.length; i++) {
    var item = helpText[i];
    document.getElementById(item.id).onfocus = function () {
      showHelp(item.help);
    }
  }
}


// creates a new lexical environment for each callback
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

function setupHelpCase3() {
  for (var i = 0; i < helpText.length; i++) {
    let item = helpText[i];
    document.getElementById(item.id).onfocus = function () {
      showHelp(item.help);
    }
  }
}

function setupHelpCase4() {
  for (var i = 0; i < helpText.length; i++) {
    (function () {
      var item = helpText[i];
      document.getElementById(item.id).onfocus = function () {
        showHelp(item.help);
      }
    })(); // Immediate event listener attachment
  }
}

// Using forEach
function setupHelpCase5() {
  helpText.forEach(function (text) {
    document.getElementById(text.id).onfocus = function () {
      showHelp(text.help);
    }
  })
}

function lookupStudent(studentId) {
  const data = [
    {id: 14, name: "Kyle"},
    {id: 73, name: "Suzy"},
    {id: 112, name: "Frank"},
    {id: 6, name: "Sarah"}
  ];

  return function (greeting) {
    const student = data.find(student => student.id === studentId);
    console.log(`[${greeting}: ${student.name}]`);
  }
}

const obj = [lookupStudent(112), lookupStudent(6)];

