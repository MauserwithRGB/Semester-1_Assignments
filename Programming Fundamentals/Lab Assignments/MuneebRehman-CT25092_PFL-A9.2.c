#include <stdio.h>

void swap(int *aPtr, int *bPtr, int *cPtr)
{
    int temp;
    temp = *bPtr;
    *bPtr = *aPtr;
    *aPtr = *cPtr;
    *cPtr = temp;
}

int main(void)
{
    int a, b, c;

    printf("Enter three integers (a, b, and then c): ");
    scanf("%d %d %d", &a, &b, &c);

    printf("\nBefore swap: a=%d, b=%d, c=%d\n", a, b, c);

    swap(&a, &b, &c);

    printf("After swap:  a=%d, b=%d, c=%d", a, b, c);

    return 0;
}
