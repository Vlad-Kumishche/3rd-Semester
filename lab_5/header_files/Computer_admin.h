#pragma once
#include "Administrator.h"

class Computer_admin :
	public Administrator
{
protected: 
	string OSName;
	string OSVersion;
	string ToolPack;
public:
	void Show();
	void Count();
	Computer_admin(string, string, string, int, string, string, string);
	Computer_admin();
	~Computer_admin();
};

