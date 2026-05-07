// Exercise 2: Teacher class with derived classes for different subjects

#include <iostream>
#include <string.h>

class Teacher
{
	private:
		char* Name;
		int Age;
		char* Institute;
		
	public:
		Teacher()
		{
			Name = NULL;
			Age = 0;
			Institute = NULL;
		}
		
		~Teacher()
		{
			if (Name != NULL)
			{
				delete[] Name;
			}
			if (Institute != NULL)
			{
				delete[] Institute;
			}
		}
		
		const char* getName()
		{
			return Name;
		}
		
		int getAge()
		{
			return Age;
		}
		
		const char* getInstitute()
		{
			return Institute;
		}
		
		void setName(const char* name)
		{
			if (Name != NULL)
			{
				delete[] Name;
			}
			Name = new char[strlen(name) + 1];
			strcpy(Name, name);
		}
		
		void setAge(int age)
		{
			Age = age;
		}
		
		void setInstitute(const char* inst)
		{
			if (Institute != NULL)
			{
				delete[] Institute;
			}
			Institute = new char[strlen(inst) + 1];
			strcpy(Institute, inst);
		}
};

class HumanitiesTeacher : public Teacher
{
	private:
		char Department[20];
		char* CourseName;
		char* Designation;
		
	public:
		HumanitiesTeacher()
		{
			strcpy(Department, "Humanities");
			CourseName = NULL;
			Designation = NULL;
		}
		
		~HumanitiesTeacher()
		{
			if (CourseName != NULL)
			{
				delete[] CourseName;
			}
			if (Designation != NULL)
			{
				delete[] Designation;
			}
		}
		
		const char* getDepartment()
		{
			return Department;
		}
		
		const char* getCourseName()
		{
			return CourseName;
		}
		
		const char* getDesignation()
		{
			return Designation;
		}
		
		void setCourseName(const char* course)
		{
			if (CourseName != NULL)
			{
				delete[] CourseName;
			}
			CourseName = new char[strlen(course) + 1];
			strcpy(CourseName, course);
		}
		
		void setDesignation(const char* desig)
		{
			if (Designation != NULL)
			{
				delete[] Designation;
			}
			Designation = new char[strlen(desig) + 1];
			strcpy(Designation, desig);
		}
		
		void display()
		{
			std::cout << "\n--- Humanities Teacher Details ---";
			std::cout << "\nName: " << getName();
			std::cout << "\nAge: " << getAge();
			std::cout << "\nInstitute: " << getInstitute();
			std::cout << "\nDepartment: " << Department;
			std::cout << "\nCourse Name: " << CourseName;
			std::cout << "\nDesignation: " << Designation;
			std::cout << "\n";
		}
};

class ScienceTeacher : public Teacher
{
	private:
		char Department[20];
		char* CourseName;
		char* Designation;
		
	public:
		ScienceTeacher()
		{
			strcpy(Department, "Science");
			CourseName = NULL;
			Designation = NULL;
		}
		
		~ScienceTeacher()
		{
			if (CourseName != NULL)
			{
				delete[] CourseName;
			}
			if (Designation != NULL)
			{
				delete[] Designation;
			}
		}
		
		const char* getDepartment()
		{
			return Department;
		}
		
		const char* getCourseName()
		{
			return CourseName;
		}
		
		const char* getDesignation()
		{
			return Designation;
		}
		
		void setCourseName(const char* course)
		{
			if (CourseName != NULL)
			{
				delete[] CourseName;
			}
			CourseName = new char[strlen(course) + 1];
			strcpy(CourseName, course);
		}
		
		void setDesignation(const char* desig)
		{
			if (Designation != NULL)
			{
				delete[] Designation;
			}
			Designation = new char[strlen(desig) + 1];
			strcpy(Designation, desig);
		}
		

		void display()
		{
			std::cout << "\n--- Science Teacher Details ---";
			std::cout << "\nName: " << getName();
			std::cout << "\nAge: " << getAge();
			std::cout << "\nInstitute: " << getInstitute();
			std::cout << "\nDepartment: " << Department;
			std::cout << "\nCourse Name: " << CourseName;
			std::cout << "\nDesignation: " << Designation;
			std::cout << "\n";
		}
};

