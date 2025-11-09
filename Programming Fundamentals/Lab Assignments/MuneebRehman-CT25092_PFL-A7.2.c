#include <stdio.h>
int main(void)
{
	int rows, columns, zeros=0;
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
			if (matrix[i][j] == 0)
			{
				zeros++;
			}
		}
	}
	if (zeros >= ((double)(rows*columns)/2))
	{
		printf("The matrix is sparse.");
	}
	else
	{
		printf("The matrix is NOT sparse.");
	}
	
}