#include <stdio.h>
#include <math.h>
int main(void)
{
    float x1, x2, a, b, c, real, imaginary, det, detN;
    printf("Enter value of 'a': ");
    scanf("%f", &a);
    printf("\nEnter value of 'b': ");
    scanf("%f", &b);
    printf("\nEnter value of 'c': ");
    scanf("%f", &c);
    
    det = sqrt(b*b - 4*a*c);
    detN = sqrt(-(b*b - 4*a*c));  // detN is the negative determinant

    if (b*b - 4*a*c > 0)
	{
        x1 = (-b + det) / (2*a);
        x2 = (-b - det) / (2*a);
        printf("The roots are %f and %f", x1, x2);
    }
    else if (b*b - 4*a*c == 0) 
	{
        x1 = -b/(2*a);
        printf("The root is %f", x1);
    }
    else
	{
        real = -b/(2*a);
        imaginary = detN / (2*a);
        printf("The first root is %f + %fi", real, imaginary);
        printf("\nThe second root is %f - %fi", real, imaginary);
    }
    return 0;
}