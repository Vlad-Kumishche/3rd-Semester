#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Headers.h"
void Terminate();
void Unexpected();

class Exception
{
public:
	Exception();
	Exception(string error);
	void PrintError();
private:
	string message_;
};
#endif