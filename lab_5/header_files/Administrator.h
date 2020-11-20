#pragma once
#include <iostream>
#include <string>

using namespace std;

class Administrator
{
protected:
	string FullName;
	string CompanyName;
	string AccessPass;
	int Salary;
public:
	virtual void Show() = 0;
	virtual void Count() = 0;
	Administrator(string, string, string, int);
	Administrator();
	virtual ~Administrator();
};

