#include "System_architect.h"

void System_architect::ShowSystem_architectInfo() {
	cout << "Number of regalia: " << this->NumberOfRegalia << endl;
}

System_architect::System_architect(string FullName, string CompanyName, string AccessPass, int Salary, string OSName, string OSVersion, string ToolPack, int NumberOfRegalia) : Computer_admin(FullName, CompanyName, AccessPass, Salary, OSName, OSVersion, ToolPack)
{
	this->NumberOfRegalia = NumberOfRegalia;
}


System_architect::~System_architect()
{
	cout << this->FullName << " lost his powers as a system architect" << endl;
}
