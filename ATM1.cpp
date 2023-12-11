#include <iostream>
#include <conio.h> // affects the output 
using namespace std;

/* A simple ATM Project
With the folLowing features:
check Balance
Cash Withdraw
User Details
Update Mobile Number
*/

class atm
{
private:
    long int account_no;
    string name;
    int pin;
    double balance;
    string mobile_no;

public:
    //setfunction to set the data of private variables
    void setData(long int account_no_a, string name_a, int pin_a, double balance_a, string mobile_no_a)
    {
        account_no = account_no_a;
        name = name_a;
        pin = pin_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    //getfunction returns/gets data from priavte variables
    getName()
    {
        return name;
    }

    getAccountNo()
    {
        return account_no;
    }

    getPin()
    {
        return pin;
    }

    getBalance()
    {
        return balance;
    }

    getMobileNo()
    {
        return mobile_no;
    }
}
// setfunction updates mobile no.
void setMobile(string mob_prev, string mob_new)		
	{
		if (mob_prev == mobile_no)						// checks old Mobile no(if it exits or is correct)
		{
			mobile_no = mob_new;						// Update old number with a new number
			cout << endl << "***Sucessfully Updated Mobile Number***.";
			_getch();				//getch is to hold the screen ( untill user press any key )																			
		}

		else							// When number doesn't match the records, don't update.
		{
			cout << endl << "!!!!___Incorrect Old Mobile no___!!!!";
			_getch();			  //getch is to hold the screen ( untill user press any key )
		}
	}

    
        	//cashWithDraw function is used to withdraw money from ATM
	void cashWithDraw(int amount)
	{
		if (amount > 0 && amount < balance)		// check entered amount validity
		{
			balance -= amount;		// (balance = balance - amount)
			cout << endl << "Here is Your Cash" << endl;
			cout << endl << "Your Available Balance is :" << balance;
			_getch();				//getch is to hold the screen(untill user press any key )
		}

		else
		{
			cout << endl << "Invalid Input or Insufficient Balance";
			_getch();				//getch is to hold the screen ( untill user press any key )
		}
	}

};




int main() 
{
    int option = 0; //choice on the menu
    int enterPin;
    long int enterAccountNo;

    system("cls"); //clears screen

    atm user1; //create a user 1(object)
    //account number(13 values), Name of user, pin(4 digits), account balance and mobile enumber 
    user1.setData(1002500121231, "Kofi Quaye", 3321, 99000.90, "+233541148867"); //add user details 


	do
	{
		system("cls");

		cout << "#*****WELCOME, ATM AT YOUR SERVICE *****#" << endl;
		cout << "Enter Your Account No: ";	  // asking user to enter account no
		cin >> enterAccountNo;

		cout << endl << "Enter PIN: ";				 // asking user to enter PIN
		cin >> enterPin;



		// check whether enter values matches with user details
		if ((enterAccountNo == user1.getAccountNo()) && (enterPin == user1.getPin()))
		{

            do
	        {
		        int amount = 0;
				string mob_prev;
                string mob_new; 

				system("cls");
				// (UI) user Interface
				cout << endl << "#*****WELCOME, ATM AT YOUR SERVICE *****#" << endl;
				cout << endl << "Select Option(s) ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> option;						// taking user choice

				switch (option)						// switch condition
				{
				case 1:								// if user presses 1 
					cout << endl << "Your Account balance is :" << user1.getBalance(); 
													// getBalance is ... printing the users									bank balance
					_getch();
					break;


				case 2:									// if user presses 2
					cout << endl << "Enter the amount :";		
					cin >> amount;
					user1.cashWithDraw(amount);			// calling cashWithdraw function 
													    // passing the withdraw amount 
					break;


				case 3:										// if user presses 3
					cout << endl << "*** These Are Your Details :- ";
					cout << endl << "-> Account no" << user1.getAccountNo();
					cout << endl << "-> Name      " << user1.getName();
					cout << endl << "-> Balance   " << user1.getBalance();
					cout << endl << "-> Mobile No." << user1.getMobileNo();
													// getting and printing user details
					_getch();
					break;


				case 4:								   //  if user presses 4
					cout << endl << "Enter Old Mobile No. ";
					cin >> mob_prev;							// take old mobile no

					cout << endl << "Enter New Mobile No. ";
					cin >> mob_new;							// take new mobile no

					user1.setMobile(mob_prev, mob_new);	// now set new mobile no
					break;

													// if user presses 5
				case 5:
					exit(0);						// exit application

				default:							// handle invalid user inputs
					cout << endl << "Enter Valid Value/digit !!!";
				} 

			} while (1);				// MENU	   // condition will always TRUE and loop is										capable of running infinite times
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			_getch();
		}
	} while (1);						//LOGIN		// condition will always TRUE and loop is										capable of running infinite times

	return 0;
}






