function Controller() {
  this.errors = [];
}

Controller.prototype.log = function (title, message) {
  console.log(`${title}: ${message}`);
}

Controller.prototype.success = function (message) {
  this.log("Success", message);
}

Controller.prototype.failure = function (message) {
  this.log("Error", message);
  this.errors.push(message);
}

function LoginForm() {
  Controller.call(this);
}

LoginForm.prototype = Object.create(Controller.prototype);
LoginForm.prototype.getUser = function () {
  return document.getElementById("username").value;
}
LoginForm.prototype.getPassword = function () {
  return document.getElementById("password").value;
}
LoginForm.prototype.validate = function () {
  const username = this.getUser();
  const password = this.getPassword();

  if (!(username && password)) {
    this.failure("Empty username and password");
  }

  if (password.length < 5) {
    this.failure("Password must be 5+ character");
  }

  return true;
}

LoginForm.prototype.error = function (err) {
  Controller.prototype.failure.call(this, err);
  return false;
}

function Authen(loginForm) {
  Controller.call(this);
  this.login = loginForm;
}

Authen.prototype = Object.create(Controller.prototype);
Authen.prototype.authen = function () {
  const username = this.login.getUser();
  const password = this.login.getPassword();

  const success = this.success.bind(this);
  const failure = this.failure.bind(this);
  const xhr = new XMLHttpRequest();
  xhr.open("post", "http://localhost:5000/auth");
  xhr.setRequestHeader("Content-Type", "application/json");
  xhr.onreadystatechange = function () {
    if (this.readyState === XMLHttpRequest.DONE && this.status === 200) {
      const result = xhr.response;
      console.log("Result: ", result);
      success();
    } else {
      failure();
    }
  };

  xhr.send({"username": username, "password": password});
}

Authen.prototype.success = function () {
  Controller.prototype.success.call(this, "Authenticated!");
}

Authen.prototype.failure = function () {
  Controller.prototype.failure.call(this, "Authentication FAILED!");
}

const form = new LoginForm();
const auth = new Authen(form);

function doSubmit() {
  auth.authen();
}


