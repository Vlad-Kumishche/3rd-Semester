#pragma once
#include "Network_admin.h"
class Network_security_admin :
	public Network_admin
{
protected:
	string Specialization;
public:
	void ShowNetwork_security_adminInfo();
	Network_security_admin(string, string, string, int, string, string);
	~Network_security_admin();
};

