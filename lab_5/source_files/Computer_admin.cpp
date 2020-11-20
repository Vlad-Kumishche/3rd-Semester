#include "Computer_admin.h"

void Computer_admin::Show()
{
	cout << "OS Name: " << this->OSName << endl;
	cout << "OS Version: " << this->OSVersion << endl;
	cout << "Tool Pack: " << this->ToolPack << endl;
}

void Computer_admin::Count()
{
	cout << "Computer admin salary per year: " << (this->Salary) * 12 << endl;
}

Computer_admin::Computer_admin(string FullName, string CompanyName, string AccessPass, int Salary, string OSName, string OSVersion, string ToolPack) : Administrator(FullName, CompanyName, AccessPass, Salary)
{
	this->OSName = OSName;
	this->OSVersion = OSVersion;
	this->ToolPack = ToolPack;
}

Computer_admin::Computer_admin()
{
	this->OSName = "Shindows";
	this->OSVersion = "1.6";
	this->ToolPack = "Console";
}


Computer_admin::~Computer_admin()
{
	cout << this->FullName << " lost his powers as a computer administrator" << endl;
}
