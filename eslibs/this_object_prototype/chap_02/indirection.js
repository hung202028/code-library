function foo() {
    console.log("Indirection", this.a);
}

var a = "Ops, global!";

var o = {a: 3, foo: foo};
var p = {a: 4};

o.foo();
(p.foo = o.foo)();

/*
The result value of assignment p.foo = o.foo is a reference to just the
underlying function object. As such, the effective call-site is just foo(),
not p.foo() or o.foo(). Per the rules mentioned earlier, the "default binding"
rule applied.
*/

