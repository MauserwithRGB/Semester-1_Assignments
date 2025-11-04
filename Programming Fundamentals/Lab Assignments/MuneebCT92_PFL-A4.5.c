#include <stdio.h>
int main (void)
{
	float cal, fat, fatCal, fat_pc;
	printf("Enter total calories: ");
	scanf("%f", &cal);
	printf("\nEnter total fat (in grams): ");
	scanf("%f", &fat);
	
	fatCal = 9 * fat;
	
	if (cal < 0 || fat < 0)
	{
		printf("\nInput must be positive!");
	}
	else if (fatCal > cal)
	{
		printf("\nTotal fat cannot be greater than total calories!");
	}
	else 
	{
		fat_pc = (fatCal / cal) * 100;
		if (fat_pc < 30)
		{
			printf("\nThis food is low in fat!");
		}
		printf("\nFat percentage in this food is %0.2f%%", fat_pc);
	}
	 return 0;
}