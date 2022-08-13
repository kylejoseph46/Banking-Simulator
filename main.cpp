#include "customer.h"



//Main.cpp will act as a manager:



int main()
{
	//Class Objects:
	Account AccountObj;
	SavingsAccount SavingObj;
	CheckingsAccount CheckingObj;
	Customer CustomerObj;

	//Variables:
	char first_time = '\0';
	int option1 = 0;
	char login_check = '\0';
	char again = '\0';
	int deposit_value = 0;
	int withdraw_value = 0;
	int transfer_value = 0;


	//Menu: 
	cout << "Is this your first time logging in? If it is, type 'Y':" << endl;
	cin >> first_time;
	cin.ignore(100, '\n');

	if(first_time = 'Y') 
	{
		cout << "Here let's create an account then!" << endl;
		CustomerObj.create_account();			
	}

	int login_hold = CustomerObj.login();
	if(login_hold == 1) 
	{
		cout << "You entered the wrong login information, would you like to try again or reset your password?? Enter Y for yes:" << endl;
		cin >> login_check;
		cin.ignore(100, '\n');
		if(login_check == 'Y') 
		{
			if(CustomerObj.login() != 0) 
			{
				cout << endl << "You clearly forgot your username and password. Let's reset it." << endl;
				CustomerObj.create_account();			
				login_hold = CustomerObj.login();
			}
			else
			{
				login_hold = 0; 
			}
		}
	}
	//Use this return value for the next part. 

	if(login_hold == 0) 
	{
		do { 
			cout << "Here are your options: " << endl;
			cout << "1| Deposit money" << endl;
			cout << "2| Withdraw money" << endl;
			cout << "3| Check Balance" << endl;
			cout << "4| Check interest affect in savings account" << endl;
			cout << "5| Transfer money to another account" << endl;
			cin >> option1;
			cin.ignore(100 ,'\n');


			//Deposit money:
			if(option1 == 1)	
			{
				cout << "How much would you like to deposit? " << endl;
				cin >> deposit_value;
				cin.ignore(100, '\n');	

				int deposit_hold = AccountObj.deposit();
				if(deposit_hold == 1) 
				{ 
					SavingObj.set_pos_savings_balance(deposit_value);
				}

				if(deposit_hold == 2) 
				{ 
					CheckingObj.set_pos_checkings_balance(deposit_value);
				}
			}

			//Withdraw Money:
			if(option1 == 2) 
			{
				//Withdraw	
				cout << "How much would you like to withdraw? " << endl;
				cin >> withdraw_value;
				cin.ignore(100, '\n');	

				int withdraw_hold = AccountObj.withdraw();
				if(withdraw_hold == 1) 
				{ 
					if(withdraw_value > SavingObj.get_savings_balance()) 
						cout << "You do not have enough balance in your account to withdraw that much money!" << endl;	
					else
						SavingObj.set_neg_savings_balance(withdraw_value);
				}

				if(withdraw_hold == 2) 
				{ 
					CheckingObj.set_neg_checkings_balance(withdraw_value);
				}
			}

			//Check Balance:
			if(option1 == 3) 
			{
				int check_balance_hold = AccountObj.check_balance();
				if(check_balance_hold == 1) 
				{ 
					cout << CustomerObj.get_username() << "'s Balance is: $" << SavingObj.get_savings_balance() << endl;
				}

				if(check_balance_hold == 2) 
				{ 
					cout << CustomerObj.get_username() << "'s Balance is: $" << CheckingObj.get_checkings_balance() << endl;
				}
			}

			//Check total after interest is applied.
			if(option1 == 4) 
			{	
				cout << SavingObj.interest_calculation() << endl;
			}

			if(option1 == 5)
			{
				cout << "How much would you like to transfer? " << endl;
				cin >> transfer_value;
				cin.ignore(100, '\n');	

				int transfer_hold = AccountObj.transfer();
				if(transfer_hold == 1) 
				{ 
					if(transfer_value > SavingObj.get_savings_balance()) 
						cout << "You do not have enough balance in your account to transfer that much money!" << endl;	
					else
					{
						SavingObj.set_pos_savings_balance(transfer_value);
						CheckingObj.set_neg_checkings_balance(transfer_value);
					} 
				}

				if(transfer_hold == 2) 
				{
					if(transfer_value > CheckingObj.get_checkings_balance()) 
						cout << "You do not have enough balance in your account to transfer that much money!" << endl;	
					else
					{ 
						CheckingObj.set_pos_checkings_balance(transfer_value);
						SavingObj.set_neg_savings_balance(transfer_value);
					} 
				}
			}


			cout << "Would you like to do something else? If no do NOT enter 'Y': " << endl;
			cin >> again;
			again = toupper(again);
			cin.ignore(100, '\n');
		}while(again == 'Y');
	}

	return 0;
}
