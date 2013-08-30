/*
* Programmer: REYES, Alexander
* Date Created: 8/29/2013
* Terminal No: 33
* Program: MIT
* Course / Section: CS127L/AT2
* Purpose: copy paste the problem below
*/

#include<iostream>
#include<iomanip>
using namespace std;


const int size=10;  //size for miles and gallons
typedef double *pointers; //type definition for pointers for mile and gallon
int max; //variable for maximum  numbers used in sorting
void MilesPerrGallon(double *ptr1,double *ptr2);//process and display the computed miles per gallon
void MperG(); //input for milesand gallons with try-throw-catch exception handling
void getSort(); //input and process the value in sorted order
void displaySort(int *ptr);//output and display the sorted value

int LIST_SIZE;

// Change back to void
int main()
{
   char ans;

   do{
//   system("cls");
   cout<<"----------O P T I O N S----------\n"
       <<"[1] Compute Miles per Gallon \n"
       <<"[2] Sorting of Numbers\n"
       <<"[3] EXIT\n"
       <<"Enter your choice: ";
   cin>>ans;
   try{
    //add code here
        if ((ans != '1' && ans != '2' && ans != '3') || !cin)
            throw ans;

        else break; // out of do-while loop
   }
   catch(char e)
   {
    //add code here
        cerr << "Invalid input.\n"
             << "Restoring input stream.\n\n";
        cin.clear();
        cin.ignore(100, '\n');
   }
   }while (true);

    switch(ans)
    {
    case '1':   //add code here
        MperG();
        break;
    case '2':   //add code here
        getSort();
        break;
    case '3':
        //add code here
        char resp;
        while (true) {//(resp != 'y' && resp != 'Y' && resp != 'n' && resp != 'N') {
            try {
                cout << "Are you sure you want to exit? <y/N>: ";
                cin >> resp;

                if (!isalnum(resp) || (resp != 'y' && resp != 'Y' && resp != 'n' && resp != 'N'))
                    throw resp;

                else break; // out of the loop
            }
            catch(char e) {
                cerr << "Invalid entry: " << e << "\n"
                     << "Restoring input stream.\n\n";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }

        if (resp == 'y' || resp == 'Y')
            return 0;
        else main();
    }//end switch

    return 0; // remove this
}

////////////////////////
void MperG()
{
//add code here

    double miles,
        gallons,
        *milPtr,
        *galPtr;

    milPtr = new double[size];
    galPtr = new double[size];

for(int i = 0; i < size; i++)
    {
        //add code here
        while(true){

        //add code here
        try{

            //add code here
            cout << "Enter miles (100-250) inclusive: ";
            cin >> miles;

            if (!cin)
                throw -1.0;
            else if (miles < 100 || miles > 250)
                throw miles;
            else {
                *(milPtr + i) = miles;
                break; // out of while loop
            }
        }//end try
        catch(double m)
        {
            //add code here
            cerr << "Invalid input";
            if (m != -1.0)
                cerr << ": " << m;
            cerr << "\nRestoring input stream. \n\n";
            cin.clear();
            cin.ignore(100, '\n');
        }//end catch

             //add code here
        }//end while
    }//loop for miles

/*********************************************************/ 
    //add code here
    for(int j = 0; j < size; j++)
    {
        //add code here
        while(true)
{
        //add code here
        try{
                //add code here
                cout << "Enter gallons (5-25) inclusive: ";
                cin >> gallons;

                if (!cin)
                    throw -1.0;
                else if (gallons < 5 || gallons > 25)
                    throw gallons;
                else {
                    *(galPtr + j) = gallons;
                    break; //out of while loop
                }
        }//end try
        catch(double g)
        {
            //add code here
            cerr << "Invalid input";
            if (g != -1.0)
                cerr << ": " << g;
            cerr << "\nRestoring input stream. \n\n";
            cin.clear();
            cin.ignore(100, '\n');
        }//end catch

             //add code here

        }//end while
    }//loop for gallons

    //add code here
    MilesPerrGallon(milPtr, galPtr);

}
////////////////////////
void MilesPerrGallon(double *ptr1,double *ptr2)
{

    //add code here
    double *mpgPtr;

    mpgPtr = new double[size];

    // Calculate miles per gallon
    for (int k = 0; k < size; k++)
        *(mpgPtr + k) = *(ptr1 + k) / *(ptr2 + k);

    //Display results ***Make into table
//    system("cls");
    cout << "Miles \t Gallons \tMPG \n"
         << "============================================"
         << "\n";
    for (int l = 0; l < size; l++)
        cout << *(ptr1 + l) << "\t  " << *(ptr2 + l)
             << "\t       = " << *(mpgPtr + l) << "\n";

    cout << "\n";

    cout << "Press any key to continue...";
//    system("pause");
    main();
}
///////////////////////////////////////
void getSort()
{
    //add code here
    int input;
    int *Sptr;

    // Get size of array
    while (true) {
        try {
            cout << "Enter size of array: ";
            cin >> LIST_SIZE;

            if (LIST_SIZE < 1 || !cin)
                throw LIST_SIZE;

            else break; // out of while loop
        }
        catch(int e) {
            cerr << "Invalid input.\n"
                << "Restoring input stream.\n\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
    }// End get size

    Sptr = new int[LIST_SIZE];

    // Get elements of array
    cout << "Enter numbers for \n";
    for (int i = 0; i < LIST_SIZE; i++) {
        while (true) {
            try {
                cout << "index[" << i << "]: ";
                cin >> input;

                if (!cin)
                    throw -1;

                else {
                    *(Sptr + i) = input;
                    break; // out of while loop
                }
            }
            catch(int) {
                cerr << "Invalid input. \n"
                     << "Restoring input stream. \n\n";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
    }// End get elements


    // Insertion Sort
    int on_deck, comparing;

    for (int i = 1; i < LIST_SIZE; i++) {
        on_deck = *(Sptr + i);
        comparing = i - 1;

        while ((comparing >= 0) && (on_deck < *(Sptr + comparing))) {
            *(Sptr + (comparing+1)) = *(Sptr + comparing);
            *(Sptr + comparing) = on_deck;
            comparing -= 1;

        }
    } // End Insertion Sort

    displaySort(Sptr);

    cin.ignore(100, '\n');
    cout << "Press any key to continue...";
//    system("pause");
    main();
}
/////////////////////////
void displaySort(int *ptr)
{
//add code here
    cout << "Sorted array: ";
    for (int i = 0; i < LIST_SIZE; i++)
        cout << *(ptr + i) << " ";

    cout << "\n";

    delete[] ptr;
}
