#include <stdio.h>

void swaped(int *aPtr, int *bPtr, int *cPtr);

int main()
{
	int a, b, c, temp;
	printf("Enter value of 'a': ");
	scanf("%d", &a);
	printf("Enter value of 'b': ");
	scanf("%d", &b);
	printf("Enter value of 'c': ");
	scanf("%d", &c);
	int *aPtr = &a, *bPtr = &b, *cPtr = &c;
	
	swaped(aPtr, bPtr, cPtr);
}

void swaped(int *aPtr, int *bPtr, int *cPtr)    // the question had incorrect swap logic; value or 'c' was getting lost. So i did 3-way rotation instead. 
{
	int temp, a = *aPtr, b = *bPtr, c = *cPtr;
	temp = *aPtr;
	*aPtr = *bPtr;
	*bPtr = *cPtr;
	*cPtr = temp;
	printf("Swapped values:\n 'a' = %d\n'b' = %d\n'c' = %d", *aPtr, *bPtr, *cPtr);
	
}