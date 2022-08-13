//Kyle Joseph
//Personal Project
//Purpose: Create a program to allow a user to make a bank account.
//This program uses the following object oriented programming concepts:
//Inheritance, encapsulation, and data Abstraction.

//Within the bank account the user can create an account, login,
//if the user enters the password wrong too many times they will 
//be prompted to make a new password. 
//And then the options after logging in are:
//depositing money, withdrawing money, checking the balance, 
//transferring money, and checking interest accumulation.
//And all of these operations can be done in both checkings and savings accounts.
//Except for the interest accumulation, because that only occurs in savings accounts.



#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;



const int MAX = 50;



//Bank account Base class that contains methods for all of the derived classes to use. 
//This can deposit money, withdraw money, check balance, and transfer money, from either account.
class Account 
{
	public:
		int deposit();
		int withdraw();
		int check_balance();
		int transfer();
	protected:
};



//Derived SavingsAccount class that can calculate interest, transfer money to checkings, and can check it's own balance.
class SavingsAccount: public Account
{
	public:
		SavingsAccount();
		~SavingsAccount();
		int interest_calculation();
		int set_pos_savings_balance(int value);
		int set_neg_savings_balance(int value);
		int get_savings_balance();
	private:
		float interest_percent;
		int savings_balance;

};



//Derived CheckingsAccount class that can transfer money to savings and check it's own balance.
class CheckingsAccount: public Account
{
	public:
		CheckingsAccount();
		~CheckingsAccount();
		int set_pos_checkings_balance(int value);
		int set_neg_checkings_balance(int value);
		int get_checkings_balance();

	private:
		int checkings_balance;

};
