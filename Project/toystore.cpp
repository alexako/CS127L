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
#include <cstring> // for strcmp()
#include <iomanip> // for setw()
#include <stdlib.h> // for atoi(), atof()

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
void addProduct(); // Add product to inventory list
void viewUsers(); // View registered user list
void quit();
string enterpassword();

int attempts = 0;
bool ADMIN_PRIVELEGE = false; //debug mode deactivated
/* Input files */
const char* USER_FILE = "data/users.dat"; // User list
const char* INVENTORY_FILE = "data/inventory.dat"; // Inventory list


struct users {
    string username;
    string password;
};


struct inventory {
    string product;
    int prodNum;
    double price;
    int quantity;
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

    #ifdef _WIN32
    system("pause");
    #endif
    #ifdef __linux
    cout << "\nPress <Enter> to continue...";
    cin.get();
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

    // Program Functionality overview
    cout << "Purpose: \n\n"
         << "   This program provides the user\n"
         << "   with access to the toy store's\n"
         << "   inventory. The user will be able\n"
         << "   to view and add items to a file.\n"
         << "   A list of all registered users\n"
         << "   will also be accessible.\n\n\n\n"
         << "A Project for CS127L.\n\n\n\n\n\n";

    pauseScreen();

    mainMenu();

    return 0;
}


