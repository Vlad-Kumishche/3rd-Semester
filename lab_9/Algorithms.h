#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Headers.h"
#include "Exception.h"
#include "Detail.h"
namespace lab9
{
	class Algorithms
	{
	public:
		void Show(std::set<Detail>::const_iterator begin, std::set<Detail>::const_iterator end);
		void First(std::string path);
		int Second(std::set<Detail>::const_iterator begin, std::set<Detail>::const_iterator end);
		void Third(std::set<Detail>::const_iterator begin, std::set<Detail>::const_iterator end, std::string path);
		int GetNum();
	};
}
#endif
