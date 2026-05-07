// Exercise 1: Abstract class ArrayMultiplier with pure virtual function

#include <iostream>

class ArrayMultiplier
{
	public:
		// Pure virtual function
		virtual void calculate() = 0;
};

class ArrayMultiplier1D : public ArrayMultiplier
{
	private:
		int* array;
		int size;
		int multiplier;
		
	public:
		// Constructor
		ArrayMultiplier1D(int s, int mult)
		{
			size = s;
			multiplier = mult;
			array = new int[size];
		}
		
		// Destructor
		~ArrayMultiplier1D()
		{
			delete[] array;
		}
		
		// Function to input array values
		void inputArray()
		{
			std::cout << "\nEnter " << size << " elements for 1D array:\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << "Element [" << i << "]: ";
				std::cin >> array[i];
			}
		}
		
		// Implementation of pure virtual function
		void calculate()
		{
			std::cout << "\n--- 1D Array Multiplication ---";
			std::cout << "\nOriginal Array: ";
			for (int i = 0; i < size; i++)
			{
				std::cout << array[i] << " ";
			}
			
			std::cout << "\nMultiplier: " << multiplier;
			std::cout << "\nResult: ";
			for (int i = 0; i < size; i++)
			{
				std::cout << (array[i] * multiplier) << " ";
			}
			std::cout << "\n";
		}
};

class ArrayMultiplier2D : public ArrayMultiplier
{
	private:
		int** array;
		int rows;
		int cols;
		int multiplier;
		
	public:
		// Constructor
		ArrayMultiplier2D(int r, int c, int mult)
		{
			rows = r;
			cols = c;
			multiplier = mult;
			
			array = new int*[rows];
			for (int i = 0; i < rows; i++)
			{
				array[i] = new int[cols];
			}
		}
		
		// Destructor
		~ArrayMultiplier2D()
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] array[i];
			}
			delete[] array;
		}
		
		// Function to input array values
		void inputArray()
		{
			std::cout << "\nEnter elements for " << rows << "x" << cols << " 2D array:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					std::cout << "Element [" << i << "][" << j << "]: ";
					std::cin >> array[i][j];
				}
			}
		}
		
		// Implementation of pure virtual function
		void calculate()
		{
			std::cout << "\n--- 2D Array Multiplication ---";
			std::cout << "\nOriginal Array:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					std::cout << array[i][j] << " ";
				}
				std::cout << "\n";
			}
			
			std::cout << "\nMultiplier: " << multiplier;
			std::cout << "\nResult:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					std::cout << (array[i][j] * multiplier) << " ";
				}
				std::cout << "\n";
			}
		}
};

int main()
{
	std::cout << "=== Array Multiplier System ===\n";
	
	// Testing 1D Array Multiplication
	ArrayMultiplier1D arr1D(5, 3);
	arr1D.inputArray();
	arr1D.calculate();
	
	// Testing 2D Array Multiplication
	ArrayMultiplier2D arr2D(3, 3, 2);
	arr2D.inputArray();
	arr2D.calculate();
	
	return 0;
}
