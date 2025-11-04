#include <stdio.h>
int main(void){
	int balance, withdraw, deposit, menu;
	balance = 542310;
	printf("Welcome!\n\nInsert your card.\n\nSelect an option:\n\n");
	printf("1: Withdraw cash \t 2: Check balance \t 3: Deposit cash\n");
	scanf("%d", &menu);
	switch (menu){
		case 1:
			printf("Enter amount: ");
			scanf("%d", &withdraw);
			balance = balance - withdraw;
			printf("\nPlease, take your card.\n\nYour new balance is %d", balance);
			break;
		case 2:
			printf("\nPlease, take your card.\n\nYour balance is %d.", balance);
			break;
		case 3:
			printf("\nEnter amount to be deposited: ");
			scanf("%d", &deposit);
			balance = balance + deposit;
			printf("\nPlease, take your card.\n\nYour new balance is %d", balance);
			break;
			default:
				printf("\nInvalid option!");
	}
}
