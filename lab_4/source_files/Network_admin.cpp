#include "Network_admin.h"


void Network_admin::ShowNetwork_adminInfo() {
	cout << "Type of network: " << this->TypeOfNetwork << endl;
}


Network_admin::Network_admin(string FullName, string CompanyName, string AccessPass, int Salary, string TypeOfNetwork) : Administrator(FullName, CompanyName, AccessPass, Salary)
{
	this->TypeOfNetwork = TypeOfNetwork;
}

Network_admin::Network_admin()
{
}

Network_admin::~Network_admin()
{
	cout << this->FullName << " lost his powers as a network administrator" << endl;
}