void mainMenu() {

    char option;


    while (true) { // Main Menu loop
        banner("Main Menu");
        try {
            cout << "   1. View Toy Inventory\n";
            if (ADMIN_PRIVELEGE) cout << "   2. Logout\n";
            else cout << "   2. Admin Login\n";
            cout << "   3. Quit\n";
            if (ADMIN_PRIVELEGE)
                cout << "   4. Return to Admin menu\n";
            cout << "\nSelection: ";

            cin >> option;

            switch(option) {
                case '1': viewInventory(); mainMenu();
                case '2':
                    if (ADMIN_PRIVELEGE) ADMIN_PRIVELEGE = false;
                    else adminLogin();
                    mainMenu();
                    break;
                case '3': if (ADMIN_PRIVELEGE) ADMIN_PRIVELEGE = false;
                case '4':
                    if (ADMIN_PRIVELEGE) adminMenu();
                    quit(); break;
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
                 << "   3. View User Database\n";
            if (ADMIN_PRIVELEGE)
                cout << "   4. Logout\n"
                     << "   5. Return to Main Menu\n";
            else
                cout << "   4. Return to Main Menu\n";
            cout << "\n"
                 << "Selection: ";

            cin >> option;

            switch(option) {
                case '1': viewInventory(); break;
                case '2': addProduct(); break;
                case '3': viewUsers(); break;
                case '4':
                    if (ADMIN_PRIVELEGE) {
                        ADMIN_PRIVELEGE = false;
                        clearScreen();
                        cout << "\n\n\n\n\n\n\n\nSuccessfully logged out.\n\n\n";
                        stall();
                    }
                case '5': mainMenu();
                default:
                    throw option;
            } // End switch

        }
        catch(char e) {
            clearScreen();
            cerr << "Invalid selection: " << e << "\n";
            cin.clear();
            pauseScreen();
        }
    } // End Admin Menu loop
}


void adminLogin() {

    banner("Admin Login");

    string password;
    string line; //of input file
    users USER;
    ifstream userList;
    userList.open(USER_FILE);

    //Check if user is already logged in
    if (ADMIN_PRIVELEGE) {
        cout << setw(3)
             << "An admin user already logged in.\n"
             << "Please logout to sign in with a different user.\n\n";

        pauseScreen();
        adminMenu();
    }

    // Kills program if too many failed attempts to log in
    if (attempts > 2) {
        cerr << "Too many failed attempts to log in.\n"
             << "Exiting program...";
        pauseScreen();
        exit(0);
    }

    // Checks if the users list file (data/users.dat) loaded properly
    try {
        cout << "Loading...\n\n\n\n";
        stall();
        pauseScreen();
        clearScreen();
        if (userList.fail())
            throw 'x';
    }
    catch(char) {
        clearScreen();
        cerr << "\n\n\nMissing file.\n"
             << "Could not locate users.dat\n\n\n";
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
        cin >> username;
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
                cout << setw(5)
                     << "\n\n\n\n\n\n\n\nAccess Authorized.\n";
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
        userList.close();
        adminLogin();
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

    int count = 0; //number of toys in inventory
    string readBuffer;
    inventory items;
    ifstream inventFile;
    inventFile.open(INVENTORY_FILE);

    // Checks if the users list file (data/inventory.dat) loaded properly
    try {
        cout << "Loading...\n\n\n\n";
        stall();
        pauseScreen();
        clearScreen();
        if (inventFile.fail())
            throw 'x';
    }
    catch(char) {
        clearScreen();
        cerr << "\n\n\nMissing file.\n"
             << "Could not locate inventory.dat\n\n\n";
        pauseScreen();
        mainMenu();
    }


    banner("Inventory List");

    cout << setw(1) << "Prod No."
         << setw(7) << "Name"
         << setw(16) << "Price / "
         << setw(25) << "Quant.\n"
         "-------------------------------------\n";

    // Parse inventory list
    string::size_type start, end;
    while (getline(inventFile, readBuffer)) { // Read each line

        string::size_type start, end;
        items.prodNum = atoi(readBuffer.substr(start = readBuffer.find("#")+1,
                                    end = readBuffer.find('|')-1).c_str());
        items.product = readBuffer.substr(start = readBuffer.find("|")+1,
                                    end = readBuffer.find(" > ")-1);
        items.price = atof(readBuffer.substr(start = readBuffer.find(">")+1,
                                    end = readBuffer.find('=')-1).c_str());
        items.quantity = atoi(readBuffer.substr(start = readBuffer.find("=")+1,
                                    end = readBuffer.find('\n')-1).c_str());

        if (items.prodNum) {
            cout << setw(1) << items.prodNum; // Print product number
            string prod = items.product.substr(0, items.product.find(" >"));
            if (prod.length() > 7) cout << setw(10) << prod.substr(0, 8); // Reduce string to 7
            else cout << setw(10) << items.product.substr(0, items.product.find(" >")); // Print product name
            cout << setw(13) << showpoint << fixed << setprecision(2)
                 << items.price; // Print product price
            cout << " / "
                 << setw(2) << items.quantity // Print quantity of product
                 << "\n";

            count += 1;
        }
        else cout << "\t     -- EMPTY --- \n";

    } // End parse inventory list
    cout << "-------------------------------------\n\n\n";

    cout << "Total number of toys: " << count
         << "\n\n";

    pauseScreen();
    inventFile.close();
}


void addProduct() {

    ofstream inventFile;
    inventFile.open(INVENTORY_FILE, ofstream::out | ofstream::app); // append to file
    inventory item;

    banner("Add Product");

    // Get product name
    cin.ignore();
    cout << "Enter product name: ";
    getline(cin, item.product);

    // Get product number
    while (true) {
        cout << "Enter product number: ";
        try {
            cin.clear();
            cin >> item.prodNum;

            if (item.prodNum < 10000 || item.prodNum > 99999 || !cin)
                throw item.prodNum;

            break; // out of while loop
        }
        catch(int x) {
            clearScreen();
            cerr << "Invalid product number: " << x << ". Must be 5 digits.\n";
            pauseScreen();
        }
    }

    // Get product price
    cout << "Enter product price: $";
    cin >> item.price;

    // Get product quantity
    cout << "Enter number currently in stock: ";
    cin >> item.quantity;

    banner("Add Product");

    cout << "Product No. " << item.prodNum << '\n'
         << "Name: " << item.product << '\n';
    cout << "Price: $" << showpoint << fixed << setprecision(2)
         << item.price << '\n'
         << "Quantity: " << item.quantity << "\n\n\n";

    // Write input to file and encode
    cout << "Saving " << item.product << " to inventory list...\n\n";

    inventFile << "\n#" << item.prodNum << " | "
               << item.product << " > "
               << item.price << " = "
               << item.quantity << "\r";

    stall();
    cout << "Saved successfully.\n\n\n";
    pauseScreen();
    inventFile.close();
    // End write input to file

    clearScreen();

    //Ask user if another item will be added
    char confirm;
    while (true) {
        cout << "Would you like to add another product? <y/N>: ";
        try {
            cin >> confirm;
            cin.ignore(100, '\n');

            switch (tolower(confirm)) {
                case 'y': addProduct();
                case 'n': mainMenu();
                default:
                    throw confirm;
            }
        }
        catch(char a) {
            clearScreen();
            cerr << "Invalid option " << a << ". Try again.\n";
        }
    }// End another item loop
}


void viewUsers() {

    string readBuffer;
    users user;
    ifstream userFile;
    userFile.open(USER_FILE);

    banner("User List");

    cout << "Registered Users\n"
         << "-----------------\n";

    //Parse users
    int count = 0;
    while (getline(userFile, readBuffer)) { // Read each line

            count += 1;
            string::size_type start, end;
            user.username = readBuffer.substr(start = readBuffer.find("id: ")+4,
                                    end = readBuffer.find('>')-5);

            cout << count << ".  " << user.username << "\n";
    } // End parse users
    cout << "-----------------\n\n\n";

    cout << "Total number of users: " << count << "\n\n\n";

    pauseScreen();
    userFile.close();
}

void searchProduct() {

    string readBuffer;
    string *products = new string[100];
    inventory stock;
    ifstream stockFile;
    stockFile.open("test.txt");

    banner("Search");

    cout << "Enter the product number <ex. 32512>: #";

    //Parse file
    for (int index = 0; getline(stockFile, readBuffer); index++)
        product[index] = readBuffer;

    
}
