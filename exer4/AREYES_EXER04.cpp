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

#ifdef _WIN32
/** Restore these headers when testing in lab **/
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
const string PASSKEY = "12345";
const string OPTIONA = "[a] Check the palindrome\n";
const string OPTIONB = "[b] Read in a line of text\n";
const string OPTIONC = "[c] Quit\n";
bool authorized = false;

// Remove this
void clearScreen() {
    #ifdef _WIN32
    system("CLS");
    #endif
    #ifdef __linux
    system("clear");
    #endif
}

void stall() { // Need to fix this!!! **Enter pass not working
    #ifdef _WIN32
    Sleep(700);
    #endif
    #ifdef __linux
    sleep(0.5);
    #endif
}//


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
                    while (true) { // 1a: palindrome loop
                        char input[120];
                        
                        while (true) { // 2a: loop for valid input of string

                            clearScreen(); //Remove and change to system("cls");

                            cout << OPTIONA
                                 << "Input the word: ";

                            //Check if string is alphanumeric
                            try {
                                cin.get(input, 120);

                                cout << "input: " << input << endl;

                                int i = 0;
                                while (input[i] != '\0') { 
                                    if (!isalnum(input[i]))
                                        throw input[i];

                                    i += 1;
                                }
                                
                                break; // out of loop 2a
                            }
                            catch(char x) {
                                
                                clearScreen(); //Remove and change to system("cls");
                                
                                cerr << "Invalid character: " << x << "."
                                     << "Alphanumeric characters only.\n"
                                     << "Restoring input stream.\n";
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        } // End 2a: valid input loop

                        palindrome(input); // Check if palindrome

                        #ifdef _WIN32
                        system("pause");
                        #endif
                        cin.ignore(100, '\n');

                        clearScreen(); //Remove and change to system("cls");

                        // Ask user to try again
                        char again;
                        while (true) { // 3a: loop for valid input --> again
                            cout << "Do you want to try again [y/n]\n"
                                 << "Choice: ";                                

                            try {
                                cin >> again;
                                cin.ignore(100, '\n');

                                switch (tolower(again)) {
                                    case 'y': break; // out of switch
                                    case 'n': main();
                                    default:
                                        throw again;
                                }
                                break; // out of loop 3a
                            }
                            catch(char) {
                                cerr << "Invalid input.\n";
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        } // End 3a: ask user to try again
                    } // End 1a: main palindrome loop
                    break;
                case 'b':
                    while (true) { // 1b: counting loop

                        counting();

                        clearScreen(); //Remove and change to system("cls");

                        // Ask user to try again
                        char again;
                        while (true) { // 2b: loop for valid input --> again
                            cout << "Do you want to try again [y/n]\n"
                                 << "Choice: ";                                

                            try {
                                cin >> again;
                                cin.ignore(100, '\n');

                                switch (tolower(again)) {
                                    case 'y': break; // out of switch
                                    case 'n': main();
                                    default:
                                        throw again;
                                }
                                break; // out of loop 2b
                            }
                            catch(char) {
                                cerr << "Invalid input.\n";
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        } // End 2b: ask user to try again
                    } // End 1b: counting loop
                    break;
                case 'c':
                    quit();
                default:
                    throw choice;
            }
        }
        catch(char) {
            cerr << "Invalid option.";
            stall(); // Remove and change to Sleep(1000);
        }
    } // End of main loop

    return 0; //Remove
}
void counting()
{
//add all your code here
    string sentence;
    string letters = "abcdefghijklmnopqrstuvwxyz";
    int *lCount = new int[letters.length()](); // lCount[l] = number of occurrences
    int words = 1;

    clearScreen(); //Remove and change to system("cls");

    while (true) { // validate input
        try {
            cout << OPTIONB
                 << "Enter a valid a sentence (with spaces):\n> ";

            getline(cin, sentence);
            if (sentence.length() < 1)
                throw sentence;
            break; // out of while loop
        }
        catch(string) {
            cerr << "You've gotta enter something!\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
    } // End validate input

    for (string::size_type i = 0; i < sentence.length(); i++) {
        // Count words
        if (isspace(sentence[i])) {
            words += 1;
        }

        // Count letter 
        for (string::size_type j = 0; j < letters.length(); j++) {
            if (tolower(sentence[i]) == letters[j]) {
                lCount[j] += 1;
            }
        }
    }

    cout << "\nwords: " << words << endl;

    //Print letter count
    for (string::size_type index = 0; index < letters.length(); index++) {
        if (lCount[index])
            cout << letters[index] << ": " << lCount[index] << "\n";
    }
    cout << "\n";

    //Print inverted sentence
    for (string::size_type l = 0; l < sentence.length(); l++) {
        if (isalpha(sentence[l])) {
            if (islower(sentence[l]))
                cout << static_cast<char> (toupper(sentence[l]));
            else
                cout << static_cast<char> (tolower(sentence[l]));
        }
        else
            cout << sentence[l];
    }
    cout << "\n";

    cout << "Press <enter> to continue...\n";
    cin.ignore(100, '\n');
}
void palindrome(char sal[120])
{
//add all your code here

    clearScreen(); //Remove and change to system("cls");

    // Loading
    cout << "Calculating " << sal;
    for (int i = 0; i < 5; i++) {
        stall(); // Remove and change to Sleep(1000);
        cout << ".";
    }
    cout << "\n";
    // End loading

    // Get length of given char string
    int length; // of string 
    for (length = 0; length < 120; length++) {
        if (sal[length] == '\0')
            break;
    }

    // Iterate and compare elements from start and end of string
    int i = 0, j = length-1;
    bool ispal = true;
    while (i <= j) {
        if (sal[i] != sal[j]) {
            ispal = false;
            break;
        }

        i += 1;
        j -= 1;
    }

    if (!ispal)
        cout << sal << " is not a palindrome.\n";
    else
        cout << sal << " is a palindrome!\n";

    cout << "\nPress <enter> to continue...\n";
    cin.ignore(100, '\n');
}
void password()
{
//add all your code here

    clearScreen(); //Remove and change to system("cls");

    initscr(); //Remove curses.h

    printw("Enter password\n> "); //change to conio.h

    string pass;
    int attempts = 0;

    while (true) {

        pass = EnterPassword();

        printw("Processing password"); //change to conio.h

        for (int i = 0; i < 5; i++) {
            stall(); // Remove and change to Sleep(1000);
            printw("."); // change to conio.h
        }

        if (pass == PASSKEY) {
            clearScreen(); //Remove and change to system("cls");
            cout << "Accepted.\n"
                 << "Program initiating...\n";
            authorized = true;
            stall(); // Remove and change to Sleep(1000);
            
            break;
        }
        else {
            clearScreen(); //Remove and change to system("cls");
            printw("Incorrect. Try again.\n> "); //change to conio.h
            attempts += 1;
        }

        if (attempts >= 3) {
            cout << "Too many failed attempts. Exiting program...\n\n";
            stall(); // Remove and change to Sleep(1000);
            
            exit(0);

            break; //Remove this
        }


    }

    endwin(); //Remove curses.h
}
char menu()
{
//add all your code here

    char option;

    clearScreen(); //Remove and change to system("cls");

    cout << "========== Menu ==========\n"
         << "  Operations: \n"
         << "\t" << OPTIONA
         << "\t" << OPTIONB
         << "\t[c] Quit \n"
         << "> ";
    cin >> option;
    cin.ignore(100, '\n');

    return option;
}

void quit()
{
//add all your code here
    clearScreen(); //Remove and change to system("cls");

    cout << "Are you sure you want to quit? <y/N>: ";
    char confirm;
    while (true) {
        try {
            cin >> confirm;
            cin.ignore(100, '\n');

            switch (tolower(confirm)) {
                case 'y': exit(0);
                case 'n': main();
                default:
                    throw confirm;
            }
        }
        catch(char) {
            clearScreen(); //Remove and change to system("cls");
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

    noecho(); //Disable echoing; maybe remove
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

    echo(); //Restore echo; maybe remove

    return entry;
}
