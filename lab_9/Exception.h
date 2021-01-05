#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Headers.h"
namespace lab9
{
	void Terminate();
	void Unexpected();

	class Exception
	{
	public:
		Exception() : message_("Something went wrong") {}
		Exception(std::string error) : message_(error) {}
		void PrintError();
	private:
		std::string message_;
	};
}
#endif