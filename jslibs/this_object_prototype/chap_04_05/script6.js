function Widget(width, height) {
  this.width = width;
  this.height = height;
  this.elem = {
    id: null,
    name: null,
    className: null
  }
}

Widget.prototype.render = function (where) {
  console.log(`Render widget:
    name=${this.elem.name},
    width=${this.width}, 
    height=${this.height},
    location=${where}`)
}

function Button(width, height, label) {
  Widget.call(this, width, height);
  this.elem.name = label;
}

Button.prototype = Object.create(Widget.prototype);
Button.prototype.render = function (where) {
  Widget.prototype.render.call(this, where);
  this.elem.click = this.onClick.bind(this);
};

Button.prototype.onClick = function (event) {
  const message = event || "Click";
  console.log("Element clicked: ", this.elem.name, ", message: ", message);
}

const btn1 = new Button(10, 20, "OK");
const btn2 = new Button(10, 20, "Cancel");

