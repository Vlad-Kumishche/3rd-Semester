#pragma once

#include "Computer_admin.h"
class System_architect :
	public Computer_admin
{
protected:
	int NumberOfRegalia;
public:
	void Show();
	void Count();
	System_architect(string, string, string, int, string, string, string, int);
	System_architect();
	~System_architect();
};

