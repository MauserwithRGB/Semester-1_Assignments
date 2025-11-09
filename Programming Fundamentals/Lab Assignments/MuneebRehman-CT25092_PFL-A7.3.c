#include <stdio.h>
#include <string.h>
int main(void)
{
	char first[30], last[30], full[60];
	printf("Enter your first name: ");
	scanf("%s", &first);
	printf("Enter your last name: ");
	scanf("%s", &last);
	
	full[0] = '\0';
	strcat(full, first);
	strcat(full, " ");
	strcat(full, last);
	printf("Your full name is %s.", full);
}