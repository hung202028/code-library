class Widget {
  constructor(width, height) {
    this.width = width;
    this.height = height;
    this.$elem = null;
  }

  render($where) {
    if (this.$elem) {
      this.$elem.css({
        width: this.width + " px",
        height: this.height + " px"
      }).appendTo($where);
    }
  }
}

class Button extends Widget {
  constructor(width, height, label) {
    super(width, height);
    this.label = label || "Default";
    this.$elem = $(" <button> ").text(this.label);
  }

  render($where) {
    super.render($where);
    this.$elem.click(this.onClick.bind(this));
  }

  onClick(evt) {
    console.log(`Button \"${this.label}\" clicked!`);
  }
}

class C {
  constructor() {
    this.num = Math.random();
  }

  rand() {
    console.log("Random: ", this.num);
  }
}

const c1 = new C();
const c2 = new C();

c1.rand();
C.prototype.rand = function () {
  console.log("Random: ", this.num * 1000);
}

c1.rand();
