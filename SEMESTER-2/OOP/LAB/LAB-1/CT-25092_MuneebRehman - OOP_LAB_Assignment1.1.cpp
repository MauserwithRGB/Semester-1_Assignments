// OOP Lab Assignment 1.1           Task: a program for inputting roll number and marks and displaying the total, along with percentage

#include <iostream>
#include <cstring>

class student
{
	std::string roll_no;	
	float marks[5] = {0};
	float totalMarks = 0;
	
	public:
		void takeInput()
		{
			std::cout << "Enter your roll number: ";
			std::cin >> roll_no;

			std::cout << "\nEnter your marks in each subject(5): ";

			for (int i = 0; i < 5; i++)
			{
				std::cout << "\nSubject " << i + 1 << ": ";
				std::cin >> marks[i];
				
				if (marks[i] < 0  || marks[i] > 100)
					{
						std::cout << "\nInvalid marks!\nTry again.";
						i -= 1;  // keeps asking for the same subject if input is invalid by canceling out i++, thus continuing the loop
					}
			}
		}
		
		void printMarks()
		{
			for (int i = 0; i < 5; i++)
			{
				totalMarks += marks[i]; 
			}
			
			std::cout << "Your total marks are " << totalMarks << ".\nYour percentage is " << (totalMarks / 500) * 100;
		}
};

int main()
{

	student student1;
	student1.takeInput();
	student1.printMarks();
}