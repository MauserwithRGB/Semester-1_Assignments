#include <stdio.h>
int main(void)
{
	int pass = 0, fail = 0, marks = 0, consecutive_count = 0;

	while (marks != -1)
	{
		printf("Enter your marks: ");
    	scanf("%d", &marks);
		if (marks >= 50)
		{
			pass++;
			consecutive_count = 0;
		}
		if  (marks < 50)
		{
			fail++;
			consecutive_count++;
		}
		if (consecutive_count == 3)
		{
			break;
		}
	}
	if (marks == -1)
	{
		printf("Program stopped due to input '-1'.");
	}
	else
	{
		printf("Program stopped due to 3 consecutive failing marks.\nPassed: %d\nFailed: %d", pass, fail);
	}
}
