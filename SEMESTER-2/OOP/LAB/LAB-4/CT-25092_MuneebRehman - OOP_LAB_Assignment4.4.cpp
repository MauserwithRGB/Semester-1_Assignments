// Exercise 4: Demonstrating the concept of constant keyword

#include <iostream>

class Student
{
	private:
		int rollNumber;
		float marks;
		const int maxMarks;
		
	public:
		Student(int roll, float m) : maxMarks(100)
		{
			rollNumber = roll;
			marks = m;
		}
		
		void displayInfo() const
		{
			std::cout << "\nRoll Number: " << rollNumber;
			std::cout << "\nMarks: " << marks;
			std::cout << "\nMax Marks: " << maxMarks;
			std::cout << "\n";
		}
		
		void updateMarks(float newMarks)
		{
			marks = newMarks;
			std::cout << "Marks updated successfully!\n";
		}
		
		int getMaxMarks() const
		{
			return maxMarks;
		}
};

int main()
{
	const float PI = 3.14159;
	std::cout << "Constant PI value: " << PI << "\n";
	
	const int value = 50;
	const int* ptr = &value;
	std::cout << "Const pointer value: " << *ptr << "\n";
	
	const Student student1(101, 85.5);
	student1.displayInfo();
	
	Student student2(102, 90.0);
	student2.displayInfo();
	student2.updateMarks(95.0);
	student2.displayInfo();
	
	std::cout << "\nMax marks (from const function): " << student2.getMaxMarks() << "\n";
	
	return 0;
}