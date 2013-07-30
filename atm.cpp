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
#include <math.h>	//Need for fmod() '%' is only for ints

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

// Comment out the following function definitions if this is not allowed
void clearScreen() {
    write(1,"\E[H\E[2J",7);
}

void PrintBanner(const char* operation) {
    /*** Prints banner on top of the screen for each operation ***/

	for (int i = 0; i < 30; i++) {cout << "=";}
	cout << endl
		 << "\t  " << operation
		 << endl;
	for (int i = 0; i < 30; i++) {cout << "=";}
	cout << endl << endl;
}


// Change back to void type and remove return statement
int main()
{
	double balance = 10000.00;
	char ch;
	int select;

	//you can add code here and declaration here
	int pin;
	int attempts = 1;


	do {

		if (attempts >= 4) {
			cerr << endl
				<< "Too many unsuccessful attempts. Exiting program..." << endl;
			quitProgram();
		}

		//Remove if User-defined functions are not allowed
		clearScreen();

		if (attempts > 1)
			cout << "Attempt: " << attempts << " out of 3" << endl;

		cout << "Enter 4-digit pin: ";
		cin >> pin;

		pin = passWord(pin);
		attempts++;

	} while (pin < 1);

	cout << showpoint << fixed << setprecision(2);


	do {

		//Remove if User-defined functions are not allowed
		clearScreen();

		select = selectMenu ();

		switch (select) {
			case 1: clearScreen(); // <---- Remove if User-defined functions are not allowed
				depositMoney(balance);   //add code here for DepositMoney
				break;
			case 2: clearScreen(); // <---- Remove if User-defined functions are not allowed
				widrawMoney(balance);    //add code here for widrawMoney
				break;
			case 3: clearScreen(); // <---- Remove if User-defined functions are not allowed
				cout << endl
						<< "Current balance: "
						<< balanceInquiry(balance);    //add code here for balanceInquiry;
				break;
			case 4: quitProgram();   //add code here for quitProgram(); //exit(0);
		}

		//you can add code here

		ch = tryAgain ();

	} while (ch == 'Y' || ch == 'y');

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

		clearScreen(); //<---- Remove if User-defined functions are not allowed
		cerr << "Invalid input: " << again << endl
             << "Try again. " << endl;

	} while (!(again == 'Y' || again == 'y' || again == 'N' || again == 'n'));

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


	// Remove if User-defined functions are not allowed
	PrintBanner("Main Menu");

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
	bool condition[2];

	// Remove if User-defined functions are not allowed
	PrintBanner("Deposit");

	do {

		cout << endl
			 << "Enter deposit amount: ";

		cin >> deposit;

		// Remove if User-defined functions are not allowed
		clearScreen();

		condition[0] = !fmod(deposit, 100);
		condition[1] = (deposit >= 500);

		if (!condition[0]) {
			cerr << endl
				 << "Deposit amount must be in increments of 100";
		}
		if (!condition[1]) {
			cerr << endl
				 << "Deposit amount must be greater than P500.00";
		}
		else if (condition[0] && condition[1])
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
	bool condition[3];
	int thousands,
		fives,
		thundreds,
		hundreds;

	// Remove if User-defined functions are not allowed
	PrintBanner("Withdrawal");

	do {

		cout << endl
			 << "Enter withdrawal amount: ";

		cin >> withdrawal;

		// Remove if User-defined functions are not allowed
		clearScreen();

		condition[0] = (withdrawal >= 500 && withdrawal <= 5000);
		condition[1] = (withdrawal <= WMoney);
		condition[2] = !fmod(withdrawal, 100);

		if (!condition[0]) {
			cerr << endl
				 <<"Withdrawal amount must be between P500.00 and P5,000.00 (inclusive)";
		}
		if (!condition[1]) {
			cerr << endl
				 << "Insufficient funds" << endl
				 << "Remaining balance: " << WMoney;
		}
		if (!condition[2]) {
			cerr << endl
				 << "Withdrawal amount must be in increments of 100";
		}
		else if (condition[0] && condition[1] && condition[2])
			break;

	} while (true);

	WMoney = WMoney - withdrawal;

    // Remove if User-defined functions are not allowed
    clearScreen();
    PrintBanner("Dispense");

	// Dispense output | Breakdown Calculation
	thousands = withdrawal / 1000;
	fives = fmod(withdrawal, 1000) / 500;
	thundreds = fmod(fmod(withdrawal, 1000), 500) / 200;
	hundreds = fmod(fmod(fmod(withdrawal, 1000), 500), 200) / 100;

	cout << endl
		 << "1000\t" << thousands << " = " << thousands * 1000 << endl
		 << "500\t" << fives << " = " << fives * 500 << endl
		 << "200\t" << thundreds << " = " << thundreds * 200 << endl
		 << "100\t" << hundreds << " = " << hundreds * 100 << endl
		 << "==============" << endl
		 << "Total\t" << "Php" << withdrawal
		 << endl;

	cout << endl
	     << "Transaction complete." << endl
		 << "Remaining balance: " << WMoney << endl
		 << endl;

}

