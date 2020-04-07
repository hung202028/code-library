function explicitBinding(mark) {
    if (!mark) {
        console.log("ExplicitBinding:", this.a);
    }
    else {
        console.log("ExplicitBinding - ", mark , ":", this.a);
    }
}

function explicitBindingAdd(something, mark) {
    let msg = "ExplicitBindingAdd:";
    if (mark) {
        msg = "ExplicitBindingAdd - " + mark + ":"
    }

    console.log(msg, this.a + something);
}

var obj = {
    a: 2,
    id: "obj_001"
};

explicitBinding.call(obj);

var bar = function (mark) {
    explicitBinding.call(obj, mark);
};

bar("bar");
setTimeout(bar, 2000, "bar_in_timeout");

// hard bound "bar" is no longer have its "this" overridden
bar.call(window, "window");

bar = function () {
    return explicitBindingAdd.apply(obj, arguments);
};

bar(3, "aaaa");

// API call context
function showElem(elem) {
    console.log("ShowElem: ", elem, this.id);
}

// use "obj" as "this" for showElem call
[1].forEach(showElem, obj);

