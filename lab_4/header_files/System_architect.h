#pragma once

#include "Computer_admin.h"
class System_architect :
	public Computer_admin
{
protected:
	int NumberOfRegalia;
public:
	void ShowSystem_architectInfo();
	System_architect(string, string, string, int, string, string, string, int);
	~System_architect();
};

