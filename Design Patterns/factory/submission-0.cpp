class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    // Write your code here
public:
    CarFactory() {
        // default constructor
    }
    Vehicle* createVehicle() override {
        return new Car{};
    }
};

class BikeFactory : public VehicleFactory {
    // Write your code here
    Vehicle* createVehicle() override {
        return new Bike{};
    }
};

class TruckFactory : public VehicleFactory {
    // Write your code here
    Vehicle* createVehicle() override {
        return new Truck{};
    }
};
