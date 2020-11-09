function manageClickEvents(btn) {
  var clickHanders = [];

  return function listener(func) {
    if (func) {
      const handler = function onClick(evt) {
        func(evt);
      };
      clickHanders.push(handler);
      btn.addEventListener("click", handler);
    } else {
      for (let handler of clickHanders) {
        btn.removeEventListener("click", handler);
      }
      clickHanders = [];
    }
  }
}

const btn1 = document.getElementById("btn1");
const btn1Manager = manageClickEvents(btn1);
btn1Manager(function checkout(evt) {
  evt && evt.preventDefault();
  console.log("BTN1[Clicked: checkout]");
});
btn1Manager(function trackAction(evt) {
  evt && evt.preventDefault();
  console.log("BTN1[Submited: track_action]");
});

const btn2 = document.getElementById("btn2");
btn2.addEventListener("click", function () {
  console.log("Removed all handlers of btn1");
  btn1Manager(); // from now click btn1 will not show log
})
