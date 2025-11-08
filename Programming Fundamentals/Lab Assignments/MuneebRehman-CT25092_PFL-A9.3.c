#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    int *ptr = arr;
    int sum = 0;
    
    printf("Enter %d integers:\n", n);
    
    for (int i = 0; i < n; i++)
    {
    	scanf("%d", &arr[i]);
	}
	
    for (int i = 0; i < n; i++)
    {
    	sum += *(ptr + i);
	}
	
    printf("Sum of elements = %d\n", sum);
    return 0;
}
