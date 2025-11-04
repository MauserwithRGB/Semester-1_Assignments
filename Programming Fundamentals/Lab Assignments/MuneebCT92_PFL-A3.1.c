#include <stdio.h>
int main(void)
{
    int A, B, C; 
    printf("Enter A, then B: "); 
    scanf("%d %d", &A, &B); 
    C=A; 
    A=B; 
    B=C; 
    printf("A: %d\nB: %d\n", A, B); 
}