#include "Administrator.h"

Administrator::Administrator(string FullName, string CompanyName, string AccessPass, int Salary)
{
	this->FullName = FullName;
	this->CompanyName = CompanyName;
	this->AccessPass = AccessPass;
	this->Salary = Salary;
}

Administrator::Administrator()
{
	this->FullName = "Ivan Ivanovich Ivanov";
	this->CompanyName = "ERAT";
	this->AccessPass = "123456";
	this->Salary = 2400;
}

Administrator::~Administrator()
{
	cout << "Oops, it looks like " << FullName << " was fired. That's the worst" << endl << endl;
}
