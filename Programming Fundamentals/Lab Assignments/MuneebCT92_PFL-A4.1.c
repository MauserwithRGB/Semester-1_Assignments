#include <stdio.h>
int main(void)
{
    char letter;

    printf("Enter input: ");
    scanf("%c", &letter);
    
    if (letter >= 'A' && letter <= 'Z') 
	{
        printf("Input is a capital letter");
    }
    else if (letter >= 'a' && letter <= 'z') 
	{
        printf("Your input is a small letter");
    }
    else if (letter >= '0' && letter <= '9')
	{
        printf("Your input is a number");
    }
    else
	{
        printf("Your input is a special character");
    }
    return 0;
}