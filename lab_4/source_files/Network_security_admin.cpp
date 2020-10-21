#include "Network_security_admin.h"

void Network_security_admin::ShowNetwork_security_adminInfo() {
	cout << "Specialization: " << this->Specialization << endl;
}

Network_security_admin::Network_security_admin(string FullName, string CompanyName, string AccessPass, int Salary, string TypeOfNetwork, string Specialization) : Network_admin(FullName, CompanyName, AccessPass, Salary, TypeOfNetwork)
{
	this->Specialization = Specialization;
}


Network_security_admin::~Network_security_admin()
{
	cout << this->FullName << " lost his powers as a network security administrator" << endl;
}
