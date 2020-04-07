// Adding named properties doesn't change the "length" of the array

var myArray = [2, "three", 4];
console.log("Before add prop, myArray.length", myArray.length);

myArray["bar"] = "foo";
console.log("After add prop, myArray.length", myArray.length);
console.log("myArray.bar", myArray["bar"], myArray.bar);

/* Becarefull!!
If you try to add a named property to an array, but the property name looks like
a number, it will end up instead as a numeric index, and thus, modify the
array contents.
* */

myArray["3"] = "five";
console.log("myArray[3], myarray.length", myArray[3], myArray.length);


function anotherFunction() { }
var anotherObject = {};
var anotherArray = [];

var obj1 = {
    a: 2,
    b: 3,

    func: anotherFunction,
    o: anotherObject,
    arr: anotherArray
};

var obj2 = Object.assign({}, obj1);
