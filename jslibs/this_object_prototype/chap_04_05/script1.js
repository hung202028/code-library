const objA = {
  a: 1,
  b: 2
};

Object.defineProperty(objA, "a", {
  writable: false,
  configurable: true,
  enumerable: true
});

objA.a = 1000; // value will not change
console.log("objA.a", objA.a);

// Now change writeable
Object.defineProperty(objA, "a", {writable: true});
objA.a = 1111;
console.log("objA.a", objA.a);


const objB = {
  a: 1,
  b: 2
};

// Cannot re-define when configurable is false
Object.defineProperty(objB, "b", {
  writable: false,
  configurable: false,
  enumerable: true
});


delete objB.b; // cannot delete object property
console.log("objB.b", objB.b);


const objC = {
  a: 1
};

Object.preventExtensions(objC); // Prevent adding new props
objC.b = 2000;
console.log("objC.b", objC.b);


const objD = {a: 1};
console.log("\"a\" in objD", "a" in objD);
console.log("objD hasOwnProperty a", objD.hasOwnProperty("a"));


const objE = {};
Object.defineProperties(objE, {
  a: {
    value: "objE.a_value",
    enumerable: true
  },

  b: {
    value: "objE.b_value",
    enumerable: true
  },

  c: {
    value: "objE.c_value",
    enumerable: false
  }
});

// will not show c
for (const key in objE) {
  console.log("objE.key - objE.value", key, "-", objE[key]);
}

// will get all props
console.log(Object.getOwnPropertyNames(objE)) // return array





