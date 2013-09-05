/*
* Programmer: REYES, Alexander
* Date Created: 9/5/2013
* Terminal No: 33
* Program: BSCS
* Course / Section: CS127L/AT2
* Purpose: This program will calculate the speed from distance over time
*/

#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>

using namespace std;

#ifdef __WIN32
#include<conio.h> //using curses.h
#include<windows.h> //Need this! Find linux version
#endif
#ifdef __linux
#include <curses.h>
#include <unistd.h>
#endif


void counting();
void palindrome(char sal[120]);
void password();
char menu();
void quit();

string EnterPassword();


int main() //change back to void type
{
//add all your code here
    char choice;

    password();

    while (true) {
        try {
            choice = menu();
            
            switch(choice) {
                case 'a':
                        break;
                case 'b':
                        break;
                case 'c':
                        quit();
                default:
                    throw choice;
            }
        }
        catch(char) {
            cerr << "Invalid option.";
            #ifdef _WIN32
            Sleep(700);
            #endif
            #ifdef _linux
            usleep(1)
            #endif
        }
    }

    return 0; //Remove
}
void counting()
{
//add all your code here

}
void palindrome(char sal[120])
{
//add all your code here

}
void password()
{
//add all your code here

    #ifdef _WIN32
    system("CLS");
    #endif

    initscr(); //Remove curses.h

    printw("Enter password\n> "); //change to conio.h

    string pass;
    int counter = 0;

    while (counter < 3) {

        pass = EnterPassword();

        if (pass == "k1udgedit") {
            printw("Welcome. Loading Main Menu"); //change to conio.h

            for (int i = 0; i < 5; i++) {
                #ifdef _WIN32
                Sleep(700);
                #endif
                #ifdef _linux
                usleep(1);
                #endif
                printw(".");
            }
            break;
        }
        else {
            #ifdef _WIN32
            system("CLS");
            #endif
            printw("Incorrect. Try again.\n> "); //change to conio.h
            counter += 1;
        }

        if (counter >= 3) {
            cout << "Too many failed attempts. Exiting program...\n\n";
            #ifdef _WIN32
            Sleep(1000);
            exit(0);
            #endif
        }


    }

    endwin(); //Remove curses.h
}
char menu()
{
//add all your code here

    char option;

    #ifdef _WIN32
    system("CLS");
    #endif


    cout << "========== Menu ==========\n"
         << "  Operations: \n"
         << "\t [a] Something \n"
         << "\t [b] Something \n"
         << "\t [c] Something \n"
         << "> ";
    cin >> option;

    return option;
}

void quit()
{
//add all your code here
    #ifdef _WIN32
    system("CLS");
    #endif

    cout << "Are you sure you want to quit? <y/N>: ";
    char confirm;
    while (true) {
        try {
            cin >> confirm;

            if (!cin || !isalpha(confirm))
                throw confirm;
            else if (confirm == 'y' || confirm == 'Y')
                exit(0);
            else
                main();
        }
        catch(char) {
            #ifdef _WIN32
            system("CLS");
            #endif
            cerr << "Invalid option. Try again.\n> ";
        }
    }

}

string EnterPassword()
{
//add all your code here
    const char BACKSPACE = 127; 
    const char RETURN = 10; // 10 for curses.h, 13 for conio.h

    string entry;
    char key = 0;

    noecho(); //Disable echoing
    while ((key = getch()) != RETURN) {
        
        if (key == BACKSPACE) {
            if(entry.length() >= 0) {
                printw("\b \b"); //Needs lab testing
                entry.resize(entry.size()-1);
            }   
        }
        else {
            entry += key;
            printw("*"); //Need lab testing
        }
    }

    echo(); //Restore echo
    printw("\n"); //Needs lab testing

    return entry;
}
