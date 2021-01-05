#ifndef DETAIL_H
#define DETAIL_H
#include "Headers.h"
#include "Exception.h"

namespace lab9
{
	class Detail
	{
	public:
		Detail() : id_(0), name_("unnamed"), mass_(1) {}
		Detail(int id, std::string name, int mass) : id_(id), name_(name), mass_(mass) {}
		~Detail();

		int get_id() const;
		std::string get_name() const;
		int get_mass() const;

		void set_id(int id);
		void set_name(const std::string name);
		void set_mass(int mass);

		bool operator == (Detail operand) const;
		bool operator < (Detail operand) const;
		bool operator > (Detail operand) const;
		bool operator <= (Detail operand) const;

		friend std::ostream& operator << (std::ostream& out, Detail obj);
	private:
		int id_;
		std::string name_;
		int mass_;
	};
}
#endif
