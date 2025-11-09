#include <stdio.h>
int main(void)
{
	int rows;
	printf("NOTE: Rows are equal to columns in a square matrix.\n");
	printf("Enter the number of rows and columns in the square matrix: ");
	scanf("%d", &rows);
	
	int matrix[rows][rows], trans[rows][rows];
	printf("Enter the elements: ");
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<rows; j++)
		{
			scanf("%d", &matrix[i][j]);
			trans[j][i] = matrix[i][j];
		}
	}
	
	int symFlag = 1;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<rows; j++)
		{
			if (trans[i][j] != matrix[i][j])
			{
				symFlag = 0;
				break;
			}
		}
	}
	printf("The transpose of the matrix is:\n");
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<rows; j++)
		{
			printf("%d ", trans[i][j]);
		}
		printf("\n");
	}
	if (symFlag == 1)
	{
		printf("The matrix is symmetric.");
	}
	else
	{
		printf("The matrix is NOT symmetric.");
	}
}