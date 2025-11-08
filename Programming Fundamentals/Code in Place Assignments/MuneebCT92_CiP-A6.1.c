#include <stdio.h>
int main(void)
{
	int p = 0, m= 1, n = 0;
	printf("The Fibonacci Numbers upto 500 are:\n");
	
	while (n <= 500)
	{
		printf("%d\n", n);
		
		p = m;
		m = n;
		n = p + m;
		
		if (n % 5 == 0)
		{
			continue;
		}
		
		if (n > 300)
		{
			break;
		}
	}
	printf("\nNOTE: Numbers either greater than 300 or divisible by 5 are skipped.");
}