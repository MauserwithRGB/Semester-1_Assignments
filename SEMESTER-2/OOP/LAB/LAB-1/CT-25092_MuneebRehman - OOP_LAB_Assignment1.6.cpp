// OOP assihnment 1.6                purpose:    Bank cash withdrawal system

#include <iostream>
#include <string>

class bankAccount
{
	private:
		std::string acc_no;   // account no
		int acc_pin;     // account pin
		char acc_type;
		float balance; // account balance
		
	
	public:
		bankAccount(std::string accNo, int accPin, char accType)
		{
			acc_no = accNo;
			acc_pin = accPin;
			acc_type = accType;
			balance = 200000;   // default balance of 200k
		}
		
		void withdraw(float amount)
		{
			if (amount > 100000)
			{
				std::cout << "\nAmount cannot exceed 100,000!";
				return;
			}
			
			if (acc_type == 'S' || acc_type == 's')
			{
				if (amount <= 50000)
				{
					balance -= amount - (amount * 0.02);   // 2% transaction fee
				}
				
				else if (amount > 50000)
				{
					balance -= amount - (amount * 0.05);    // 5% transaction fee for withdrawal above 50k 	
				}
			}
			
			else if (acc_type == 'C' || acc_type == 'c')
			{
				if (amount <= 50000)
				{
					balance -= amount - 100;   //  100 transaction fee
				}
				
				else if (amount > 50000)
				{
					balance -= amount - (amount * 0.05);    // 5% transaction fee for withdrawal above 50k 	
				}	
			}
			
			std::cout << "\nTransaction successful!\nPlease, take your card and cash.";
			std::cout << "\nYour new balance is " << balance;
			
		}
		
};

int main()
{
	std::string accountNo;
	std::cout << "Enter you account number: ";
	std::cin >> accountNo;
	
	int accountPin;
	std::cout << "\nEnter your pin: ";
	std::cin >> accountPin;
	
	char accountType;
	std::cout << "\nEnter your account type: ";
	std::cin >> accountType;
	
	bankAccount user1(accountNo, accountPin, accountType);
	
	float userAmount;
	std::cout << "\nEnter the amount you wish to withdraw: ";
	std::cin >> userAmount;
	
	user1.withdraw(userAmount);
}