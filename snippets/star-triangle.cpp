#include <iostream>

using namespace std;

int main() {

	int size;

	cout << "Enter a size: ";
	cin >> size;
	cout << endl << endl;

	// Prints star-triangle starting from narrow side
	for (int i=0; i <= size; i++) {
		for (int j=0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	// Prints star-triangle starting from wide side
	for (int i=size+1; i >= 0; i--) {
		for (int j=0; j<= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
