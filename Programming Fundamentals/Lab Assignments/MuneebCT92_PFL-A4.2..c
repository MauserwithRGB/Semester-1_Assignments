#include<stdio.h>
int main(void)
{
    float amount, amountnew, discount;
    printf("Upto 50% Discount on Worth More than Rs 1,999\n");
    printf("\nEnter Your Amount: ");
    scanf("%f", &amount);

    if (amount < 1999){
        printf("No Discount Available!");
    }
    else if (amount > 1999 && amount <= 4000){
        amountnew = amount - 0.2 * amount ;
        discount = amount - amountnew;
        printf("\nNew Price: %0.2f\n\nDiscounted Amount: %0.2f\n\nOriginal Price: %0.2f", amountnew, discount, amount);
    }
    else if (amount > 4000 && amount <= 6000){
        amountnew = amount - 0.3 * amount;
        discount = amount - amountnew;
        printf("\nNew Price: %0.2f\n\nDiscounted Amount: %0.2f\n\nOriginal Price: %0.2f", amountnew, discount, amount);
    }
    else {
        amountnew = amount - 0.5 * amount;  
        discount = amount - amountnew;
        printf("\nNew Price: %0.2f\n\nDiscounted Amount: %0.2f\n\nOriginal Price: %0.2f", amountnew, discount, amount);
    }
    return 0;
}