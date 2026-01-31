// OOP lab assignment 1.4            purpose: a 3x3 matrix addition and multiplication program using functions

#include <iostream>

void addMatrix(int mat1[3][3], int mat2[3][3])  // no need to pass column size because for addition rows must = columns
{
	int result[3][3] = {0};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	
	std::cout << "\nThe resultant matrix after addition is:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << result[i][j] << " ";
		}
		
		std::cout << "\n";
	}
}

void mulMatrix(int mat1[3][3], int mat2[3][3])
{
	int result[3][3] = {0};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				result [i][j] = mat1[i][j] * mat2[i][j];
			}
		}
	}
	
	std::cout << "\nThe resultant matrix after multiplication is:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	int mat1[3][3], mat2[3][3];
	
	std::cout << "Enter the elements for the first matrix: ";	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> mat1[i][j];
		}
	}
	
	
	std::cout << "\nEnter the elements for the second matrix: ";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> mat2[i][j];
		}
	}
	
	addMatrix(mat1, mat2);
	
	mulMatrix(mat1, mat2);
}