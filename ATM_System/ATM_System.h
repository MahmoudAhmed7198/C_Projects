

/*struct which contains IDs, passwords and the current balance*/

typedef struct
{
	char ID;
	int password;
	int balance;
}Account;

/*Prototypes of APIS*/
char loginToSystem(void);
void PrintBalance(char accountID);
void Deposit(char accountID, int cash_amount);
void Transfer(char accountID1);
char withdraw(char accountID, int cash_amount);
