class Widget {
  constructor(width, height) {
    this.width = width;
    this.height = height;
    this.elem = {
      id: null,
      name: null
    }
  }

  render(where) {
    console.log(`Render widget:
    name=${this.elem.name},
    width=${this.width}, 
    height=${this.height},
    location=${where}`)
  }
};

class Button extends Widget {
  constructor(width, height, label) {
    super(width, height);
    this.label = label || "button";
    this.elem = {name: this.label};
  }

  render(where) {
    super.render(where);
    this.elem.click = this.onClick.bind(this);
  }

  onClick(event) {
    const msg = event || "default evt";
    console.log("Elem button clicked: ", this.elem.name, ", message: ", msg);
  }
};


const btn1 = new Button(10, 20, "BTN1");
const btn2 = new Button(10, 20, "BTN2");

const body = "<body>";
btn1.render(body);
btn2.render(body);


