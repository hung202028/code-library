const Foo = {
  init: function (ssn, name) {
    this.name = name;
    this.ssn = ssn;
  },

  id: function () {
    return "objA.id" + this.ssn + "-" + this.name;
  }
};


const Bar = Object.create(Foo);
Bar.log = function (message) {
  const id = this.id();
  console.log("Bar.ID: ", id);
  console.log("Bar.Message: ", message);
};

const b1 = Object.create(Bar);
b1.init("111", "B1");

const b2 = Object.create(Bar);
b2.init("222", "B2");

b1.log("Message B1");
b2.log("Message B2");

Bar.log = function (message) {
  const id = this.id();
  console.log("Bar.log Modified: ", id);
}

console.log("===================");
b1.log("Message B1");
b2.log("Message B2");




