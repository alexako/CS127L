/*
* Programmer: REYES, Alexander Joseph
* Date Created: 7/25/2013
* Terminal No: 33
* Program: BSCS
* Course / Section: CS127L/AT2
* Purpose: This program simulates an ATM program
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>   //Need for fmod() '%' is only for ints

using namespace std;

int selectMenu();
//this function will display the main menu options
//and will return a value of the selected transaction
// the program should validate the input : selection of options should be 1,2,3 and 4 only 
//use do-while loop for validation of option

double depositMoney(double& mon);
//this function will simulate deposit transaction
//this function will update the balance once a successful
//deposit transaction occured.
//this function should not allow deposit if amount to deposit is from 100.00 to 400.00
//for the program not to terminate in this case, perform a do while loop to validate the deposit amount and as the user to re-enter amount of 500 and/or above.

void widrawMoney(double& WMoney);
//this function will simulate withdraw transaction
//balance should be updated once a success withdraw transaction occurred.
//this function should not allow withdrawal if amount to withdraw is less than 500.00
//maximum withdrawal amount is 5000.00
//withdrawal amount should be displayed with the following breakdown: 100,200,500, and 1000
//for example  amount is Php1800.00 breakdowns are:
//    1000 ' 1  =1000.00
//      500 ' 1  = 500.00
//      200 ' 1=   200.00
//      100 ' 1=  100.00
//    Total : Php 1800.00

double balanceInquiry(double cBal);
//this function should display the remaining balance

void quitProgram();
//this function will terminate the program using the exit pre-defined object

char tryAgain();
//this function will ask the user if he wants to do another transaction
//this function should return a char type based on selection made by the user
// Y for yes and N for no will be the ONLY accepted value(s)
//use toupper function for the input
//re-enter the value if the user inputs other character than Y and/or N : use another do-while loop for the validation.

int passWord(int);
//this function handles the testing condition of the entered password by the user
//if password is correct then this will return the value of 1; if not correct this will return the value of -1
//this function is called inside the main menu?

// Comment out if this is not allowed
void clearScreen() {
    #ifdef __cplusplus__
      #include <cstdlib>
    #else
      #include <stdlib.h>
    #endif

    if (system("CLS")) system("clear");
}

// Change back to void type and remove return statement
int main()
{
	double balance=10000.00;
	char ch;
	int select;

	//you can add code here and declaration here
	int pin;
	int attempts = 0;

	do {

		if (attempts >= 3) {
			cerr << endl
				<< "Too many unsuccessful attempts. Exiting program." << endl;
			quitProgram();
		}

		cout << endl << "Enter 4-digit pin: ";
		cin >> pin;

		pin = passWord(pin);
		attempts++;

		if (!pin)
			cout << "Attempt: " << attempts << " out of 3" << endl;

	} while (pin < 1);


	cout<<showpoint<<fixed<<setprecision(2);


	do {

/*      // Uncomment if adding user-defined functions are not allowed
        // Start of simple clear
        #ifdef __cplusplus__
          #include <cstdlib>
        #else
          #include <stdlib.h>
        #endif

        if (system("CLS")) system("clear");
        // end of simple clear
*/

        clearScreen();
		select = selectMenu ();

		switch (select) {
			case 1: clearScreen(); 
			    depositMoney(balance);   //add code here for DepositMoney
				break;
			case 2: clearScreen();
			    widrawMoney(balance);    //add code here for widrawMoney
				break;
			case 3: clearScreen();
			    cout << endl
						<< "Current balance: "
						<< balanceInquiry(balance);    //add code here for balanceInquiry;
				break;
			case 4: quitProgram();   //add code here for quitProgram(); //exit(0);
		}

		//you can add code here

		ch = tryAgain ();

	}while (ch=='Y' || ch == 'y');

	quitProgram();

	return 0; //remove this
}


int passWord(int pwd) {
    /*** Returns true if password if correct ***/
	return (pwd == 1234);
}

char tryAgain() {
    /*** Returns Y/n if user wants another transaction and to return to the main menu ***/
	char again;

	do {
		cout << endl
			 << "Would you like to do another transaction? <Y/n> ";

		cin >> again;

		if (again == 'Y' || again == 'y' || again == 'N' || again == 'n')
			break;

        else {
            clearScreen();
            cerr << "Invalid input: " << again << endl
                << "Try again. " << endl << endl;
        }
        

	} while (true);

	return again;
}


void quitProgram() {
    clearScreen();
	cout << "Thank you for banking with us!" << endl;
	exit(0);
}


