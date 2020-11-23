#include "System_architect.h"

void System_architect::Show()
{
	cout << endl << "Full Name: " << this->FullName << endl;
	cout << "Company Name: " << this->CompanyName << endl;
	cout << "Access Password: " << this->AccessPass << endl;
	cout << "Salary: " << this->Salary << endl;
	cout << "OS Name: " << this->OSName << endl;
	cout << "OS Version: " << this->OSVersion << endl;
	cout << "Tool Pack: " << this->ToolPack << endl;
	cout << "Number of regalia: " << this->NumberOfRegalia << endl;
}

void System_architect::Count() 
{
	cout << "System architect salary per year: " << (this->Salary) * 12 << endl;
}

System_architect::System_architect(string FullName, string CompanyName, string AccessPass, int Salary, string OSName, string OSVersion, string ToolPack, int NumberOfRegalia) : Computer_admin(FullName, CompanyName, AccessPass, Salary, OSName, OSVersion, ToolPack)
{
	this->NumberOfRegalia = NumberOfRegalia;
	
}

System_architect::System_architect()
{
	this->NumberOfRegalia = 999;
}

System_architect::~System_architect()
{
	cout << this->FullName << " lost his powers as a system architect" << endl;
}
