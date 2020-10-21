#pragma once
#include "Administrator.h"

class Computer_admin :
	virtual public Administrator
{
protected: 
	string OSName;
	string OSVersion;
	string ToolPack;
public:
	void ShowComputer_adminInfo();
	Computer_admin(string, string, string, int, string, string, string);
	Computer_admin();
	~Computer_admin();
};

