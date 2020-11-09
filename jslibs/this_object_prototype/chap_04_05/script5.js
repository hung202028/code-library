const b1 = Object.create({});
const b2 = {};
const b3 = Object.create(null);


const objA = {
  p1: 1,
  p2: 2,

  f1: function () {
    return "f1"
  }
};
const objB = Object.create(objA);
objB.p3 = 10;
objB.p4 = 11;


// skip inherit props
const res1 = [];
for (let p in objB) {
  if (!objB.hasOwnProperty(p)) continue;
  res1.push(p);
}

// skip func
const res2 = [];
for (let p in objB) {
  if (typeof objB[p] === "function") continue;
  res2.push(p);
}


Object.defineProperty(objA, "p3", {enumerable: false});

// An array of the nnames of enumerable props of obj (array of string)
const names1 = Object.keys(objA);
// An array o then names of both enumerable and non-enumerable props (string)
const names2 = Object.getOwnPropertyNames(objA);
const names3 = Reflect.ownKeys(objA);
const names4 = Object.getOwnPropertySymbols(objA);

// Object.assign overrides props
// merge: copy missed props
function merge(target, ...sources) {
  for (const src of sources) {
    for (const p of Object.getOwnPropertyNames(src)) {
      if (target && (!target.hasOwnProperty(p))) {
        target[p] = src[p];
      }
    }
  }

  return target;
}

const objA1 = Object.assign({x: 1}, {x: 2, y: 3}, {x: 3, y: 5, z: 4});
const objA2 = merge({x: 1}, {x: 2, y: 3}, {x: 3, y: 5, z: 4});
