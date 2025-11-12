#include <stdio.h>
#include <string.h>
#include <ctype.h>
int countVowels(char str[250]), countWords(char str[250]), countUppercase(char str[250]);
int main(void)
{
	char string[250];
	int vowels, words, upcase;
	printf("Enter a sentence: ");
	fgets(string, sizeof(string), stdin);
	vowels = countVowels(string);
	words = countWords(string);
	upcase = countUppercase(string);
	printf("There are %d vowels, %d words, and %d uppercase letters in this sentence.", vowels, words, upcase);
}

int countVowels(char str[250])
{
	char ch;
	int vowels = 0, size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		ch = tolower(str[i]);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			vowels++;
		}
	}
	return vowels;
}

int countWords(char str[250])
{
	int words = 1, size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if(str[i] == ' ')
		{
			words++;
			if (str[i+1] == ' ')        // to solve double spacing issues
			{
				words -= 1;
			}
		}
	}
	return words;
}
 
int countUppercase(char str[250])
{
	int upcase = 0, size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (isupper(str[i]))
		{
			upcase++;
		}
	}
	return upcase;
}