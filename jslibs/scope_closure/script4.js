function apiReq() {
  return function makeReq() {
    $.ajax({
      url: "http://localhost",
      method: "GET"
    })
  }
}

function setup() {
  const btn = document.getElementById("btn4");

}


setup();