#include <stdio.h>
int main(void)
{
	int size;
	printf("How many numbers do you want to enter?: ");
	scanf("%d", &size);
	
	int array[size], sum=0, count=0;
	printf("Enter the numbers: ");
	for (int i=0; i<size; i++)
	{
		scanf("%d", &array[i]);
	}
	for (int i=0; i<size; i++)
	{
		if (array[i]>=0)
		{
			sum += array[i];
			count++;
		}
    }
	printf("\nThe sum of all positive numbers entered is %d.", sum);  
	printf("\nThe average of all the positive numbers entered is %.2f.", (double) sum/count);
	
}