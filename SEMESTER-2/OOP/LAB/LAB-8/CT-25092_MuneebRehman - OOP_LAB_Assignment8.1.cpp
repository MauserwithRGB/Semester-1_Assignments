#include <iostream>
#include <string>

struct VehicleData
{
    std::string type, make, model, colour, year, totalMileage;
};

class Vehicle
{
protected:
    std::string type, make, model, colour, year, totalMileage;
public:
    Vehicle(const VehicleData& d)
        : type(d.type), make(d.make), model(d.model),
          colour(d.colour), year(d.year), totalMileage(d.totalMileage) {}
    virtual void display() = 0;
    virtual ~Vehicle() {}
};

class GasVehicle : virtual public Vehicle
{
protected:
    float fuelCapacity;
public:
    GasVehicle(float fC, const VehicleData& d)
        : Vehicle(d), fuelCapacity(fC) {}
};

class ElectricVehicle : virtual public Vehicle
{
protected:
    float energyStorage;
public:
    ElectricVehicle(float eS, const VehicleData& d)
        : Vehicle(d), energyStorage(eS) {}
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle
{
protected:
    float maxWeight;
    int totalWheels;
    float length;
public:
    HeavyVehicle(float mW, int tW, float l, float fC, float eS, const VehicleData& d)
        : Vehicle(d), GasVehicle(fC, d), ElectricVehicle(eS, d),
          maxWeight(mW), totalWheels(tW), length(l) {}
};

class HighPerformance : public GasVehicle
{
protected:
    float horsePwr;
    float topSpeed;
public:
    HighPerformance(float hp, float ts, float fC, const VehicleData& d)
        : Vehicle(d), GasVehicle(fC, d), horsePwr(hp), topSpeed(ts) {}
};

class SportsCar : public HighPerformance
{
    std::string gearbox;
    std::string driveSystem;
public:
    SportsCar(std::string gb, std::string ds, float hp, float ts, float fC, const VehicleData& d)
        : Vehicle(d), HighPerformance(hp, ts, fC, d), gearbox(gb), driveSystem(ds) {}
    void display() override {
        std::cout << "=== Sports Car ===\n"
                  << "Type: "        << type       << "\n"
                  << "Make: "        << make       << "\n"
                  << "Model: "       << model      << "\n"
                  << "Colour: "      << colour     << "\n"
                  << "Year: "        << year       << "\n"
                  << "Mileage: "     << totalMileage << "km\n"
                  << "Fuel Cap: "    << fuelCapacity << "L\n"
                  << "Horsepower: "  << horsePwr   << "hp\n"
                  << "Top Speed: "   << topSpeed   << "km/h\n"
                  << "Gearbox: "     << gearbox    << "\n"
                  << "Drive System: "<< driveSystem << "\n";
    }
};

class ConstructionTruck : public HeavyVehicle
{
    std::string cargo;
public:
    ConstructionTruck(std::string cg, float mW, int tW, float l, float fC, float eS, const VehicleData& d)
        : Vehicle(d), HeavyVehicle(mW, tW, l, fC, eS, d), cargo(cg) {}
    void display() override {
        std::cout << "=== Construction Truck ===\n"
                  << "Type: "        << type       << "\n"
                  << "Make: "        << make       << "\n"
                  << "Model: "       << model      << "\n"
                  << "Colour: "      << colour     << "\n"
                  << "Year: "        << year       << "\n"
                  << "Mileage: "     << totalMileage << "km\n"
                  << "Fuel Cap: "    << fuelCapacity << "L\n"
                  << "Energy Store: "<< energyStorage << "kWh\n"
                  << "Max Weight: "  << maxWeight  << "kg\n"
                  << "Wheels: "      << totalWheels << "\n"
                  << "Length: "      << length     << "m\n"
                  << "Cargo: "       << cargo      << "\n";
    }
};

class Bus : public HeavyVehicle
{
    int totalSeats;
public:
    Bus(int ts, float mW, int tW, float l, float fC, float eS, const VehicleData& d)
        : Vehicle(d), HeavyVehicle(mW, tW, l, fC, eS, d), totalSeats(ts) {}
    void display() override {
        std::cout << "=== Bus ===\n"
                  << "Type: "        << type       << "\n"
                  << "Make: "        << make       << "\n"
                  << "Model: "       << model      << "\n"
                  << "Colour: "      << colour     << "\n"
                  << "Year: "        << year       << "\n"
                  << "Mileage: "     << totalMileage << "km\n"
                  << "Fuel Cap: "    << fuelCapacity << "L\n"
                  << "Energy Store: "<< energyStorage << "kWh\n"
                  << "Max Weight: "  << maxWeight  << "kg\n"
                  << "Wheels: "      << totalWheels << "\n"
                  << "Length: "      << length     << "m\n"
                  << "Total Seats: " << totalSeats << "\n";
    }
};

int main()
{
    VehicleData d{"Heavy", "Mercedes", "Citaro", "White", "2022", "0"};
    Bus bus(50, 18000.0f, 6, 12.0f, 200.0f, 100.0f, d);
    bus.display();
}