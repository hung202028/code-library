/*
When a function is called with "new" in front of it, the following things are
happen automatically:

1. A brand-new object is created.
2. The newly created object is [[Prototype]] linked.
3. The newly created object is set as "this" binding for that function call.
4. Unless the function returns it own alternate object, the new-invoked function
   call will automatically return the newly constructed object.
*/

function newBinding(value) {
    this.a = value;
}

var bar = new newBinding(2);
console.log("BarNewBinding: ", bar.a);