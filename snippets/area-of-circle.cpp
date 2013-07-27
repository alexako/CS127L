#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double find_side(double area);
//Doesn't compute perfect squares accurately

double Carea(double side);
//Finds the area of a circle based on argument

int main() {

    double Sarea, side;
    char answer;

    do {
        cout << "Enter area of square: ";
        cin >> Sarea;

        side = find_side(Sarea);

        cout << "The largest area of a circle: " << Carea(side) << endl;

        cout << "Again? ";
        cin >> answer;

    } while (answer == 'y' || answer == 'Y');

    return 0;
}

double find_side(double area) {

    double side;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    for (double i = 1.0; i < area; i++) {
        if (pow(i, 2) == area)
            side = i;
    }

    if (side > 0) {
        cout << "Found side: " << side << endl;
        return side;
    }

    else {
        cerr << "Side length not found!\n";
        return -1;
    }
}

double Carea(double side) {

    const double PI = 3.14;
    double radius;

    radius = side / 2;

    return (PI * (radius * radius));
}
