#include "Exception.h"
void Terminate()
{
	cerr << "\nTerminate handler called" << endl;
	abort();
}
void Unexpected()
{
	cerr << "\nUnexpected exception" << endl;
	terminate();
}

Exception::Exception() : message_("Something went wrong") {}
Exception::Exception(string error) : message_(error) {}
void Exception::PrintError()
{
	cout << "Exception: " << message_ << endl;
}