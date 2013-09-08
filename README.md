CS127L
======

Useful snippets of code available in **[snippets](https://github.com/alexako/CS127L/tree/master/snippets)** directory

Solutions and logs of the Programming Exercises for CS127 lab

**[Exercise 1 - ATM Simulator](https://github.com/alexako/CS127L/blob/master/exer1/atm.cpp)**
 - Straight forward implementation of concepts taught in class
 - Found out '%' can only be used for ints
 - Need to use fmod() from math.h for doubles

**[Exercise 2 - Cramer's Rule and Frequency](https://github.com/alexako/CS127L/blob/master/exer2/Ex2.cpp)**
 - The order of parameters processed is last to first foo(last, next, first). So, I assigned variables to store the return values to process the deter functions in correct order.
 - Not sure if x and y values should be accurately rounded to next whole number, some decimal point, or truncated as an int.

**[Exercise 3 - Miles Per Gallon and Sort Array using Pointers](https://github.com/alexako/CS127L/blob/master/exer3/AREYES-EXER03.cpp)**
 - Miles Per Gallon was another straight forward implementation of class lectures
 - Used Insertion sort but problem stated values should be processed in sorted order
 
**[Exercise 4 - Strings](https://github.com/alexako/CS127L/blob/master/exer4/AREYES_EXER04.cpp)**
 - Palindrome was easy. Iterated through string from the start and end while testing if equivalent.
 - Used pointer array to count letters of string
 - Typecast string char to char in order to use tolower()/toupper()
 - Problem with sleep() function. Not working at all.
 - password() and EnterPassword() are using curses.h. Need to use windows.h for lab.
 - iostream does not work with curses.h. Used printw() instead. Need to change back after testing.
