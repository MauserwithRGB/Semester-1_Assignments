// Exercise 3: Car Rental System using abstract base class

#include <iostream>
#include <string.h>

// Forward declarations
class Vehicle;
class RentalSystem;

// Abstract Base Class
class Vehicle
{
	protected:
		int carId;
		char* brand;
		char* model;
		bool available;
		
	public:
		// Constructor
		Vehicle()
		{
			carId = 0;
			brand = NULL;
			model = NULL;
			available = true;
		}
		
		// Destructor
		virtual ~Vehicle()
		{
			if (brand != NULL)
			{
				delete[] brand;
			}
			if (model != NULL)
			{
				delete[] model;
			}
		}
		
		// Pure virtual functions
		virtual bool isAvailable() = 0;
		virtual void rent() = 0;
		virtual void returnVehicle() = 0;
		virtual void displayInfo() = 0;
};

// Derived Class: Car
class Car : public Vehicle
{
	public:
		// Constructor
		Car(int id, const char* b, const char* m)
		{
			carId = id;
			
			brand = new char[strlen(b) + 1];
			strcpy(brand, b);
			
			model = new char[strlen(m) + 1];
			strcpy(model, m);
			
			available = true;
		}
		
		// Implementation of isAvailable
		bool isAvailable()
		{
			return available;
		}
		
		// Implementation of rent
		void rent()
		{
			if (available)
			{
				available = false;
				std::cout << "\nCar ID " << carId << " (" << brand << " " << model << ") has been rented.";
			}
			else
			{
				std::cout << "\nCar ID " << carId << " is not available!";
			}
		}
		
		// Implementation of returnVehicle
		void returnVehicle()
		{
			if (!available)
			{
				available = true;
				std::cout << "\nCar ID " << carId << " (" << brand << " " << model << ") has been returned.";
			}
			else
			{
				std::cout << "\nCar ID " << carId << " was not rented!";
			}
		}
		
		// Display car information
		void displayInfo()
		{
			std::cout << "\nCar ID: " << carId;
			std::cout << "\nBrand: " << brand;
			std::cout << "\nModel: " << model;
			std::cout << "\nStatus: " << (available ? "Available" : "Rented");
		}
		
		int getId()
		{
			return carId;
		}
};

// Rental System Class
class RentalSystem
{
	public:
		void rentVehicle(Vehicle* v)
		{
			if (v->isAvailable())
			{
				v->rent();
			}
			else
			{
				std::cout << "\nVehicle is not available for rent!";
			}
		}
		
		void returnVehicle(Vehicle* v)
		{
			v->returnVehicle();
		}
		
		void checkAvailability(Vehicle* v)
		{
			if (v->isAvailable())
			{
				std::cout << "\nVehicle is available for rent.";
			}
			else
			{
				std::cout << "\nVehicle is currently rented.";
			}
		}
};

// Customer Class
class Customer
{
	private:
		char* name;
		int customerId;
		
	public:
		// Constructor
		Customer(int id, const char* n)
		{
			customerId = id;
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
		
		// Destructor
		~Customer()
		{
			delete[] name;
		}
		
		void rentVehicle(Vehicle* v, RentalSystem* rs)
		{
			std::cout << "\n\nCustomer " << name << " (ID: " << customerId << ") wants to rent a vehicle.";
			rs->rentVehicle(v);
		}
		
		void returnVehicle(Vehicle* v, RentalSystem* rs)
		{
			std::cout << "\n\nCustomer " << name << " (ID: " << customerId << ") is returning a vehicle.";
			rs->returnVehicle(v);
		}
};

int main()
{
	std::cout << "=== Car Rental System ===\n";
	
	// Creating array of pointers to Vehicle (base class)
	Vehicle* vehicles[5];
	
	// Dynamic memory allocation for Car objects
	vehicles[0] = new Car(101, "Toyota", "Corolla");
	vehicles[1] = new Car(102, "Honda", "Civic");
	vehicles[2] = new Car(103, "Suzuki", "Alto");
	vehicles[3] = new Car(104, "Hyundai", "Elantra");
	vehicles[4] = new Car(105, "Kia", "Sportage");
	
	// Displaying all vehicles
	std::cout << "\n--- Available Vehicles ---";
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n";
		vehicles[i]->displayInfo();
	}
	
	// Creating rental system
	RentalSystem rentalSystem;
	
	// Creating customers
	Customer customer1(1, "Ali Ahmed");
	Customer customer2(2, "Sara Khan");
	
	// Customer 1 rents a vehicle
	customer1.rentVehicle(vehicles[0], &rentalSystem);
	
	// Customer 2 rents a vehicle
	customer2.rentVehicle(vehicles[1], &rentalSystem);
	
	// Display updated status
	std::cout << "\n\n--- Updated Vehicle Status ---";
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n";
		vehicles[i]->displayInfo();
	}
	
	// Customer 1 returns vehicle
	customer1.returnVehicle(vehicles[0], &rentalSystem);
	
	// Customer 2 tries to rent already rented vehicle
	Customer customer3(3, "Hassan Raza");
	customer3.rentVehicle(vehicles[1], &rentalSystem);
	
	// Display final status
	std::cout << "\n\n--- Final Vehicle Status ---";
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n";
		vehicles[i]->displayInfo();
	}
	
	// Cleaning up dynamically allocated memory
	for (int i = 0; i < 5; i++)
	{
		delete vehicles[i];
	}
	
	std::cout << "\n";
	return 0;
}
