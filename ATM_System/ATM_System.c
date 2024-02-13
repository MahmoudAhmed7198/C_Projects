#include<stdio.h>
#include"ATM_System.h"

//3 users with 3 accounts,,arr[0]->account1,arr[1]->account2,arr[2]->account3
Account user_accounts[3]={{11,111,1000},{22,222,2000},{33,333,3000}};


/*the implementations of APIS*/

char id;
char loginToSystem(void)
{
	int password;
	char validity='F';
	int i=3;
	do
	{
	printf("Please insert your account ID:");
	scanf("%d",&id);
	printf("Please insert your password:");
	scanf("%d",&password);
	if(id==user_accounts[0].ID && password==user_accounts[0].password)
	{
		validity='T';
		break;
	}
	else if(id==user_accounts[1].ID && password==user_accounts[1].password)
	{
		validity='T';
		break;
	}
	else if(id==user_accounts[2].ID && password==user_accounts[2].password)
	{
		validity='T';
		break;
	}
	else
	{
		if(i==0)
			break;
		else
		printf("the userID or Password is incorrect, Please try %d Trials!\n",i);
	}
	i--;
	}while(i>=0);
	return validity;

}
void PrintBalance(char accountID)
{

		if(accountID==user_accounts[0].ID)
		{
			printf("the existing balance:%d",user_accounts[0].balance);
		}
		else if(accountID==user_accounts[1].ID)
		{
			printf("the existing balance:%d",user_accounts[1].balance);
		}
		else if(accountID==user_accounts[2].ID)
		{
			printf("the existing balance:%d",user_accounts[2].balance);
		}

	else
		return;

}
void Deposit(char accountID, int cash_amount)
{
		char validate='F';
		if(accountID==user_accounts[0].ID)
		{
			user_accounts[0].balance+=cash_amount;
			validate='T';
		}
		else if(accountID==user_accounts[1].ID)
		{
			user_accounts[1].balance+=cash_amount;
			validate='T';
		}
		else if(accountID==user_accounts[2].ID)
		{
			user_accounts[2].balance+=cash_amount;
			validate='T';
		}
	else
		{
		return;
		}
		printf("%c",validate);
}
void Transfer(char accountID1)
{
	char accountID2;
	char validate='F';
	int required_money;
		printf("Please Enter the accountID2:");
		scanf("%d",&accountID2);
		printf("Enter the required money:");
		scanf("%d",&required_money);
		if(accountID1==user_accounts[0].ID && required_money<=user_accounts[0].balance)
		{
				if(accountID2==user_accounts[1].ID)
				{
					user_accounts[1].balance+=required_money;
					user_accounts[0].balance-=required_money;
					validate='T';
				}
				else if(accountID2==user_accounts[2].ID)
				{
					user_accounts[2].balance+=required_money;
					user_accounts[0].balance-=required_money;
					validate='T';
				}
		}
		else if(accountID1==user_accounts[1].ID && required_money<=user_accounts[1].balance)
		{
				if(accountID2==user_accounts[0].ID)
				{
					user_accounts[0].balance+=required_money;
					user_accounts[1].balance-=required_money;
					validate='T';
				}
				else if(accountID2==user_accounts[2].ID)
				{
					user_accounts[2].balance+=required_money;
					user_accounts[1].balance-=required_money;
					validate='T';
				}

		}
		else if(accountID1==user_accounts[2].ID && required_money<=user_accounts[2].balance)
		{

				if(accountID2==user_accounts[0].ID)
				{
					user_accounts[0].balance+=required_money;
					user_accounts[2].balance-=required_money;
					validate='T';
				}
				else if(accountID2==user_accounts[1].ID)
				{
					user_accounts[1].balance+=required_money;
					user_accounts[2].balance-=required_money;
					validate='T';
				}
		}
	else{
		return;
	}
		printf("%c",validate);

}
char withdraw(char accountID, int cash_amount)
{
	char validate='F';
		if(accountID==user_accounts[0].ID)
		{
			if(cash_amount<=user_accounts[0].balance)
			{
				user_accounts[0].balance-=cash_amount;
				validate='T';
			}
			else
			{
				printf("the balance isn't sufficient\n");
			}
		}
		else if(accountID==user_accounts[1].ID)
		{
			if(cash_amount<=user_accounts[1].balance)
			{
				user_accounts[1].balance-=cash_amount;
				validate='T';
			}
			else
			{
				printf("the balance isn't sufficient\n");
			}
		}
		else if(accountID==user_accounts[2].ID)
		{
			if(cash_amount<=user_accounts[2].balance)
			{
				user_accounts[2].balance-=cash_amount;
				validate='T';
			}
			else
			{
				printf("the balance isn't sufficient\n");
			}
		}


	return validate;

}
