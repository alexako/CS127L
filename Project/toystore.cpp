/*
 * toystore.cpp
 * 
 * Copyright 2013 Alex <alex@kludge>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring> //for strcmp()

#ifdef _WIN32
#include<conio.h>
#include<windows.h>
#endif

#ifdef __linux
#include <curses.h>
#include <unistd.h>
#endif

using namespace std;


void mainMenu();
void adminMenu();
void viewInventory();
void adminLogin();
void addProduct();
void removeProduct();
void viewUsers();
void quit();
string enterpassword();
bool ADMIN_PRIVELEGE = false;


struct users {
    string username;
    string password;
};


struct inventory {
    char product[100];
    char quantity[5];
};


void clearScreen() {
    #ifdef _WIN32
    system("CLS");
    #endif
    #ifdef __linux
    system("clear");
    #endif
}


void pauseScreen() {

    cout << "\nPress <Enter> to continue...";

    #ifdef _WIN32
    system("pause");
    #endif
    #ifdef __linux
    cin.clear();
    cin.ignore(100, '\n');
    #endif
}


void stall() {
    #ifdef _WIN32
    Sleep(700);
    #endif
    #ifdef __linux
    sleep(0.5);
    #endif
}


void banner(string title) {

    clearScreen();
    cout << "=====================================\n"
         << "\t Toy Store Inventory \n"
         << "=====================================\n"
         << "\t --| " << title << " |--\n\n";
}


int main() {

    banner("Welcome");

    // Program Functionality
    cout << "Purpose: \n\n"
         << "   This program provides the user\n"
         << "   with access to the store's\n"
         << "   inventory. The user will be able\n"
         << "   to inquire, search, update, add,\n"
         << "   or remove items in the database.\n\n\n"
         << "A Project for CS127L.\n\n\n\n\n\n\n";

    pauseScreen();

    mainMenu();

    return 0;
}


void mainMenu() {

    char option;


    while (true) { // Main Menu loop
        banner("Main Menu");
        try {
            cout << "   1. View Toy Inventory\n"
                 << "   2. Admin Login\n"
                 << "   3. Quit\n\n"
                 << "Selection: ";

            cin >> option;

            switch(option) {
                case '1': viewInventory(); mainMenu();
                case '2': adminLogin(); break;
                case '3': quit(); break;
                default:
                    throw option;
            }

            break; //out of Menu loop
        }
        catch(char e) {
            clearScreen();
            cerr << "Invalid selection: " << e << "\n";
            cin.clear();
            pauseScreen();
        }
    } // End Main Menu loop
}


void adminMenu() {

    char option;


    while (true) { // Admin Menu loop
        banner("Admin Menu");
        try {
            cout << "   1. View Toy Inventory\n"
                 << "   2. Add New Toy Product\n"
                 << "   3. Remove Toy Product\n"
                 << "   4. View User Database\n";
            if (ADMIN_PRIVELEGE)
                cout << "   5. Logout\n"
                     << "   6. Return to Main Menu\n";
            else
                cout << "   5. Return to Main Menu\n";
            cout << "\n"
                 << "Selection: ";

            cin >> option;

            switch(option) {
                case '1': viewInventory(); break;
                case '2': addProduct(); break;
                case '3': removeProduct(); break;
                case '4': viewUsers(); break;
                case '5': ADMIN_PRIVELEGE = false;
                case '6': mainMenu();
                default:
                    throw option;
            }

            break; //out of Admin Menu loop
        }
        catch(char e) {
            clearScreen();
            cerr << "Invalid selection: " << e << "\n";
            cin.clear();
            pauseScreen();
        }
    } // End Admin Menu loop

    adminMenu();
}


void adminLogin() {

    banner("Admin Login");

    string password;
    string line; //of input file
    users USER;
    ifstream userList;
    userList.open("data/users.txt");
    int attempts = 0;

    //Check if user is already logged in
    if (ADMIN_PRIVELEGE) {
        cout << "An admin user already logged in.\n"
             << "Please logout to sign in with a different user.\n";

        pauseScreen();
        adminMenu();
    }

    // Kills programs if too many failed attempts to log in
    if (attempts > 2) {
        cerr << "Too many failed attempts to log in.\n"
             << "Exiting program...";
        cin.get();
        exit(0);
    }

    // Loads the users list file (data/users.txt)
    try {
        cout << "Loading...\n";
        stall();
        pauseScreen();
        if (!userList.good())
            throw 'x';
    }
    catch(char) {
        clearScreen();
        cerr << "Missing file.\n"
             << "Could not locate users.txt\n";
        pauseScreen();
        mainMenu();
    }

    attempts += 1;

    #ifdef __linux
    initscr();
    #endif

    while (true) {

        // Get username from user 
        #ifdef _WIN32
        char username[100];
        cout << "Enter Username: ";
        getline(cin, username);
        #endif
        #ifdef __linux
        char username[100];
        clear();
        refresh();
        printw("Enter Username: ");
        getstr(username);
        #endif
        // End get username from user
        // Get password from user
        #ifdef _WIN32
        cout << "Enter password: ";
        #endif
        #ifdef __linux
        refresh();
        printw("Enter password: ");
        #endif
        password = enterpassword();
        // End get password from user

        while (getline(userList, line)) { // Read each line from file

            // Search line for user id and password pair
            string::size_type start, end;
            USER.username = line.substr(start = line.find("id:")+4,
                                    end = line.find('>')-5);
            USER.password = line.substr(start = line.find("key:")+5,
                                    end = line.find('\r'));

            // Test user id and password pair with user input
            string user(username); // Construct string for comparison

            if (!user.compare(USER.username)
                && !password.compare(USER.password)) {
                clearScreen();
                cout << "Access Authorized.\n";
                #ifdef __linux
                endwin();
                #endif
                ADMIN_PRIVELEGE = true; // Keeps user logged in
                attempts = 0; // Reset attempts counter
                stall();
                adminMenu();
            }
        }

        cout << "Incorrect Username and/or password.\n"
             << "Returning to Main Menu...\n\n";
        #ifdef __linux
        getch();
        endwin();
        #endif
        #ifdef _WIN32
        pauseScreen();
        #endif
        mainMenu();
    }
}


string enterpassword() {

    #ifdef _WIN32
    const char RETURN = 13; // 13 for conio.h
    const char BACKSPACE = '\b';
    #endif
    #ifdef __linux
    const char RETURN = 10; // 10 for curses.h
    const char BACKSPACE = 127;
    #endif

    string entry;
    char key = 0;

    #ifdef __linux
    noecho();
    #endif

    while ((key = getch()) != RETURN) {
        
        if (key == BACKSPACE && entry.length() > 0) {
            #ifdef _WIN32
            cout << "\b \b";
            #endif
            #ifdef __linux
            printw("\b \b");
            #endif
            entry.resize(entry.size()-1);
        }
        else {
            entry += key;
            #ifdef _WIN32
            cout << "*";
            #endif
            #ifdef __linux
            printw("*");
            #endif
        }
    }

    #ifdef __linux
    echo();
    #endif

    return entry;
}


void quit() {

    clearScreen();

    char confirm;
    while (true) {
        cout << "Are you sure you want to quit? <y/N>: ";
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
        catch(char e) {
            clearScreen();
            cerr << "Invalid option " << e << ". Try again.\n";
        }
    }
}

//Admin Menu functions
void viewInventory() {

    cout << "In viewInventory()\n";
    pauseScreen();
}


void addProduct() {

    cout << "In addProduct()\n";
    pauseScreen();
}


void removeProduct() {

    cout << "In removeProduct()\n";
    pauseScreen();
}


void viewUsers() {

    cout << "In viewUsers()\n";
    pauseScreen();
}