double balanceInquiry (double cBal) {
	return cBal;
}


int selectMenu() {
    /*** Outputs the main menu and returns the option selected by user ***/

	int option;
	int attempts = 0;


    // START Menu banner
    for (int i = 0; i < 30; i++)
        cout << "=";
    cout << endl
        << "\tMain Menu"
        << endl;
    for (int i = 0; i < 30; i++)
        cout << "=";        
    cout << endl << endl;
    // END Menu banner
    
	cout << "Menu:" << endl
		<< "\t1. Deposit" << endl
		<< "\t2. Withdraw" << endl
		<< "\t3. Balance Inquiry" << endl
		<< "\t4. Quit" << endl
		<< endl
		<< "Selection: ";

	do {

		cin >> option;

		if (option == 1 || option == 2 || option == 3 || option == 4)
			break;
		else
			cerr << "Invalid option. Please select an option: ";
	} while (true);


	return option;
}


double depositMoney(double& mon) {
    /*** 
        Deposits/adds the amount entered by user if it satisfies the following conditions:
            amount is a multiple of 100
            amount >= 500
    ***/

	double deposit;

    // START Menu banner
    for (int i = 0; i < 30; i++)
        cout << "=";
    cout << endl
        << "\tDeposit Menu"
        << endl;
    for (int i = 0; i < 30; i++)
        cout << "=";        
    cout << endl << endl;
    // END Menu banner

	do {
		cout << endl
			<< "Enter deposit amount: ";

		cin >> deposit;

        bool condition1 = !fmod(deposit, 100);
        bool condition2 = (deposit >= 500);

		if (!condition1) {
			cerr << endl
				<< "Deposit amount must be in increments of 100";
		}
		if (!condition2) {
			cerr << endl
				<< "Deposit amount must be greater than P500.00";
		}
		else if (condition1 && condition2)
			break;

	} while (true);

	mon = mon + deposit;

	cout << endl
		<< "Remaining balance: " << mon << endl
		<< "Transaction complete.";

	return 0;
}


void widrawMoney(double& WMoney) {
    /***
        Withdraws amount entered by user if it satisfies the following conditions:
            500 >= amount <= 5000
            Has sufficient funds remaining
            amount is a multiple of 100
        Also prints the breakdown of the amount dispensed
    ***/


	double withdrawal;
	int thousands, fives, thundreds, hundreds;


    // START Menu banner
    for (int i = 0; i < 30; i++)
        cout << "=";
    cout << endl
        << "\tWithdrawal Menu"
        << endl;
    for (int i = 0; i < 30; i++)
        cout << "=";        
    cout << endl << endl;
    // END Menu banner

    do {
	    cout << endl
		    << "Enter withdrawal amount: ";

	    cin >> withdrawal;

        bool condition1 = (withdrawal >= 500 && withdrawal <= 5000);
        bool condition2 = (withdrawal <= WMoney);
        bool condition3 = !fmod(withdrawal, 100);

		if (!condition1) {
			cerr << endl
				<<"Withdrawal amount must be between P500.00 and P5,000.00 (inclusive)";
		}
		if (!condition2) {
			cerr << endl
				<< "Insufficient funds" << endl
				<< "Remaining balance: " << WMoney;
		}
		if (!condition3) {
			cerr << endl
				<< "Withdrawal amount must be in increments of 100";
		}
		else if (condition1 && condition2 && condition3)
			break;

	} while (true);

	WMoney = WMoney - withdrawal;

	// Dispense output | Breakdown
	thousands = withdrawal / 1000;
	fives = fmod(withdrawal, 1000) / 500;   //(withdrawal % 1000) / 500;
	thundreds = fmod(fmod(withdrawal, 1000), 500) / 200; //((withdrawal % 1000) % 500) / 200;
	hundreds = fmod(fmod(fmod(withdrawal, 1000), 500), 200) / 100; //(((withdrawal % 1000) % 500) % 200) / 100;

	cout << endl
		<< "1000\t" << thousands << " = " << thousands * 1000 << endl
		<< "500\t" << fives << " = " << fives * 500 << endl
		<< "200\t" << thundreds << " = " << thundreds * 200 << endl
		<< "100\t" << hundreds << " = " << hundreds * 100 << endl
        << "==============" << endl
		<< "Total\t" << "Php" << withdrawal
		<< endl;

	cout << endl
		<< "Remaining balance: " << WMoney << endl
		<< "Transaction Complete.";

}

