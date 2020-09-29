#include <iostream>
#include <ctime>
#include "array.h"

using namespace std;

int main() {
	/*-------------------
	8th point of the task
	------------------*/
	cout << "8th point of the task:\n\n";

	//Random init
	srand(time(0));

	Array a(10);
	a.random_init(30);

	Array b(15);
	b.random_init(30);

	Array c(20);
	c.random_init(30);

	//Overloading stream output operator
	cout << "Array a: " << a << "\nArray b: " << b << "\nArray c: " << c << "\n\n";
	
	//Overloading < operator
	cout << ((a < b) ? "a less than b" : "b less than a") << endl;
	
	//Overloading > operator
	cout << ((c > b) ? "c more than b" : "b more than c") << endl;
	
	//Overloading + operator
	cout << "Array a + c: " << a + c << endl;

	/*-------------------
	9th point of the task
	------------------*/
	cout << "\n\n9th point of the task:\n\n";

	Array *ptr1 = new Array(7);
	ptr1->handle_init();

	Array *ptr2 = new Array (*ptr1);

	ptr1->shellSort();
	ptr2->random_init(50);

	cout << "\nArray ptr1 (sorted): " << *ptr1 << "\nArray ptr2 (random): " << *ptr2 << "\n\n";

	delete ptr1, ptr2;

	/*-------------------
	10th point of the task
	------------------*/
	cout << "\n\n10th point of the task:\n\n";

	int num_of_rows;
	bool failInput;
	cout << "Enter the number of rows: " << endl;
	do
	{
		failInput = false;
		cin >> num_of_rows;
		if (cin.fail()) {
			failInput = true;
			cout << "Incorrect entry, try again: ";

			//Input buffer clear 
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
	} while (failInput);
	
	Array *arr = new Array[num_of_rows];
	for (int i = 0; i < num_of_rows; i++) {
		cout << "Enter array #" << i+1 << ":\n";

		arr[i].handle_init();
		cout << endl;
	}
		
	cout << endl;

	for (int i = 0; i < num_of_rows; i++) {
		arr[i].print();
		cout << endl;
	}
}
