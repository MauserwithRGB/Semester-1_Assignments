#include <stdio.h>
int main(void)
{
	int num, mul, table;
	printf("======= Multiplication Table =======\n");
	printf("\nEnter Number: ");
	scanf("%d", &num);
	
	for (int mul = 1; mul <= 10; mul++)
	{
		table = num * mul;
		printf("%d x %d = %d\n",num, mul, table);
	}
}