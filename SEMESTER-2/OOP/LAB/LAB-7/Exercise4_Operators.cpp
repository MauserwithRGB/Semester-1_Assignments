// Exercise 4: Friend function - Functions accessing private members of Employee

#include <iostream>
#include <string.h>

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
		
		// Declaring friend functions
		friend void updateSalary(Employee &emp, float newSalary);
		friend void displayPayroll(Employee &emp);
		friend void giveIncrement(Employee &emp, float percentage);
		friend void calculateAnnualSalary(Employee &emp);
};

// Friend function to update salary
void updateSalary(Employee &emp, float newSalary)
{
	emp.salary = newSalary; // accessing private member
	std::cout << "\nSalary updated successfully for " << emp.name << "!";
}

// Friend function to display payroll details
void displayPayroll(Employee &emp)
{
	std::cout << "\n--- Payroll Details ---";
	std::cout << "\nEmployee Name: " << emp.name;
	std::cout << "\nEmployee ID: " << emp.id;
	std::cout << "\nDesignation: " << emp.designation;
	std::cout << "\nCurrent Salary: " << emp.salary << " PKR";
	std::cout << "\n";
}

// Friend function to give increment
void giveIncrement(Employee &emp, float percentage)
{
	float increment = emp.salary * (percentage / 100.0);
	emp.salary = emp.salary + increment;
	std::cout << "\n" << percentage << "% increment given to " << emp.name;
	std::cout << "\nNew Salary: " << emp.salary << " PKR";
}

// Friend function to calculate annual salary
void calculateAnnualSalary(Employee &emp)
{
	float annualSalary = emp.salary * 12;
	std::cout << "\nAnnual Salary of " << emp.name << ": " << annualSalary << " PKR";
}

int main()
{
	std::cout << "=== Employee Payroll System (Friend Function) ===\n";
	
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
	
	// Updating salaries using friend functions
	std::cout << "\n\n--- Salary Updates ---";
	updateSalary(emp1, 55000.0);
	updateSalary(emp2, 85000.0);
	
	// Giving increment
	giveIncrement(emp3, 10);
	
	// Displaying payroll details using friend function
	std::cout << "\n\n--- Payroll Details ---";
	displayPayroll(emp1);
	displayPayroll(emp2);
	displayPayroll(emp3);
	
	// Calculating annual salaries
	std::cout << "\n\n--- Annual Salaries ---";
	calculateAnnualSalary(emp1);
	calculateAnnualSalary(emp2);
	calculateAnnualSalary(emp3);
	
	std::cout << "\n\n--- Updated Employee Details ---";
	emp1.display();
	emp2.display();
	emp3.display();
	
	return 0;
}
