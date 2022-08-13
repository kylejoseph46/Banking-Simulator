#include "customer.h"



//Implementation of the account related functions:




//Initializing SavingsAccount data members.
SavingsAccount::SavingsAccount()
{	
	interest_percent = 0.02;
	savings_balance = 0;
}



SavingsAccount::~SavingsAccount() 
{
	//Nothing needs to be deallocated.

}



//Initializing CheckingsAccount data members.
CheckingsAccount::CheckingsAccount() 
{

	checkings_balance = 0;

}



CheckingsAccount::~CheckingsAccount() 
{

	//Nothing needs to be deallocated.

}



//This deposit function returns either a 1 or 2 for the savings or checkings account to choose which account to deposit into.
int Account::deposit() 
{
	int SorC = 0;
	cout << "Would you like to add to the savings account or checkings account?" << endl;
	cout <<"1| Savings" << endl;
	cout << "2| Checkings" << endl;			
	cin >> SorC;
	cin.ignore(100, '\n');

	if(SorC == 1) 
	{
		return 1;
	}

	if(SorC == 2) 
	{
		return 2;
	}

	cout << "Money not deposited :(" << endl;	
	return 0;
}



//This withdraw function returns either a 1 or 2 for the savings or checkings account to choose which account to withdraw from.
int Account::withdraw() 
{

	int SorC = 0;
	cout << "Would you like to withdraw from the savings account or checkings account?" << endl;
	cout <<"1| Savings" << endl;
	cout << "2| Checkings" << endl;			
	cin >> SorC;
	cin.ignore(100, '\n');

	if(SorC == 1) 
	{
		return 1;
	}

	if(SorC == 2) 
	{
		return 2;
	}
	return 0;
}



//This check_balance function returns either a 1 or 2 for the savings or checkings account to choose which account to check the balance of.
int Account::check_balance() 
{

	int SorC = 0;
	cout << "Would you like to check the balance of the savings account or checkings account?" << endl;
	cout <<"1| Savings" << endl;
	cout << "2| Checkings" << endl;			
	cin >> SorC;
	cin.ignore(100, '\n');

	if(SorC == 1) 
	{
		//cout << Sobj.get_savings_balance() << endl;
		return 1;
	}

	if(SorC == 2) 
	{
		//cout << Cobj.get_checkings_balance() << endl;
		return 2;
	}

	return 0;
} 



//This transfer function returns either a 1 or 2 for the savings or checkings account to choose which account to transfer from and into.
int Account::transfer()
{	
	int SorC = 0;
	cout << "Would you like to transfer money to the savings account or checkings account?" << endl;
	cout <<"1| Savings" << endl;
	cout << "2| Checkings" << endl;			
	cin >> SorC;
	cin.ignore(100, '\n');

	if(SorC == 1) 
	{
		return 1;
	}

	if(SorC == 2) 
	{
		return 2;
	}

	return 0; 
}



//This function allows us to add to our balance in the savings account.
int SavingsAccount::set_pos_savings_balance(int value) 
{
	savings_balance += value;	
	return 0;
}




//This function allows us to subtract from our balance in the savings account.
int SavingsAccount::set_neg_savings_balance(int value) 
{
	savings_balance -= value;	
	return 0;
}



//This function allows us to add to our balance in the checkings account.
int CheckingsAccount::set_pos_checkings_balance(int value) 
{
	checkings_balance += value;
	return 0;
}



//This function allows us to subtract from our balance in the checkings account.
int CheckingsAccount::set_neg_checkings_balance(int value) 
{
	checkings_balance -= value;
	return 0;
}



//This function allows us to retrieve our balance in the savings account.
int SavingsAccount::get_savings_balance()
{
	return savings_balance;
}



//This function allows us to retrieve our balance in the checkings account.
int CheckingsAccount::get_checkings_balance()
{
	return checkings_balance;
}



//This function calculates the interest of the balance in an account and returns total of the interest added onto the balance.
int SavingsAccount::interest_calculation() 
{
	float total_interest = 0;
	float balance_after_interest = 0;
	int num_of_years = 0; 
	float calc_hold = 0;
	cout << "How many years will this money be in your account for? " << endl;
	cin >> num_of_years;			
	cin.ignore(100, '\n');

	total_interest = num_of_years * interest_percent; 	
	calc_hold = savings_balance * total_interest;
	balance_after_interest = calc_hold + savings_balance;

	cout << "This is your balance after interest is applied: " << endl;

	return balance_after_interest;
}



