function defaultBinding() {
    console.log("DefaultBinding:", this.a);
}

function defaultBindingStrict() {
    "use strict"

    console.log("DefaultBinding with strict:", this.a);
}

var a = "GLOBAL VALUE";
defaultBinding();
//defaultBindingStrict();