#include "DevOps.h"

void DevOps::ShowDevOpsInfo() {
	ShowEmployeeInfo();
	ShowComputer_adminInfo();
	ShowSystem_architectInfo();
	ShowNetwork_adminInfo();
	ShowNetwork_security_adminInfo();
	cout << "Degree of steepness: " << this->degreeOfSteepness << endl << endl;
}

DevOps::DevOps(string FullName, string CompanyName, string AccessPass, int Salary, string OSName, string OSVersion, string ToolPack, int NumberOfRegalia, string TypeOfNetwork, string Specialization, string degreeOfSteepness) : Network_security_admin(FullName, CompanyName, AccessPass, Salary, TypeOfNetwork, Specialization), System_architect(FullName, CompanyName, AccessPass, Salary, OSName, OSVersion, ToolPack, NumberOfRegalia), Administrator(FullName, CompanyName, AccessPass, Salary)
{
	this->degreeOfSteepness = degreeOfSteepness;
}


DevOps::~DevOps()
{
	cout << this->FullName << " lost his powers as a DevOps engener" << endl;
}
