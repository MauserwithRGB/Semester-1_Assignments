#include <stdio.h>
int main(void)
{
	int rng, lim;
	printf("======= Even/Odd Checker =======\n");
	printf("Enter Range of Numbers: \n");
	scanf("%d", &rng);
	
	if (rng > 0)
	{
	for (int lim = 1; lim <= rng; lim++)
	{
		if (lim % 2 == 0)
		{
			printf("%d is Even.\n", lim);
		}
		else 
		{
			printf("%d is Odd.\n", lim);
		}
	}
	}
	else if (rng == 0)
	{             
		printf("No Sequence for Input '0'.\n");
	}
	else if (rng < 0)
	{    
		for (int lim = -1; lim >= rng; lim--)
		{
			if (lim % -2 == 0)
			{
				printf("%d is Even.\n", lim);
			}                       
			else
			{   
				printf("%d is Odd.\n", lim);
			
			}
	    }
    }
    return 0;
}