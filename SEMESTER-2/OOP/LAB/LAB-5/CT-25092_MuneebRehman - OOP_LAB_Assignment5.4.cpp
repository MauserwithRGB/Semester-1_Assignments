// Exercise 4: Bakery billing system with inheritance

#include <iostream>
#include <string.h>

class Item
{
	protected:
		char* Name;
		int Quantity;
		
	public:
		Item()
		{
			Name = NULL;
			Quantity = 0;
		}
		
		~Item()
		{
			if (Name != NULL)
			{
				delete[] Name;
			}
		}
		
		void setName(const char* name)
		{
			if (Name != NULL)
			{
				delete[] Name;
			}
			Name = new char[strlen(name) + 1];
			strcpy(Name, name);
		}
		
		void setQuantity(int qty)
		{
			Quantity = qty;
		}
		
		const char* getName()
		{
			return Name;
		}
		
		int getQuantity()
		{
			return Quantity;
		}
		
		virtual float calculateTotal()
		{
			return 0.0;
		}
};

class BakedGoods : public Item
{
	protected:
		float Discount;
		
	public:
		BakedGoods()
		{
			Discount = 0.10;
		}
		
		float getDiscount()
		{
			return Discount;
		}
};

class Cakes : public BakedGoods
{
	private:
		float Price;
		
	public:
		Cakes()
		{
			Price = 600.0;
			setName("Cake");
		}
		
		float getPrice()
		{
			return Price;
		}
		
		float calculateTotal()
		{
			float total = Price * Quantity;
			float discountAmount = total * Discount;
			return total - discountAmount;
		}
		
		void displayBill()
		{
			std::cout << "\nItem: " << Name;
			std::cout << "\nQuantity: " << Quantity;
			std::cout << "\nPrice per unit: " << Price;
			std::cout << "\nDiscount: " << (Discount * 100) << "%";
			std::cout << "\nTotal: " << calculateTotal() << " PKR";
		}
};

class Bread : public BakedGoods
{
	private:
		float Price;
		
	public:
		Bread()
		{
			Price = 200.0;
			setName("Bread");
		}
		
		float getPrice()
		{
			return Price;
		}
		
		float calculateTotal()
		{
			float total = Price * Quantity;
			float discountAmount = total * Discount;
			return total - discountAmount;
		}
		
		void displayBill()
		{
			std::cout << "\nItem: " << Name;
			std::cout << "\nQuantity: " << Quantity;
			std::cout << "\nPrice per unit: " << Price;
			std::cout << "\nDiscount: " << (Discount * 100) << "%";
			std::cout << "\nTotal: " << calculateTotal() << " PKR";
		}
};

class Drinks : public Item
{
	private:
		float Discount;
		float Price;
		
	public:
		Drinks()
		{
			Discount = 0.05;
			Price = 100.0;
			setName("Drink");
		}
		
		float getDiscount()
		{
			return Discount;
		}
		
		float getPrice()
		{
			return Price;
		}
		
		float calculateTotal()
		{
			float total = Price * Quantity;
			float discountAmount = total * Discount;
			return total - discountAmount;
		}
		
		void displayBill()
		{
			std::cout << "\nItem: " << Name;
			std::cout << "\nQuantity: " << Quantity;
			std::cout << "\nPrice per unit: " << Price;
			std::cout << "\nDiscount: " << (Discount * 100) << "%";
			std::cout << "\nTotal: " << calculateTotal() << " PKR";
		}
};

int main()
{
	int numCakes, numBread, numDrinks;
	float grandTotal = 0.0;
	
	std::cout << "=== Bakery Billing System ===\n";
	
	std::cout << "\nEnter quantity of Cakes: ";
	std::cin >> numCakes;
	Cakes cakeOrder;
	cakeOrder.setQuantity(numCakes);
	
	std::cout << "Enter quantity of Bread: ";
	std::cin >> numBread;
	Bread breadOrder;
	breadOrder.setQuantity(numBread);
	
	std::cout << "Enter quantity of Drinks: ";
	std::cin >> numDrinks;
	Drinks drinkOrder;
	drinkOrder.setQuantity(numDrinks);
	
	std::cout << "\n\n=== Customer Bill ===";
	
	if (numCakes > 0)
	{
		std::cout << "\n";
		cakeOrder.displayBill();
		grandTotal = grandTotal + cakeOrder.calculateTotal();
	}
	
	if (numBread > 0)
	{
		std::cout << "\n";
		breadOrder.displayBill();
		grandTotal = grandTotal + breadOrder.calculateTotal();
	}
	
	if (numDrinks > 0)
	{
		std::cout << "\n";
		drinkOrder.displayBill();
		grandTotal = grandTotal + drinkOrder.calculateTotal();
	}
	
	std::cout << "\n\n--- Grand Total: " << grandTotal << " PKR ---\n";
}