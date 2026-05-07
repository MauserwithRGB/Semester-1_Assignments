// Exercise 3: Friend class - Payroll accessing private members of Employee

#include <iostream>
#include <string.h>

class Employee; // Forward declaration

class Payroll
{
	public:
		// Function to update salary
		void updateSalary(Employee &emp, float newSalary);
		
		// Function to display payroll details
		void displayPayroll(Employee &emp);
		
		// Function to give increment
		void giveIncrement(Employee &emp, float percentage);
};

class Employee
{
	private:
		char* name;
		int id;
		char* designation;
		float salary;
		
	public:
		// Constructor
		Employee()
		{
			name = NULL;
			id = 0;
			designation = NULL;
			salary = 0.0;
		}
		
		// Destructor
		~Employee()
		{
			if (name != NULL)
			{
				delete[] name;
			}
			if (designation != NULL)
			{
				delete[] designation;
			}
		}
		
		// Function to set employee details
		void setDetails(const char* n, int empId, const char* desig, float sal)
		{
			if (name != NULL)
			{
				delete[] name;
			}
			name = new char[strlen(n) + 1];
			strcpy(name, n);
			
			id = empId;
			
			if (designation != NULL)
			{
				delete[] designation;
			}
			designation = new char[strlen(desig) + 1];
			strcpy(designation, desig);
			
			salary = sal;
		}
		
		// Display function
		void display()
		{
			std::cout << "\nName: " << name;
			std::cout << "\nID: " << id;
			std::cout << "\nDesignation: " << designation;
			std::cout << "\nSalary: " << salary << " PKR";
			std::cout << "\n";
		}
		
		// Declaring Payroll as friend class
		friend class Payroll;
};

// Implementing Payroll member functions
void Payroll::updateSalary(Employee &emp, float newSalary)
{
	emp.salary = newSalary; // accessing private member
	std::cout << "\nSalary updated successfully for " << emp.name << "!";
}

void Payroll::displayPayroll(Employee &emp)
{
	std::cout << "\n--- Payroll Details ---";
	std::cout << "\nEmployee Name: " << emp.name;
	std::cout << "\nEmployee ID: " << emp.id;
	std::cout << "\nDesignation: " << emp.designation;
	std::cout << "\nCurrent Salary: " << emp.salary << " PKR";
	std::cout << "\n";
}

void Payroll::giveIncrement(Employee &emp, float percentage)
{
	float increment = emp.salary * (percentage / 100.0);
	emp.salary = emp.salary + increment;
	std::cout << "\n" << percentage << "% increment given to " << emp.name;
	std::cout << "\nNew Salary: " << emp.salary << " PKR";
}

int main()
{
	std::cout << "=== Employee Payroll System (Friend Class) ===\n";
	
	// Creating employee objects
	Employee emp1;
	emp1.setDetails("Ahmed Ali", 101, "Software Engineer", 50000.0);
	
	Employee emp2;
	emp2.setDetails("Sara Khan", 102, "Project Manager", 80000.0);
	
	Employee emp3;
	emp3.setDetails("Hassan Raza", 103, "Junior Developer", 35000.0);
	
	// Displaying initial employee details
	std::cout << "\n--- Initial Employee Details ---";
	emp1.display();
	emp2.display();
	emp3.display();
	
	// Creating payroll object
	Payroll payroll;
	
	// Updating salaries using friend class
	std::cout << "\n\n--- Salary Updates ---";
	payroll.updateSalary(emp1, 55000.0);
	payroll.updateSalary(emp2, 85000.0);
	
	// Giving increment
	payroll.giveIncrement(emp3, 10);
	
	// Displaying updated payroll details
	std::cout << "\n\n--- Updated Payroll Details ---";
	payroll.displayPayroll(emp1);
	payroll.displayPayroll(emp2);
	payroll.displayPayroll(emp3);
	
	std::cout << "\n--- Updated Employee Details ---";
	emp1.display();
	emp2.display();
	emp3.display();
	
	return 0;
}
