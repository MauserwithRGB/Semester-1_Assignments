#include <stdio.h>
int main(void)
{
	int rows, columns;
	printf("Enter number of rows: ");
	scanf("%d", &rows);
	printf("Enter number of columns: ");
	scanf("%d", &columns);
	
	int matrix[rows][columns];
	printf("Enter the elements: ");
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	printf("The matrix is:\n");
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	int max = matrix[0][0];
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			if (matrix[i][j]>matrix[0][0])
			{
				max = matrix[i][j];
			}
		}
	}
	printf("The greatest element is %d.", max);
}