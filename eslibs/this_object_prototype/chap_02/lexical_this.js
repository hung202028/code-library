/*
Normal function abide by the four rules we covered. But ES6 introduces a new
special kind of function that doesn't use these rules: the arrow-function.

Instead of using the four standard "this" rules, ES6 arrow-function adopt "this"
binding from the enclosing(function or global) scope.
* */

function arrowFunction() {
    return () => {
        // This here is lexically inherit from "arrowFunction()"
        console.log("Inside ArrowFunction", this.a);
    };
}

var obj1 = {a: "obj1_arrow_func"};
var obj2 = {a: "obj2_arrow_func"};
var bar = arrowFunction.call(obj1);
bar.call(obj2);

// The arrow-function created in "arrowFunction" lexically captures whatever
// "arrowFunction" 's "this" at its call-time. Since the "arrowFunction" was
// "this" bound to "obj1", "bar" will also be "this" bound to "obj1".


// A pattern for doing the same ES6 arrow-function
function selfPattern() {
    let self = this;

    return function () {
        console.log("SelfPattern", self.a);
    };
}

var obj3 = {a: "RUNNING!"};
selfPattern.call(obj3);