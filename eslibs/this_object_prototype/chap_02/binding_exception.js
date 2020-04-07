function bindingException(mark) {
    let msg = "BindingException: ";
    if (mark) {
        msg = "BindingException - " + mark + ": ";
    }

    console.log(msg, this.a, this.b);
}

function showVars(a, b) {
    console.log("ShowVars", a, b);
}

var a = 2;
var b = 3;

bindingException.call(null, "aaa");
showVars.apply(null, [20, 30]);

/*
There is a slight hidden danger in always using "null" when you dont care about
the "this" binding. If you ever use that against a function call(for instance,
a third-party library function that you dont control) and that function does
make a "this" reference, the "default binding" rule means it might inadvertently
reference(or worse, mutate!) the "global object".
Obviously, such a pitfall can lead to a variety of bugs that are very difficult
to diagnose and track down.
*/


// Safer this by creating DMZ object

var dmz = Object.create(null);
showVars.apply(dmz, [20, 30]);