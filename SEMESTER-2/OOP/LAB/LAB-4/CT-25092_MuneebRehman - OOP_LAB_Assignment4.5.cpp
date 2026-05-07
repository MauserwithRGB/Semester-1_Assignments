// Exercise 5: Hotel Mercato rent calculation system

#include <iostream>
#include <string.h>

class HotelRent
{
	private:
		char* customerName;
		int numberOfDays;
		const float dailyRate;
		float totalRent;
		
		void calculateRent()
		{
			if (numberOfDays > 7)
			{
				totalRent = (numberOfDays - 1) * dailyRate;
			}
			else
			{
				totalRent = numberOfDays * dailyRate;
			}
		}
		
	public:
		HotelRent() : dailyRate(1000.85)
		{
			customerName = NULL;
			numberOfDays = 0;
			totalRent = 0.0;
		}
		
		~HotelRent()
		{
			if (customerName != NULL)
			{
				delete[] customerName;
			}
		}
		
		void inputDetails()
		{
			char tempName[100];
			
			std::cout << "Enter customer name: ";
			std::cin.getline(tempName, 100);
			
			customerName = new char[strlen(tempName) + 1];
			strcpy(customerName, tempName);
			
			std::cout << "Enter number of days stayed: ";
			std::cin >> numberOfDays;
			
			calculateRent();
		}
		
		void displayDetails() const
		{
			std::cout << "\n\n--- Hotel Mercato Bill ---";
			std::cout << "\nCustomer Name: " << customerName;
			std::cout << "\nDays: " << numberOfDays;
			std::cout << "\nRent: " << totalRent << " PKR";
			
			if (numberOfDays > 7)
			{
				std::cout << "\n(Discount applied: 1 day free)";
			}
			std::cout << "\n";
		}
};

int main()
{
	HotelRent customer;
	
	std::cout << "=== Hotel Mercato Rent Calculation System ===\n\n";
	
	customer.inputDetails();
	customer.displayDetails();
	
	return 0;
}