#include "account.h"



//Header file for the user:



//Includes all information for the user.
class Customer
{
	public:
		Customer();
		~Customer();
		int create_account();
		int login();
		char *& get_username();
		void set_username(char * name);
		char *& get_password();
		void set_password(char * pass);

	private:
		char * username;
		char * password;
};
