// Exercise 1: Employee class with changeable name but constant ID

#include <iostream>
#include <string.h>

class Employee
{
	private:
		char* EmployeeName;
		const int EmployeeId;
		
	public:
		Employee(const char* name, int id) : EmployeeId(id)
		{
			EmployeeName = new char[strlen(name) + 1];
			strcpy(EmployeeName, name);
		}
		
		~Employee()
		{
			delete[] EmployeeName;
		}
		
		const char* getEmployeeName()
		{
			return EmployeeName;
		}
		
		int getEmployeeId()
		{
			return EmployeeId;
		}
		

		void setEmployeeName(const char* name)
		{
			delete[] EmployeeName;
			EmployeeName = new char[strlen(name) + 1];
			strcpy(EmployeeName, name);
		}
};

int main()
{
	Employee Employee1("Ali Ahmed", 101);
	Employee Employee2("Sara Khan", 102);
	Employee Employee3("Hassan Raza", 103);
	
	std::cout << "--- Initial Employee Details ---\n";
	std::cout << "Employee 1: " << Employee1.getEmployeeName() << " (ID: " << Employee1.getEmployeeId() << ")\n";
	std::cout << "Employee 2: " << Employee2.getEmployeeName() << " (ID: " << Employee2.getEmployeeId() << ")\n";
	std::cout << "Employee 3: " << Employee3.getEmployeeName() << " (ID: " << Employee3.getEmployeeId() << ")\n";
	
	Employee1.setEmployeeName("Ali Akbar");
	Employee2.setEmployeeName("Sara Malik");
	
	std::cout << "\n--- After Name Changes ---\n";
	std::cout << "Employee 1: " << Employee1.getEmployeeName() << " (ID: " << Employee1.getEmployeeId() << ")\n";
	std::cout << "Employee 2: " << Employee2.getEmployeeName() << " (ID: " << Employee2.getEmployeeId() << ")\n";
	std::cout << "Employee 3: " << Employee3.getEmployeeName() << " (ID: " << Employee3.getEmployeeId() << ")\n";
	
	return 0;
}