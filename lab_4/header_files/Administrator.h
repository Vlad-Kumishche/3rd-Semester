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
	void ShowEmployeeInfo();
	Administrator(string, string, string, int);
	Administrator();
	~Administrator();
};

