#include <string>
#include <fstream>
#include <iostream>


int main()
{
	std::ifstream file{"filename.txt"};
	std::string name, address, something;
	if (file >> name >> address >> something)
		std::cout << name << address;
	
	
	
//	// i can also just creat an ofstream object, but name and open it later
//	std::ofstream file; // creates just the object
//	
////	file.eof();
//
//	file.open("filename.txt"); // opens (or creates it if not already created) the file with the name 'filename.txt'
//	
//	std::string name, address, something;
//	std::cout << "Enter name, address, something: ";
//	
//	while (std::cin >> name >> address >> something)
//		file << name << "\n" << address << "\n" << something;
	
	
//	std::ofstream outFile("first_file.txt");			// opens the file, and loads it *fully* into memory. the file is truncated, or in simpler terms; 	it overwrites all of the file.
//	
//	if(!outFile)		// if file didn't open
//	{
//		std::cerr << "File not opnened!";
//	}
//	
//	outFile << "First time doing file processing! 2\n";
//	outFile << "Overwritten";
//	outFile.close();
}