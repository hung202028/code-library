function implicitBinding() {
    console.log("ImplicitBinding:", this.a);
}

var obj = {
    a: 1000,
    func: implicitBinding
};

obj.func(); // this.a synonymous to obj.a


// call chain
var obj1 = {
    a: 42,
    func: implicitBinding
};

var obj2 = {
    a: 10,
    obj1: obj1
};

obj2.obj1.func(); // 42


// implicitly lost

/* Even though "bar" appears to be a reference to obj.func, in fact, it's
*  really just another reference to "implicitBinding" itself. Moreover, the
*  call-site is what matters, and the call-site is: bar(), which is a plain,
*  undecorated all and thus "default binding" rule is applies.
* */
var bar = obj.func;
bar();

function doFn(func) {
    func();
}

doFn(obj.func);
setTimeout(obj.func, 2000);