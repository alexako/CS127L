
######Exercise 2 (100 points)

ONE /TWO DIMENSIONAL ARRAY (with array to a function-pass by reference)

CRAMER’S RULE is an explicit formula for the solution of a system of linear equations with as many equations as unknowns, valid whenever the system has a unique solution. It expresses the solution in terms of the determinants of the (square) coefficient matrix and of matrices obtained from it by replacing one column by the vector of right hand sides of the equations.
**Please see cramer’s rule file for the process of determinants

FREQUENCY The rate at which something occurs or is repeated over a particular period of time or in a given sample.
A program that would input a series of numbers between 11 and 20 terminated by a 0 sentinel and then display the frequency or number of occurrence of each number. It should also validate the entry (must be between 11 and 20 only) and if invalid, it should display the message “OUT OF RANGE”.
Write the definitions of the declared function prototypes of the given code. This program should be able to simulate cramer’s rule and frequency from 11-20. No modification should be done in the given codes (main function and function prototypes).

/*  Laboratory Exercise No2. - one and two dimensional array
    one dimensional- frequency of
    two dimensional- cramer's rule
*/

\#include \<iostream\> <br>
\#include \<cctype\> <br>
\#include \<iomanip\> <br>

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

void main()

{
    //add code here
    choiceMenu(ans);
    tryAgain();
    cout<<endl;
}//end main

///////////////////////////////////

void Menu()
{
    //add code here
}

/////////////////////////////////

void choiceMenu(int ch)

{
    switch(ch)

    {
        case 1:
                //add code here –cramer’s rule

            break;
        case 2:
                //add code here – frequency 11-20
            break;
        case 3:
                //add code here for exit
    }//end switch
}//end choiceMenu

///////////////////////////////////

char fexit()
{
    //add code here
}//end fexit

//////////////////////////////////

void equation1(int list[][col], int rsize)

{
    //add code here
}//end equation1

///////////////////////////////////////////

int deter1(int list[][col],int size)

{
    //add code here
}

/////////////////////////////////////////

int deter2(int list[][col],int size)

{
    //add code here
}

///////////////////////////////////////////

int deter3(int list[][col],int size)

{
    //add code here
}

////////////////////////////////////////////

void cramer(int D, int Dx, int Dy)

{
    //add code here
}

//////////////////////////

void tryAgain()

{
    //add code here
}

//////////////////////////////

void FREQUENCY(int list[],int lsize)

{
    //add code here
}

Note: you are only required to write the function definition. Thus, you are not allowed to make any modifications in the main function and on the function prototypes unless there is “//add code here for……”. Any modifications will result a deduction from your lab exercise.
Please be guided accordingly.
