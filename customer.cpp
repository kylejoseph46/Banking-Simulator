#include "customer.h"



//Customer Functions implemenation:



Customer::Customer()
{
	username = nullptr;
	password = nullptr;
}



Customer::~Customer() 
{


}



int Customer::create_account()
{
	char user[MAX];
	cout << "Enter a username" << endl;
	cin >> user;
	cin.ignore(100, '\n');

	username = new char[strlen(user) +1];
	strcpy(username, user);


	char pass[MAX];
	cout << "Enter a password" << endl;
	cin >> pass;
	cin.ignore(100, '\n');

	password = new char[strlen(pass) +1];
	strcpy(password, pass);

	return 0;
}



int Customer::login()
{
	cout << endl << "Login to your account: " << endl << endl;

	char user[MAX];
	cout << "Enter your username" << endl;
	cin >> user;
	cin.ignore(100, '\n');


	char pass[MAX];
	cout << "Enter your password" << endl;
	cin >> pass;
	cin.ignore(100, '\n');

	if(strcmp(user, username) == 0 && strcmp(pass, password) == 0)
	{
		cout << "You successfully logged in!" << endl;
		return 0;
	} 

	return 1;
}



char *& Customer::get_username() 
{
	return username;
}



char *& Customer::get_password() 
{
	return password;
}



