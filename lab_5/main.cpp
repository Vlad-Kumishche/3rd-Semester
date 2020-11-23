#include <iostream>
#include <string>
#include "System_architect.h"
#include "Network_admin.h"

using namespace std;

int Int(string);
string GetLine(string);

int main()
{
	int size = Int("Enter size of array, please: ");
	Administrator** Employees = new Administrator*[size];

	string FullName, CompanyName, AccessPass, OSName, OSVersion, ToolPack,
		TypeOfNetwork, Specialization, degreeOfSteepness;

	int Salary, NumberOfRegalia;
	
	for (int i = 0; i < size; i++)
	{
		std::cout << "Employee #" << i + 1 << ":" << endl;
		switch (i%3)
		{
		case 0:
			FullName = GetLine("Full Name: ");
			CompanyName = GetLine("Company Name: ");
			AccessPass = GetLine("Access Password: ");
			Salary = Int("Salary: ");
			OSName = GetLine("OS Name: ");
			OSVersion = GetLine("OS Version: ");
			ToolPack = GetLine("Tool Pack: ");
			Employees[i] = new Computer_admin(FullName, CompanyName, AccessPass, Salary, OSName, OSVersion, ToolPack);
			break;
		case 1:
			FullName = GetLine("Full Name: ");
			CompanyName = GetLine("Company Name: ");
			AccessPass = GetLine("Access Password: ");
			Salary = Int("Salary: ");
			OSName = GetLine("OS Name: ");
			OSVersion = GetLine("OS Version: ");
			ToolPack = GetLine("Tool Pack: ");
			NumberOfRegalia = Int("Number of regalia: ");
			Employees[i] = new System_architect(FullName, CompanyName, AccessPass, Salary, OSName, OSVersion, ToolPack, NumberOfRegalia);
			break;
		case 2:
			FullName = GetLine("Full Name: ");
			CompanyName = GetLine("Company Name: ");
			AccessPass = GetLine("Access Password: ");
			Salary = Int("Salary: ");
			TypeOfNetwork = GetLine("Type of network: ");
			Employees[i] = new Network_admin(FullName, CompanyName, AccessPass, Salary, TypeOfNetwork);
			break;
		}
		std::cout << endl;
	}

	std::cout << endl << "Output:" << endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Employee #" << i + 1 << ":" << endl;
		Employees[i]->Show();
		Employees[i]->Count();
		std::cout << endl << endl;
	}
	//freeing memory
	for (int i = 0; i < size; i++)
		delete Employees[i];
	delete Employees;
}

int Int(string messege) {

	std::cout << messege;
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
			std::cout << "Incorrect entry, try again: ";
		}
	} while (failInput);
	std::cout << endl;
	return stoi(value);
}

string GetLine(string messege) {
	std::cout << messege;
	string value;
	bool failInput;
	do
	{
		failInput = false;
		getline(cin, value);
		if (value.empty()) {
			failInput = true;
			std::cout << "Incorrect entry, try again: ";
		}
	} while (failInput);

	return value;
}
