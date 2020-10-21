#pragma once
#include "Administrator.h"
class Network_admin :
	virtual public Administrator
{
protected:
	string TypeOfNetwork;
public:
	void ShowNetwork_adminInfo();
	Network_admin(string, string, string, int, string);
	Network_admin();
	~Network_admin();
};

