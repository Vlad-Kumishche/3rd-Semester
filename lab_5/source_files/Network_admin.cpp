#include "Network_admin.h"


void Network_admin::Show()
{
	cout << endl << "Full Name: " << this->FullName << endl;
	cout << "Company Name: " << this->CompanyName << endl;
	cout << "Access Password: " << this->AccessPass << endl;
	cout << "Salary: " << this->Salary << endl;
	cout << "Type of network: " << this->TypeOfNetwork << endl;
}

void Network_admin::Count()
{
	cout << "Network admin salary per year: " << (this->Salary) * 12 << endl;
}

Network_admin::Network_admin(string FullName, string CompanyName, string AccessPass, int Salary, string TypeOfNetwork) : Administrator(FullName, CompanyName, AccessPass, Salary)
{
	this->TypeOfNetwork = TypeOfNetwork;
}

Network_admin::Network_admin()
{
	this->TypeOfNetwork = "Single-service local area network with centralized control";
}

Network_admin::~Network_admin()
{
	cout << this->FullName << " lost his powers as a network administrator" << endl;
}
