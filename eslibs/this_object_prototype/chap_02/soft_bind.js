/*

It would be nice if there was a way to provide a different default for
"default binding" (not global or undefined), while still leaving the
function able to be manually this-bound via "implicit binding" or "explicit
binding" techniques

* */

if (!Function.prototype.softBind) {
    Function.prototype.softBind = function (obj) {
        var fn = this;

        // capture any curried params
        var curries = [].slice.call(arguments, 1);
        var bound = function () {
            return fn.apply(
                (!this || this === (window || global)) ? obj : this,
                curries.concat.apply(curries, arguments)
            );
        };

        bound.prototype = Object.create(fn.prototype);
        return bound;
    };
};

function foo() {
    console.log("FooSoftBing", this.name);
}

var obj  = {name: "obj"},
    obj2 = {name: "obj2"},
    obj3 = {name: "obj3"};

var fooObj = foo.softBind(obj);

fooObj();

obj2.foo = foo.softBind(obj);
obj2.foo();

fooObj.call(obj3);

setTimeout(obj2.foo, 2000); // fall back to soft binding