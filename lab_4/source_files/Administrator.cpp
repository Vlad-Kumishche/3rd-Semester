#include "Administrator.h"

void Administrator::ShowEmployeeInfo() {
	cout << endl << "Full Name: " << this->FullName << endl;
	cout << "Company Name: " << this->CompanyName << endl;
	cout << "Access Password: " << this->AccessPass << endl;
	cout << "Salary: " << this->Salary << endl;
}

Administrator::Administrator(string FullName, string CompanyName, string AccessPass, int Salary)
{
	this->FullName = FullName;
	this->CompanyName = CompanyName;
	this->AccessPass = AccessPass;
	this->Salary = Salary;
}

Administrator::Administrator()
{
}

Administrator::~Administrator()
{
	cout << "Oops, it looks like " << FullName << " was fired. That's the worst" << endl << endl;
}
