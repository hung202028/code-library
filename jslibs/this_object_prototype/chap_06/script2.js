class P {
  foo() {
    console.log("P.foo");
  }
}

class C extends P {
  foo() {
    super.foo();
  }
}

class D {
  foo() {
    console.log("D.foo");
  }
}


class E {
  foo: C.prototype.foo;
}

const e1 = new E();
e1.foo();
