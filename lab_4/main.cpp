#include <iostream>
#include "DevOps.h"

using namespace std;

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
	return stoi(value);
}
string GetLine(string messege) {
	cout << messege;
	string value;
	bool failInput;
	do
	{
		failInput = false;
		getline(cin, value);
		if (value.empty()) {
			failInput = true;
			cout << "Incorrect entry, try again: ";
		}
	} while (failInput);

	return value;
}

int main()
{
	string FullName, CompanyName, AccessPass, OSName, OSVersion, ToolPack,
		TypeOfNetwork, Specialization, degreeOfSteepness;

	int Salary, NumberOfRegalia;

	FullName		  = GetLine("Full Name: ");
	CompanyName		  = GetLine("Company Name: ");
	AccessPass		  = GetLine("Access Password: ");
	Salary			  = Int("Salary: ");
	OSName			  = GetLine("OS Name: ");
	OSVersion		  = GetLine("OS Version: ");
	ToolPack		  = GetLine("Tool Pack: ");
	NumberOfRegalia	  = Int("Number of regalia: ");
	TypeOfNetwork	  = GetLine("Type of network: ");
	Specialization	  = GetLine("Specialization: ");
	degreeOfSteepness = GetLine("Degree of steepness: ");

	DevOps* Ivan = new DevOps(FullName, CompanyName, AccessPass, Salary, OSName, OSVersion, ToolPack,
		NumberOfRegalia, TypeOfNetwork, Specialization, degreeOfSteepness);

	Ivan->ShowDevOpsInfo();
}