// Exercise 2: Binary search in sorted 2D matrix

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
			
			array = new int*[rows];
			for (int i = 0; i < rows; i++)
			{
				array[i] = new int[cols];
				for (int j = 0; j < cols; j++)
				{
					array[i][j] = 0;
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
		
		// Binary search function
		bool searchMatrix(int target)
		{
			if (rows == 0 || cols == 0)
			{
				return false;
			}
			
			// Treating 2D matrix as 1D sorted array
			int left = 0;
			int right = (rows * cols) - 1;
			
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				
				// Converting 1D index to 2D coordinates
				int midRow = mid / cols;
				int midCol = mid % cols;
				int midValue = array[midRow][midCol];
				
				if (midValue == target)
				{
					return true;
				}
				else if (midValue < target)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			
			return false;
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
	std::cout << "=== Binary Search in Sorted 2D Matrix ===\n";
	
	// Test case 1
	Array2D matrix1(3, 4);
	matrix1[0][0] = 1;
	matrix1[0][1] = 3;
	matrix1[0][2] = 5;
	matrix1[0][3] = 7;
	matrix1[1][0] = 10;
	matrix1[1][1] = 11;
	matrix1[1][2] = 16;
	matrix1[1][3] = 20;
	matrix1[2][0] = 23;
	matrix1[2][1] = 30;
	matrix1[2][2] = 34;
	matrix1[2][3] = 60;
	
	std::cout << "\nMatrix 1:\n";
	matrix1.display();
	
	int target1 = 3;
	std::cout << "\nSearching for target = " << target1 << "\n";
	if (matrix1.searchMatrix(target1))
	{
		std::cout << "Output: true\n";
	}
	else
	{
		std::cout << "Output: false\n";
	}
	
	// Test case 2
	int target2 = 13;
	std::cout << "\nSearching for target = " << target2 << "\n";
	if (matrix1.searchMatrix(target2))
	{
		std::cout << "Output: true\n";
	}
	else
	{
		std::cout << "Output: false\n";
	}
	
	// Additional test cases
	int target3 = 60;
	std::cout << "\nSearching for target = " << target3 << "\n";
	if (matrix1.searchMatrix(target3))
	{
		std::cout << "Output: true\n";
	}
	else
	{
		std::cout << "Output: false\n";
	}
	
	int target4 = 1;
	std::cout << "\nSearching for target = " << target4 << "\n";
	if (matrix1.searchMatrix(target4))
	{
		std::cout << "Output: true\n";
	}
	else
	{
		std::cout << "Output: false\n";
	}
	
	return 0;
}
