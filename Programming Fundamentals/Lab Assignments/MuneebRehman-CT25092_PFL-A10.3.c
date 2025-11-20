#include <stdio.h>
int main(void)
{
	int size;
	printf("Enter the size of the array you want to enter: ");
	scanf("%d", &size);
	int arr[size], element;

	int *arrPtr = arr;
	int sum = 0;
	printf("Enter the elements: ");
	for (int i = 0; i < size; i++)
	{
		arr[i] = element;
		sum += *(arrPtr + i);
	}
	printf("The sum of all the elements of the array is %d.", sum);
	
}