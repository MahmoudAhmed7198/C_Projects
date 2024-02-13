/*
 * main.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Lenovo
 */

#include<stdio.h>
#include<stdlib.h>
#include"ATM_System.h"

extern char id;

int main(void)
{
	setbuf(stdout,NULL);
	char other_trans,validation;
	int transaction,cash_money;
	printf("Welcome To ATM System\n");
	validation=loginToSystem();
	if(validation=='T')
	{
	do{
		printf("Enter the transaction:-\n");
		printf("Press '1' for balance inquiry\n");
		printf("Press '2' for Deposit money\n");
		printf("Press '3' for Transfer money\n");
		printf("Press '4' for Withdraw money\n");
		scanf("%d",&transaction);
		switch(transaction)
		{
		case 1:
			PrintBalance(id);
			break;
		case 2:
			printf("Enter money you want to deposit:");
			scanf("%d",&cash_money);
			Deposit(id, cash_money);
			break;
		case 3:
			Transfer(id);
			break;
		case 4:
			printf("Enter the money you want to withdraw:");
			scanf("%d",&cash_money);
			char validate=withdraw(id, cash_money);
			printf("%c",validate);
			break;
		}

	    printf("\nfor another transaction press 'Y' and 'N' to exit:");
	    scanf(" %c",&other_trans);
	  }while(other_trans=='Y');
	}

	else if(validation=='F')
	{
		printf("the account has locked,call customer service\n");
	}
	printf("Thank You for using ATM System!");


	return 0;
}



