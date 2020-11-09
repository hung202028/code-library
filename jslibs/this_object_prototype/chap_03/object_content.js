/*

Even when you declare a function expression as part of the object literal,
that function doesn't matically belong more to the object - there are still
just multiple references to the same function object.

* */

var myObject = {
    foo: function () {
        console.log("myObject.foo()")
    }
}
