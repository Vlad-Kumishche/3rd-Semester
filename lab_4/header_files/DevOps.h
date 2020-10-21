#pragma once
#include "Network_security_admin.h"
#include "System_architect.h"

class DevOps :
	public Network_security_admin, public System_architect
{
protected:
	string degreeOfSteepness;
public:
	void ShowDevOpsInfo();
	DevOps(string, string, string, int, string, string, string, int, string, string, string);
	~DevOps();
};

