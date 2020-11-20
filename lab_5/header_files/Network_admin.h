#pragma once
#include "Administrator.h"
class Network_admin :
	public Administrator
{
protected:
	string TypeOfNetwork;
public:
	void Show();
	void Count();
	Network_admin(string, string, string, int, string);
	Network_admin();
	~Network_admin();
};

