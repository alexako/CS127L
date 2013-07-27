#include <iostream>

using namespace std;

void swap(int& x, int& y);
// Swaps values by reference with only two variables


int main() {

    int num1, num2;

    cout << "Enter numbers to swap: ";

    cin >> num1 >> num2;

    cout << "Num1: " << num1 << endl
        << "Num2: " << num2 << endl
        << endl
        << "Swapping values..." << endl
        << endl;

    swap(num1, num2);

    cout<< "Numbers are swapped" << endl
        << endl
        << "Num1: " << num1 << endl
        << "Num2: " << num2 << endl
        << endl;

    return 0;
}

void swap(int& x, int& y) {

    x = x + y;
    y = x - y;
    x = x - y;
}
