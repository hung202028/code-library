// OLOO style
const Widget = {
  init: function (width, height) {
    this.width = width || 50;
    this.height = height || 50;
    this.elem = {name: ""}
  },

  render: function (where) {
    const position = where + (this.width * this.height) / 2;
    console.log(`Render: ${this.elem.name} at: ${position}`);
  }
};

const Button = Object.create(Widget);
Button.initBtn = function (width, height, label) {
  this.init(width, height);
  this.label = label || "BTN";
  this.elem.name = this.label;
}
Button.renderBtn = function (where) {
  this.render(where);
  this.elem.click = this.onClick.bind(this);
}
Button.onClick = function (event) {
  console.log(`Clicked on button: ${this.label}`);
};

const b1 = Object.create(Button);
const b2 = Object.create(Button);
b1.initBtn(10, 20, "b1");
b2.initBtn(10, 30, "b2");


