// Exercise 1: 2D Dynamic Array class with operator overloading

#include <iostream>

class Array2D
{
	private:
		int** array;
		int rows;
		int cols;
		
	public:
		// Default constructor
		Array2D()
		{
			rows = 0;
			cols = 0;
			array = NULL;
		}
		
		// Parameterized constructor
		Array2D(int r, int c)
		{
			rows = r;
			cols = c;
			
			// Allocating memory for 2D array
			array = new int*[rows];
			for (int i = 0; i < rows; i++)
			{
				array[i] = new int[cols];
				// Initializing with 0
				for (int j = 0; j < cols; j++)
				{
					array[i][j] = 0;
				}
			}
		}
		
		// Copy constructor
		Array2D(const Array2D &obj)
		{
			rows = obj.rows;
			cols = obj.cols;
			
			// Deep copy
			array = new int*[rows];
			for (int i = 0; i < rows; i++)
			{
				array[i] = new int[cols];
				for (int j = 0; j < cols; j++)
				{
					array[i][j] = obj.array[i][j];
				}
			}
		}
		
		// Destructor
		~Array2D()
		{
			if (array != NULL)
			{
				for (int i = 0; i < rows; i++)
				{
					delete[] array[i];
				}
				delete[] array;
			}
		}
		
		// Overloaded assignment operator
		Array2D& operator=(const Array2D &obj)
		{
			if (this != &obj) // check for self-assignment
			{
				// Delete old memory
				if (array != NULL)
				{
					for (int i = 0; i < rows; i++)
					{
						delete[] array[i];
					}
					delete[] array;
				}
				
				// Copy new data
				rows = obj.rows;
				cols = obj.cols;
				
				array = new int*[rows];
				for (int i = 0; i < rows; i++)
				{
					array[i] = new int[cols];
					for (int j = 0; j < cols; j++)
					{
						array[i][j] = obj.array[i][j];
					}
				}
			}
			return *this;
		}
		
		// Overloaded + operator
		Array2D operator+(const Array2D &obj)
		{
			if (rows != obj.rows || cols != obj.cols)
			{
				std::cout << "Error: Array dimensions must match for addition!\n";
				return Array2D();
			}
			
			Array2D result(rows, cols);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					result.array[i][j] = array[i][j] + obj.array[i][j];
				}
			}
			return result;
		}
		
		// Overloaded - operator
		Array2D operator-(const Array2D &obj)
		{
			if (rows != obj.rows || cols != obj.cols)
			{
				std::cout << "Error: Array dimensions must match for subtraction!\n";
				return Array2D();
			}
			
			Array2D result(rows, cols);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					result.array[i][j] = array[i][j] - obj.array[i][j];
				}
			}
			return result;
		}
		
		// Overloaded * operator (matrix multiplication)
		Array2D operator*(const Array2D &obj)
		{
			if (cols != obj.rows)
			{
				std::cout << "Error: Invalid dimensions for multiplication!\n";
				return Array2D();
			}
			
			Array2D result(rows, obj.cols);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < obj.cols; j++)
				{
					result.array[i][j] = 0;
					for (int k = 0; k < cols; k++)
					{
						result.array[i][j] += array[i][k] * obj.array[k][j];
					}
				}
			}
			return result;
		}
		
		// Overloaded indexing operator
		int* operator[](int index)
		{
			if (index >= 0 && index < rows)
			{
				return array[index];
			}
			else
			{
				std::cout << "Error: Index out of bounds!\n";
				return NULL;
			}
		}
		
		// Function to set values
		void setValue(int r, int c, int value)
		{
			if (r >= 0 && r < rows && c >= 0 && c < cols)
			{
				array[r][c] = value;
			}
		}
		
		// Function to display array
		void display()
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					std::cout << array[i][j] << " ";
				}
				std::cout << "\n";
			}
		}
		
		// Getters
		int getRows()
		{
			return rows;
		}
		
		int getCols()
		{
			return cols;
		}
};

int main()
{
	std::cout << "=== Testing 2D Array Class ===\n";
	
	// Testing parameterized constructor
	Array2D arr1(3, 3);
	std::cout << "\nArray 1 (3x3) initialized:\n";
	arr1.display();
	
	// Setting values using indexing operator
	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[0][2] = 3;
	arr1[1][0] = 4;
	arr1[1][1] = 5;
	arr1[1][2] = 6;
	arr1[2][0] = 7;
	arr1[2][1] = 8;
	arr1[2][2] = 9;
	
	std::cout << "\nArray 1 after setting values:\n";
	arr1.display();
	
	// Testing copy constructor
	Array2D arr2(arr1);
	std::cout << "\nArray 2 (copy of Array 1):\n";
	arr2.display();
	
	// Creating another array for operations
	Array2D arr3(3, 3);
	arr3[0][0] = 9;
	arr3[0][1] = 8;
	arr3[0][2] = 7;
	arr3[1][0] = 6;
	arr3[1][1] = 5;
	arr3[1][2] = 4;
	arr3[2][0] = 3;
	arr3[2][1] = 2;
	arr3[2][2] = 1;
	
	std::cout << "\nArray 3:\n";
	arr3.display();
	
	// Testing + operator
	Array2D arr4 = arr1 + arr3;
	std::cout << "\nArray 1 + Array 3:\n";
	arr4.display();
	
	// Testing - operator
	Array2D arr5 = arr1 - arr3;
	std::cout << "\nArray 1 - Array 3:\n";
	arr5.display();
	
	// Testing * operator
	Array2D arr6 = arr1 * arr3;
	std::cout << "\nArray 1 * Array 3:\n";
	arr6.display();
	
	// Testing assignment operator
	Array2D arr7;
	arr7 = arr1;
	std::cout << "\nArray 7 (assigned from Array 1):\n";
	arr7.display();
	
	return 0;
}
