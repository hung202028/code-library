function Vehicle() {
  this.engines = 4;
}

Vehicle.prototype.ignition = function () {
  console.log("Turning on my engine.");
};
Vehicle.prototype.drive = function () {
  this.ignition();
  console.log("Steering and moving forward!");
};

function Car() {
  var car = new Vehicle();

  car.wheels = 4;

  var vehDrive = car.drive;
  car.drive = function () {
    vehDrive.call(this);
    console.log("Behavior in CAR called");
  }

  return car;
};

const obj = Car();
obj.drive();

