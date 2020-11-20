#include <iostream>
#include <string>
#include "System_architect.h"
#include "Network_admin.h"

using namespace std;

int Int(string);

int main()
{
	int size = Int("Enter size of array, please: ");
	Administrator** Employees = new Administrator*[size];
	
	for (int i = 0; i < size; i++)
	{
		switch (i%3)
		{
		case 0:
			Employees[i] = new Computer_admin();
			break;
		case 1:
			Employees[i] = new System_architect();
			break;
		case 2:
			Employees[i] = new Network_admin();
			break;
		}
		Employees[i]->Show();
		Employees[i]->Count();
		cout << endl;
		cout << endl;
	}

	//freeing memory
	for (int i = 0; i < size; i++)
		delete Employees[i];
	delete Employees;
}
int Int(string messege) {

	cout << messege;
	//Input buffer clear 
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	bool failInput;
	string value;
	do
	{
		failInput = false;
		getline(cin, value);
		if (value.find_first_not_of("0123456789") != std::string::npos || value.empty()) {
			failInput = true;
			cout << "Incorrect entry, try again: ";
		}
	} while (failInput);
	cout << endl;
	return stoi(value);
}
