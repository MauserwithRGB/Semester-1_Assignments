#include <stdio.h>
int main(void)
{
	int input, remainder, counter;
	printf("=======Divisibility by 7 Checker=======");
	printf("\nEnter number: ");
	scanf("%d", &input);
	
	counter = 0;
	
	while (counter < 100 && (input != 7 && input != -7 && input != 0))
	{
		counter++;
		remainder = input % 10;
		input = input / 10;
		input = input - 2 * remainder;
	
	}
	if (input == 7 || input == -7 || input == 0)
	{
		printf("Number is divisible by 7");
	}
	else
	{
		printf("Number is NOT divisible by 7");
	}
	return 0;
}