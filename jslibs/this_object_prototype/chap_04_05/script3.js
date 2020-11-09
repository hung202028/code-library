/*
* Prototype: is mechanism by which javascript objects inherit from one another.
* The main purpose of prototype is to provide inheritent
* */


const objA = {
  f: function (message) {
    console.log("ObjA.f", message);
  }
};

const objB = Object.create(objA);
objB.f("message from objB");


function Person(first, last, age, gender, interests) {

  // property and method definitions
  this.name = {
    'first': first,
    'last': last
  };
  this.age = age;
  this.gender = gender;
  //...see link in summary above for full definition
};

const person1 = new Person('Bob', 'Smith', 32, 'male', ['music', 'skiing']);
console.log(person1.valueOf());

const persion2 = Object.create(person1);

function Foo(name) {
  this.name = name;
};

Foo.prototype.myName = function () {
  return this.name;
};

function Bar(name, label) {
  Foo.call(this, name);
  this.label = label;
};

Bar.prototype = Object.create(Foo.prototype);

// ES6+
//Object.setPrototypeOf(Bar.prototype, Foo.prototype);
Bar.prototype.myLabel = function () {
  return this.label;
};

const a = new Bar("Name A", "Label A");

Foo.prototype.myFunc = function () {
  return "This is my func from FOO prototype";
};

a.myFunc();





