#include <iostream>

bool additionValid(int row1, int column1, int row2, int column2)  // checks if matrices can be added or not
{
	if (row1 == row2 && column1 == column2)
		return true;
	
	return false;
}

bool mulValid(int row1, int column1, int row2, int column2)  // checks if matrices can be multiplied or not
{
	if (column1 == row2)  // columns of 1st matrix must equal the rows of the 2nd
		return true;
	
	return false;
}

void addMatrix(int mat1[][20], int mat2[][20], int rows)  // no need to pass column size because for addition rows must = columns
{
	int result[][20] = {0};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			result[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	
	std::cout << "The resultant matrix is:\n" << result;
}

void mulMatrix(int mat1[][20], int mat2[][20], int row1, int column1, int column2)
{
	int result[][20] = {0};
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < column2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < column1; k++)
			{
				result [i][j] = mat1[i][j] * mat2[i][j];
			}
		}
	}
	
	std::cout << "The resultant matrix is:\n" << result;
}

int main()
{
	int rowSize1, colSize1, rowSize2, colSize2;
	
	std::cout << "How many rows for m1: ";
	std::cin >> rowSize1;
	std::cout << "How many columns for m1: ";
	std::cin >> colSize1;
	
	int mat1[rowSize1][colSize1];
	
	std::cout << "How many rows for m2: ";
	std::cin >> rowSize2;
	std::cout << "How many columns for m2: ";
	std::cin >> colSize2;
	
	int mat2[rowSize2][colSize2];
	
	for (int i = 0; i < rowSize1; i++)
	{
		for (int j = 0; j < colSize1; j++)
		{
			std::cin >> mat1[i][j];
		}
	}
	
	for (int i = 0; i < rowSize2; i++)
	{
		for (int j = 0; j < colSize2; j++)
		{
			std::cin >> mat2[i][j];
		}
	}
	
	if (additionValid(rowSize1, colSize1, rowSize2, colSize2))
	{
		addMatrix(mat1, mat2);
	}
	
}