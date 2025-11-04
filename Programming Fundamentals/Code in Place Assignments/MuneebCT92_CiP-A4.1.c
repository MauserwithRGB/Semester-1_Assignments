#include <stdio.h>
int main(void){
	float price, discount;
	printf("Enter Amount: ");
	scanf("%f", &price);
	if (price < 1000)
	printf("No discount available!");
	else if (price >= 1000 && price <= 2000){
		discount = price * 0.05;
		price = price - discount;
		printf("Your new price is: %.0f\nDiscounted amount: %.2f", price, discount);
	}
	else if (price > 2000) {
		discount = price * 0.1;
		price = price - discount;
		printf("Your new price is: %.0f\nDiscounted amount: %.2f", price, discount);
	}
	
}
