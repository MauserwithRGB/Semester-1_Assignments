//#include <iostream>
//#include <iomanip>
//
//int main()
//{
//	while(1)
//	{
//		for (int i = 0; i < 10; i++)
//			std::cout << std::setw(i) << std::setfill('*') << "\n";
//			
//		for (int j = 10; j > 0; j--)
//			std::cout << std::setw(j) << std::setfill('*') << "\n";
//	}
//}

#include <iostream>
#include <iomanip> // Necessary header

int main() {
    std::cout << std::left << std::setw(15) << "Item" 
              << std::right << std::setw(10) << "Price" << std::endl;
    std::cout << std::string(25, '-') << std::endl; // Separator
    
    std::cout << std::left << std::setw(15) << "Apples" 
              << std::right << std::setw(10) << std::fixed << std::setprecision(2) << 1.50 << std::endl;
              
    std::cout << std::left << std::setw(15) << "Oranges" 
              << std::right << std::setw(10) << std::fixed << std::setprecision(2) << 2.75 << std::endl;
    return 0;
}
