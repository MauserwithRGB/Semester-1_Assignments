#include <iostream>

int main() {
    if (__cplusplus == 202101L)
        std::cout << "C++23\n";
    else if (__cplusplus == 202002L)
        std::cout << "C++20\n";
    else if (__cplusplus == 201703L)
        std::cout << "C++17\n";
    else if (__cplusplus == 201402L)
        std::cout << "C++14\n";
    else if (__cplusplus == 201103L)
        std::cout << "C++11\n";
    else if (__cplusplus == 199711L)
        std::cout << "C++98\n";
    else
        std::cout << "Unknown C++ version\n";
    
    std::cout << "Value of __cplusplus: " << __cplusplus << std::endl;
    return 0;
}












//#include <iostream>
//#include <string>
//#include <cctype>
//
//int main()
//{
//	float price;
//	
//	float priceArray[] = price;
//}
//


















//// OOP Assignment - ABC Bank Account purpose: a program for banking operations like deposit and withdrawal
//
//#include <iostream>
//
//class bankAccount 
//{ 
//	public:
//		
//		float balance; 
//		int transactions;
//			
//		// adding money to the account
//		void deposit(float amountIN)
//		{
//			balance = balance + amountIN;
//			transactions++; // manually increasing transaction count
//			std::cout << "\nDeposit of " << amountIN << " was successful.";
//		}
//	
//		// taking money out of the account
//		void withdraw(float amountIN)
//		{
//			if (amountIN > balance)
//			{
//				std::cout << "\nError: You do not have enough balance!";
//			}
//			else
//			{
//				balance = balance - amountIN;
//				transactions = transactions + 1;
//				std::cout << "\nWithdrawal of " << amountIN << " was successful.";
//			}
//		}
//	
//		// calculating interest for the period (hardcoded 2.5%)
//		float checkInterest()
//		{
//			float interestEarned;
//			interestEarned = balance * 0.025;
//			return interestEarned;
//		}
//
//};
//
//int main() 
//{ 
//	bankAccount userAccount; userAccount.initialize(1000.0); // starting balance of 1000
//
//	int choice;
//	float inputAmount;
//
//	// using while loop for the menu as it's easier to repeat
//	while (true)
//	{
//		std::cout << "\n\n--- ABC Bank Management System ---";
//		std::cout << "\n1. Display the account balance";
//		std::cout << "\n2. Display the number of transactions";
//		std::cout << "\n3. Display interest earned for this period";
//		std::cout << "\n4. Make a deposit";
//		std::cout << "\n5. Make a withdrawal";
//		std::cout << "\n6. Exit the program";
//	
//		std::cout << "\n\nEnter choice (1-6): ";
//		std::cin >> choice;
//	
//		switch (choice)
//		{
//				case 1:
//			{
//				std::cout << "\nYour current balance is: " << userAccount.balance;
//			}
//	
//			case 2:
//			{
//				std::cout << "\nTotal transactions performed: " << userAccount.transactions;
//			}
//		
//			case 3:
//			{
//				std::cout << "\nInterest earned for this period: " << userAccount.checkInterest();
//			}
//		
//			case 4:
//			{
//				std::cout << "\nEnter amount to deposit: ";
//				std::cin >> inputAmount;
//				userAccount.deposit(inputAmount);
//			}
//		
//			case 5:
//			{
//				std::cout << "\nEnter amount to withdraw: ";
//				std::cin >> inputAmount;
//				userAccount.withdraw(inputAmount);
//			}
//		
//			case 6:
//			{
//				std::cout << "\nExiting... Thank you for using ABC Bank.";
//				break; // breaks out of the while loop
//			}
//		
//			default
//			{
//				std::cout << "\nInvalid input! Please choose between 1 and 6.";
//			}
//		}
//	
//}
//
//}


//#include <iostream>
//void swap(int &x, int &y) { // x and y are references to original variables
//    int temp = x;
//    x = y;
//    y = temp;
//}
//
//int main() {
//    int num1 = 10.2, num2 = 20;
//    std::cout << "Before swap: num1=" << num1 << ", num2=" << num2 << std::endl;
//    swap(num1, num2); // The function modifies num1 and num2 directly
//    std::cout << "After swap: num1=" << num1 << ", num2=" << num2 << std::endl;
//    return 0;
//}
//
//
//
//
















//#include <stdio.h>
//#include <unistd.h>
//
//int main()
//{
//	int num1= 9, num2 = 3, num3 = 2;
//	printf("Result = %d", num3 * num1 / num2);
////	printf("Loading...");	
////	fflush(stdout);
////	for (int i=0; i<=100;i++)
////	{
////		printf("\rProgress: %d%%", i);
////		fflush(stdout);
////		usleep(50000);
////	}
////	printf("\nDone!");
//}







//#include <stdio.h>
//int main(void)
//{
//	int matrix[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
//	int Count=0;
//	for (int i=0; i<3;i++)
//	{
//		for (int j=0;j<3;j++)
//		{
//			if (matrix[i][j] %2 == 1)
//			{
//				Count++;
//			}
//		}
//	}
//	printf("Numbers are: %d", Count);
//	return 0;
//}





//#include <stdio.h>
//
//void func(int x);
//
//int main(void)
//{
//	func(5);
//	func(5);
//	return 0;
//}
//
//void func(int x)
//{
//
//	static int a=1;
//	a =a *x;
//	printf("a=%d \nx=%d \n", a, x);
//}


//#include <stdio.h>
//
//int main(void)
//{
//	int matrix[2][3] = {{1,2,3},{4,5,6}};
//	int *ptr = &matrix[0][0];
//	printf("%d", *(ptr+4));
//	return 0;
//}


















//#include <stdio.h>
//int main(void)
//{
//	int array[10] = {3,0,8,1,12,8,9,2,13,10}, x, y, z;
//	x = ++array[2];
//	y = array[2]++;
//	z = array[x++];
//	
//	printf("%d %d %d", x,y,z);
//}



//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char str[100], rev[100];
//    int len, i;
//
//    printf("Enter a string: ");
//    gets(str);  // use fgets in real code
//
//    len = strlen(str);
//
//    // reverse the string
//    for(i = 0; i < len; i++) {
//        rev[i] = str[len - 1 - i];
//    }
//    rev[len] = '\0';
//
//    // compare both
//    if(strcmp(str, rev) == 0)
//        printf("Palindrome\n");
//    else
//        printf("Not Palindrome\n");
//
//    return 0;
//}









//#include <stdio.h>
//
//int count_vowels(char str[]);
//
//int main(void)
//{
//	char str[500];
//	printf("Enter a string: ");
//	fgets(str, sizeof(str), stdin);
//	int count = count_vowels(str);
//	printf("Vowels = %d", count);
//	
//	return 0;
//}
//
//int count_vowels(char str[])
//{
//	int count = 0;
//	for (int i =0; i<str[i] != '\0'; i++)
//	{
//		char ch = str[i];
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			ch += 32;
//		}
//		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//


















//#include <stdio.h>
//int main(void)
//{
//	for (int i = 1; i<=4; i++)
//	{
//		for (int space = 0; space <4-i; space++)
//		{
//			printf(" ");
//		}
//		for (int j=0; j<2*i-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//int i, j, space, rows = 4;
//for (i = 1; i <= rows; i++) {
//        // Print leading spaces
//        for (space = 1; space <= rows - i; space++) {
//            printf(" ");
//        }
//        // Print asterisks
//        for (j = 1; j <= 2 * i - 1; j++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//}