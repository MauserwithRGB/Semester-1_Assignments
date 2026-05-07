// Exercise 3: Account class with static variable to count objects

#include <iostream>

class Account
{
	private:
		int account_no;
		float account_bal;
		int security_code;
		static int objectCount;
		
	public:
		Account()
		{
			objectCount++;
		}
		
		void initialize(int acc_no, float bal, int sec_code)
		{
			account_no = acc_no;
			account_bal = bal;
			security_code = sec_code;
		}
		
		void printData()
		{
			std::cout << "\n--- Account Details ---";
			std::cout << "\nAccount Number: " << account_no;
			std::cout << "\nAccount Balance: " << account_bal;
			std::cout << "\nSecurity Code: " << security_code;
			std::cout << "\n";
		}
		
		static int getObjectCount()
		{
			return objectCount;
		}
};

int Account::objectCount = 0;

int main()
{
	Account acc1;
	acc1.initialize(12345, 50000.50, 1111);
	
	Account acc2;
	acc2.initialize(67890, 75000.75, 2222);
	
	Account acc3;
	acc3.initialize(11223, 100000.00, 3333);
	
	acc1.printData();
	acc2.printData();
	acc3.printData();
	
	std::cout << "\nTotal number of Account objects created: " << Account::getObjectCount() << "\n";
	
	return 0;
}