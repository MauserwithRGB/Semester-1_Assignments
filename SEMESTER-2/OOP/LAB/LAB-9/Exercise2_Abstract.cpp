// Exercise 2: Store discount system using abstract class and virtual functions

#include <iostream>

class Store
{
	protected:
		float total_bill;
		
	public:
		// Constructor
		Store(float bill)
		{
			total_bill = bill;
		}
		
		// Pure virtual function
		virtual float calculateFinalBill() = 0;
		
		// Function to display bill details
		virtual void displayBill() = 0;
};

class ImtiazStore : public Store
{
	private:
		float discount;
		
	public:
		// Constructor
		ImtiazStore(float bill) : Store(bill)
		{
			discount = 0.07; // 7% discount
		}
		
		// Implementation of pure virtual function
		float calculateFinalBill()
		{
			float discountAmount = total_bill * discount;
			float finalBill = total_bill - discountAmount;
			return finalBill;
		}
		
		// Display bill details
		void displayBill()
		{
			std::cout << "\n--- Imtiaz Store Bill ---";
			std::cout << "\nTotal Bill: " << total_bill << " PKR";
			std::cout << "\nDiscount: " << (discount * 100) << "%";
			std::cout << "\nDiscount Amount: " << (total_bill * discount) << " PKR";
			std::cout << "\nFinal Bill: " << calculateFinalBill() << " PKR";
			std::cout << "\n";
		}
};

class BinHashimStore : public Store
{
	private:
		float discount;
		
	public:
		// Constructor
		BinHashimStore(float bill) : Store(bill)
		{
			discount = 0.05; // 5% discount
		}
		
		// Implementation of pure virtual function
		float calculateFinalBill()
		{
			float discountAmount = total_bill * discount;
			float finalBill = total_bill - discountAmount;
			return finalBill;
		}
		
		// Display bill details
		void displayBill()
		{
			std::cout << "\n--- Bin Hashim Store Bill ---";
			std::cout << "\nTotal Bill: " << total_bill << " PKR";
			std::cout << "\nDiscount: " << (discount * 100) << "%";
			std::cout << "\nDiscount Amount: " << (total_bill * discount) << " PKR";
			std::cout << "\nFinal Bill: " << calculateFinalBill() << " PKR";
			std::cout << "\n";
		}
};

int main()
{
	float billAmount;
	
	std::cout << "=== Store Discount System ===\n";
	std::cout << "\nEnter total bill amount: ";
	std::cin >> billAmount;
	
	// Creating store objects
	ImtiazStore imtiaz(billAmount);
	BinHashimStore binHashim(billAmount);
	
	// Displaying bills for both stores
	imtiaz.displayBill();
	binHashim.displayBill();
	
	// Using polymorphism with base class pointer
	std::cout << "\n\n--- Using Polymorphism ---";
	Store* storePtr;
	
	storePtr = &imtiaz;
	std::cout << "\nImtiaz Store Final Bill: " << storePtr->calculateFinalBill() << " PKR";
	
	storePtr = &binHashim;
	std::cout << "\nBin Hashim Store Final Bill: " << storePtr->calculateFinalBill() << " PKR";
	std::cout << "\n";
	
	return 0;
}
