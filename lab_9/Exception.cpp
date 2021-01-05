#include "Exception.h"

void lab9::Terminate()
{
	std::cerr << "\nTerminate handler called" << std::endl;
	abort();
}
void lab9::Unexpected()
{
	std::cerr << "\nUnexpected exception" << std::endl;
	terminate();
}
void lab9::Exception::PrintError()
{
	std::cout << "Exception: " << message_ << std::endl;
}