class MathsTeacher : public Teacher
{
	private:
		char Department[20];
		char* CourseName;
		char* Designation;
		
	public:
		MathsTeacher()
		{
			strcpy(Department, "Maths");
			CourseName = NULL;
			Designation = NULL;
		}
		
		~MathsTeacher()
		{
			if (CourseName != NULL)
			{
				delete[] CourseName;
			}
			if (Designation != NULL)
			{
				delete[] Designation;
			}
		}
		
		const char* getDepartment()
		{
			return Department;
		}
		
		const char* getCourseName()
		{
			return CourseName;
		}
		
		const char* getDesignation()
		{
			return Designation;
		}
		
		void setCourseName(const char* course)
		{
			if (CourseName != NULL)
			{
				delete[] CourseName;
			}
			CourseName = new char[strlen(course) + 1];
			strcpy(CourseName, course);
		}
		
		void setDesignation(const char* desig)
		{
			if (Designation != NULL)
			{
				delete[] Designation;
			}
			Designation = new char[strlen(desig) + 1];
			strcpy(Designation, desig);
		}
		
		void display()
		{
			std::cout << "\n--- Maths Teacher Details ---";
			std::cout << "\nName: " << getName();
			std::cout << "\nAge: " << getAge();
			std::cout << "\nInstitute: " << getInstitute();
			std::cout << "\nDepartment: " << Department;
			std::cout << "\nCourse Name: " << CourseName;
			std::cout << "\nDesignation: " << Designation;
			std::cout << "\n";
		}
};

int main()
{
	char tempInput[100];
	int ageInput;
	
	HumanitiesTeacher teacher1;
	std::cout << "=== Enter Humanities Teacher Details ===\n";
	std::cout << "Name: ";
	std::cin.getline(tempInput, 100);
	teacher1.setName(tempInput);
	
	std::cout << "Age: ";
	std::cin >> ageInput;
	teacher1.setAge(ageInput);
	std::cin.ignore();
	
	std::cout << "Institute: ";
	std::cin.getline(tempInput, 100);
	teacher1.setInstitute(tempInput);
	
	std::cout << "Course Name: ";
	std::cin.getline(tempInput, 100);
	teacher1.setCourseName(tempInput);
	
	std::cout << "Designation: ";
	std::cin.getline(tempInput, 100);
	teacher1.setDesignation(tempInput);
	
	ScienceTeacher teacher2;
	std::cout << "\n=== Enter Science Teacher Details ===\n";
	std::cout << "Name: ";
	std::cin.getline(tempInput, 100);
	teacher2.setName(tempInput);
	
	std::cout << "Age: ";
	std::cin >> ageInput;
	teacher2.setAge(ageInput);
	std::cin.ignore();
	
	std::cout << "Institute: ";
	std::cin.getline(tempInput, 100);
	teacher2.setInstitute(tempInput);
	
	std::cout << "Course Name: ";
	std::cin.getline(tempInput, 100);
	teacher2.setCourseName(tempInput);
	
	std::cout << "Designation: ";
	std::cin.getline(tempInput, 100);
	teacher2.setDesignation(tempInput);
	
	MathsTeacher teacher3;
	std::cout << "\n=== Enter Maths Teacher Details ===\n";
	std::cout << "Name: ";
	std::cin.getline(tempInput, 100);
	teacher3.setName(tempInput);
	
	std::cout << "Age: ";
	std::cin >> ageInput;
	teacher3.setAge(ageInput);
	std::cin.ignore();
	
	std::cout << "Institute: ";
	std::cin.getline(tempInput, 100);
	teacher3.setInstitute(tempInput);
	
	std::cout << "Course Name: ";
	std::cin.getline(tempInput, 100);
	teacher3.setCourseName(tempInput);
	
	std::cout << "Designation: ";
	std::cin.getline(tempInput, 100);
	teacher3.setDesignation(tempInput);
	
	std::cout << "\n\n=== Teacher Information ===";
	teacher1.display();
	teacher2.display();
	teacher3.display();
	
	return 0;
}