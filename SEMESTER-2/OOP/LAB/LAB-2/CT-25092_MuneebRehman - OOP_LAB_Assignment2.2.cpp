#include <iostream>

class bankAccount
{
	private:
		float balance;
		int transactions;
		
	public:
		bankAccount()
		{
			balance = 50000;  // harcoded balance
			transactions = 0;  // assumed that no transactions have happened
		}
		
		
}


int main() 
{ 
	bankAccount userAccount; userAccount.initialize(1000.0); // starting balance of 1000

	int choice;
	float inputAmount;

	// using while loop for the menu as it's easier to repeat
	while (true)
	{
		std::cout << "\n\n--- ABC Bank Management System ---";
		std::cout << "\n1. Display the account balance";
		std::cout << "\n2. Display the number of transactions";
		std::cout << "\n3. Display interest earned for this period";
		std::cout << "\n4. Make a deposit";
		std::cout << "\n5. Make a withdrawal";
		std::cout << "\n6. Exit the program";
	
		std::cout << "\n\nEnter choice (1-6): ";
		std::cin >> choice;
	
		switch (choice)
		{
				case 1:
			{
				std::cout << "\nYour current balance is: " << userAccount.balance;
			}
	
			case 2:
			{
				std::cout << "\nTotal transactions performed: " << userAccount.transactions;
			}
		
			case 3:
			{
				std::cout << "\nInterest earned for this period: " << userAccount.checkInterest();
			}
		
			case 4:
			{
				std::cout << "\nEnter amount to deposit: ";
				std::cin >> inputAmount;
				userAccount.deposit(inputAmount);
			}
		
			case 5:
			{
				std::cout << "\nEnter amount to withdraw: ";
				std::cin >> inputAmount;
				userAccount.withdraw(inputAmount);
			}
		
			case 6:
			{
				std::cout << "\nExiting... Thank you for using ABC Bank.";
				break; // breaks out of the while loop
			}
		
			default
			{
				std::cout << "\nInvalid input! Please choose between 1 and 6.";
			}
		}
	}
}