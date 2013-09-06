/*
* Programmer: REYES, Alexander
* Date Created: 9/5/2013
* Terminal No: 33
* Program: BSCS
* Course / Section: CS127L/AT2
* Purpose: 
*/

#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>

using namespace std;

#ifdef __WIN32
#include<conio.h> //using curses.h instead
#include<windows.h> //using unistd.h instead
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

//User defined global variables
const string OPTIONA = "[a] Check the palindrome\n";
const string OPTIONB = "[b] Read in a line of text\n";
bool authorized = false;


int main() //change back to void type
{
//add all your code here
    char choice;

    if (!authorized)
        password();

    while (true) { // Main program loop
        try {
            choice = menu();
            
            switch(choice) {
                case 'a':
                    while (true) { // 1: main loop for palindrome
                        char input[120];
                        
                        while (true) { // 2: loop for valid input of string
                            cout << OPTIONA
                                 << "Input the word: ";

                            //Check if string is alphanumeric
                            try {
                                cin.ignore();
                                cin.get(input, 120);

                                cout << "input: " << input << endl;

                                int i = 0;
                                while (input[i] != '\0') { 
                                    if (!isalnum(input[i])) {
                                        throw input[i];
                                    }

                                    i += 1;
                                }
                                
                                break; // out of loop 2
                            }
                            catch(char x) {
                                #ifdef _WIN32
                                system("CLS");
                                #endif
                                cerr << "Invalid character: " << x << "."
                                     << "Alphanumeric characters only.\n"
                                     << "Restoring input stream.\n";
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        }

                        palindrome(input); // Check if palindrome
                        #ifdef _WIN32
                        system("pause");
                        #endif

                        // Ask user to try again
                        #ifdef _WIN32
                        system("CLS");
                        #endif
                        char again;
                        while (true) { // 3: loop for valid input --> again
                            cout << "Do you want to try again [y/n]\n"
                                 << "Choice: ";                                

                            try {
                                cin >> again;

                                switch (tolower(again)) {
                                    case 'y':
                                        break; // out of switch
                                    case 'n':
                                        main();
                                    default:
                                        throw again;
                                }
                                break; // out of loop 3
                            }
                            catch(char) {
                                cerr << "Invalid input.\n";
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        } // End ask user to try again
                    }
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

    #ifdef _WIN32
    system("CLS");
    #endif

    cout << "Testing input...\n";

    cout << sal;

    int length = 0;
    for (length = 0; length < 120; length++) {
        if (sal[length] == '\0')
            break;
    }

    int i = 0, j = length-1;
    while (i != j) {
        if (sal[i] != sal[j]) {
            cout << sal << " is not a palindrome.\n";
            return;
        }

        i += 1;
        j -= 1;
    }

    cout << sal << " is a palindrome!\n";

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
    int attempts = 0;

    while (true) {

        pass = EnterPassword();

        printw("Processing password"); //change to conio.h

        for (int i = 0; i < 5; i++) {
            #ifdef _WIN32
            Sleep(700);
            #endif
            
            printw(".");
        }

        if (pass == "password") {
            #ifdef _WIN32
            system("CLS");
            #endif
            cout << "Accepted.\n"
                 << "Program initiating...\n";
            authorized = true;
            #ifdef _WIN32
            Sleep(1300);
            #endif
            
            break;
        }
        else {
            #ifdef _WIN32
            system("CLS");
            #endif
            printw("Incorrect. Try again.\n> "); //change to conio.h
            attempts += 1;
        }

        if (attempts >= 3) {
            cout << "Too many failed attempts. Exiting program...\n\n";
            #ifdef _WIN32
            Sleep(1000);
            exit(0);
            #endif
            break; //Remove this
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
         << "\t" << OPTIONA
         << "\t" << OPTIONB
         << "\t[c] Quit \n"
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
            else if (confirm == 'n' || confirm == 'N')
                main();
            else
                throw confirm;
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
            if(entry.length() > 0) {
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
