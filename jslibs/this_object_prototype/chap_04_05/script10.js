const LoginController = {
  errors: [],

  getUser: function () {
    return document.getElementById("username").value;
  },

  getPassword: function () {
    return document.getElementById("password").value;
  },

  validate: function () {
    const username = this.getUser();
    const password = this.getPassword();

    if (!(username && password)) {
      return false;
    }

    if (username.length < 5) {
      return false;
    }

    return true;
  },

  showDialog: function (title, msg) {
    console.log(`Alert[${title}: ${msg}]`);
  },

  success: function (message) {
    this.showDialog("Success", message);
  },

  failure: function (message) {
    this.showDialog("Failure", message);
    this.errors.push(message);
  }
}

const AuthController = Object.create(LoginController);
AuthController.errors = [];
AuthController.server = function (url, data) {
  return $.ajax({
    url: url,
    data: data,
    method: "POST"
  })
}
AuthController.success = function () {
  this.showDialog("Authenticated", "Login OK");
}
AuthController.failure = function () {
  this.showDialog("Failure", "Login failed");
}
AuthController.authen = function () {
  const username = this.getUser();
  const password = this.getPassword();

  if (this.validate()) {
    const data = {username: username, password: password};
    this.server("http://localhost:5000/auth", data)
      .then(this.success.bind(this))
      .fail(this.failure.bind(this))
  } else {
    this.showDialog("Validation failed", "Validation failed");
  }
}

const auth = Object.create(AuthController);

function doSubmit() {
  auth.authen();
}
