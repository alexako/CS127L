/*
* Programmer: Reyes, Alexander
* Date Created: 8/1/2013
* Terminal No: 33
* Program: CS
* Course / Section: CS127L/AT2
* Purpose: Solves equations using Cramer's Rule/ Outputs Frequency
*/


/*Laboratory Exercise No2. - one and two dimensional
array
one dimensional- frequency of
two dimensional- cramer's rule
*/

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

using namespace std;

////cramers rule////////////
const int row=2;
const int col=3;
int deter1(int list[][col],int size);//process determinant D
int deter2(int list[][col],int size);//process determinant Dx
int deter3(int list[][col],int size);//process determinant Dy
void equation1(int list[][col],int rsize);//process value in 2-dimensional array and the cramers
      //equation
void choiceMenu(int ch);//process choice 1 or 2 using switch case statement
void cramer(int,int,int);//process and display cramer's solution

///////menu,exit and try again//////////
void Menu();//show main menu
char fexit();//quit
void tryAgain();//ask the user to try again

//////frequency/////////////////////
const int size=10;//constant decalaration for the size of array in getting the frequency 11-20
void FREQUENCY(int list[],int lsize);//displays the frequency of 11 to 20 and count the
//occurence


// Remove
void clearScreen() {
    for (int i = 0; i < 50; i++)
        cout << endl;
}

// Change back to int
int main()
{

    //add code here
    int ans;

    Menu();

    cin >> ans;

    choiceMenu(ans);

    tryAgain();
    cout<<endl;

    return 0; // Remove this
}//end main


///////////////////////////////////
void Menu()
{
    //add code here

    // Remove
    clearScreen();
    cout << "Choose an operation" << endl
         << "\t 1. Cramer's Rule" << endl
         << "\t 2. Frequency" << endl
         << "\t 3. Quit " << endl
         << endl
         << "Selection: ";

}
/////////////////////////////////
void choiceMenu(int ch)
{

    switch(ch) {
    case 1:
            //add code here -cramer's rule
            int nums1[row][col];
            equation1(nums1, row);
            cramer(
               deter1(nums1, row),
               deter2(nums1, row),
               deter3(nums1, row)
               );

        break;
    case 2:
            //add code here - frequency 11-20
            int nums2[size];
            FREQUENCY(nums2, size);
        break;
    case 3:
            //add code here for exit
            fexit();

    }//end switch

}//end choiceMenu
///////////////////////////////////

char fexit()
{
    //add code here
    clearScreen();
    cout << "Exiting program..." << endl;
    exit(0);
}//end fexit
//////////////////////////////////
void equation1(int list[][col], int rsize)
{
    //add code here
    int a1, a2, b1, b2, c1, c2;

    //Remove
    clearScreen();

    cout << "Enter equation 1"
         << "Ex. \n\t x + 3y = 12 should be entered as 1 3 12";
    cin >> a1 >> b1 >> c1;

    cout << "Enter equation 2"
         << "Ex. \n\t x + 3y = 12 should be entered as 1 3 12";
    cin >> a2 >> b2 >> c2;

    list[0][0] = a1;
    list[0][1] = b1;
    list[0][2] = c1;
    list[1][0] = a2;
    list[1][1] = b2;
    list[1][2] = c2;

    // Output Equation entered

}//end equation1
///////////////////////////////////////////
int deter1(int list[][col],int size)
{
    //add code here
    return ((list[0][0] * list[1][1]) - (list[0][1] * list[1][0]));
}
/////////////////////////////////////////
int deter2(int list[][col],int size)
{
    //add code here
    return ((list[0][2] * list[1][1]) - (list[1][2] * list[0][1]));
}
///////////////////////////////////////////
int deter3(int list[][col],int size)
{
    //add code here
    return ((list[0][0] * list[1][2]) - (list[0][2] * list[1][0]));
}
////////////////////////////////////////////
void cramer(int D, int Dx, int Dy)
{
    //add code here
    int x, y;

	//Remove
    clearScreen();

    if (D == 0) {
        cerr << "The system is either inconsistent or dependent. "
                "Another method must be used to solve it."
             << endl;
        tryAgain();
    }

    x = Dx / D,
    y = Dy / D;

    // Output D, Dx, Dy

    cout << "Solution: (" << x << ", " << y << ")" << endl
         << "x = " << x << endl
         << "y = " << y << endl;
}
//////////////////////////
void tryAgain()
{
    //add code here
    char response;

    clearScreen();

    do {
        cout << "Would you like to do another operation? <Y/n>: ";
        cin >> response;

        if (response == 'Y' || response == 'y' || response == 'N' || response == 'n')
            break;
        cerr << "Invalid response.";
    } while (true);

    if (response == 'Y' || response == 'y')
        main();
    else if (response == 'N' || response == 'n')
        fexit();
}
//////////////////////////////
void FREQUENCY(int list[],int lsize)
{

    //add code here

    int num = 1, counter[10];

    // Remove
    clearScreen();

    // Initialize counter to zeros
    for (int i = 0; i < lsize; i++) {
        counter[i] = 0;
    }

    // Initialize list incrementally
    for (int j = 0; j < lsize; j++) {
        list[j] = j + 11;
    }

    cout << "Frequency" << endl
         << "Enter number between 11 and 20 (inclusive)" << endl
         << endl;

    while (num != 0) {
        cout << " > ";
        cin >> num;

        if (num <= 20 && num >= 11)
            for (int k = 0; k < lsize; k++) {
                if (list[k] == num)
                    counter[k] = counter[k] + 1;
            }
        else
            cerr << "Must be between 11 and 20 (inclusive)" << endl;
    }

    // Remove
    clearScreen();

    // Print out counts
    cout << "Total counts: " << endl;
    for (int l = 0; l < lsize; l++) {
        cout << list[l] << ": " << counter[l] << " times." << endl;
    }

    cout << endl;

    char cont;
    cout << "Press any key to continue...";
    cin.get(); // Should work in windows

    // Remove
    cin >> cont;
}
