// OOP assignment 2.1                  purpose:      a class for stduents and display the ones from a specific section

#include <iostream>
#include <string>

class student
{
	public:
		std::string name;
		std::string roll_no;
		int semester;
		char section;

		void display() 
		{
        	std::cout << "Name: " << name << " | Roll No: " << roll_no << " | Semester: " << semester << " | Section: " << section << std::endl;
    	}
};

int main(void)
{
	student std[4];
	
	std[0] = {"Muneeb", "CT-092", 2, 'B'};
	
	std[1] = {"Ali", "CT-096", 2, 'B'};
	
	std[2] = {"Hans", "CT-177", 2, 'D'};
	
	std[3] = {"Zain", "CT-100", 2, 'A'};
	
	
	std::cout << "--- Students of Section A ---" << std::endl;
    
    for (int i = 0; i < 4; i++)
	{
        if (std[i].section == 'A' || std[i].section == 'a') 
		{
            std[i].display();
        }
    }
}