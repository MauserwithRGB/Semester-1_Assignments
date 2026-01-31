// Employee class assignment            purpose: store employee data and calculate raises

#include <iostream>
#include <string>
#include <cstring>

class Employee
{
	public:
		char* firstName;
		std::string lastName;
		int monthlySalary;
		
		// Setter function to initialize the variables
		void setDetails(const char* fNameIN, std::string lNameIN, int salaryIN)
		{
			// Simple DMA allocation without checking for previous memory
			firstName = new char[20]; 
			strcpy(firstName, fNameIN);
			
			lastName = lNameIN;
			
			// Simple if-else for salary check
			if (salaryIN < 0)
			{
				monthlySalary = 0;
			}
			else
			{
				monthlySalary = salaryIN;
			}
		}
		
		// Simple Getters
		char* getFirstName()
		{
			return firstName;
		}
		
		std::string getLastName()
		{
			return lastName;
		}
		
		int getSalary()
		{
			return monthlySalary;
		}
		
		// Displaying yearly salary (Salary * 12)
		void displayYearly()
		{
			std::cout << "Yearly Salary: " << monthlySalary * 12 << std::endl;
		}
		
		// Adding 10% raise using basic math
		void giveRaise()
		{
			monthlySalary = monthlySalary + (monthlySalary * 0.1);
		}
};

int main()
{
	Employee emp1, emp2;
	
	// Setting data for two employees
	emp1.setDetails("Muneeb", "Rehman", 5000);
	emp2.setDetails("Ali", "Ahmed", 6000);
	
	std::cout << "Employee 1: " << emp1.getFirstName() << " " << emp1.getLastName() << std::endl;
	emp1.displayYearly();
	
	std::cout << "\nEmployee 2: " << emp2.getFirstName() << " " << emp2.getLastName() << std::endl;
	emp2.displayYearly();
	
	// Giving raise
	emp1.giveRaise();
	emp2.giveRaise();
	
	std::cout << "\n--- After 10% Raise ---" << std::endl;
	
	std::cout << "Employee 1: " << emp1.getFirstName() << " " << emp1.getLastName() << std::endl;
	emp1.displayYearly();
	
	std::cout << "\nEmployee 2: " << emp2.getFirstName() << " " << emp2.getLastName() << std::endl;
	emp2.displayYearly();
	
	return 0;
}