#include "Detail.h"

lab9::Detail::~Detail()
{
	id_ = 0;
	name_ = "";
	mass_ = 0;
}
int lab9::Detail::get_id() const
{
	return id_;
}
std::string lab9::Detail::get_name() const
{
	return name_;
}
int lab9::Detail::get_mass() const
{
	return mass_;
}
void lab9::Detail::set_id(int id)
{
	try
	{
		if (id > 0)
		{
			id_ = id;
			return;
		}
		throw Exception("id cannot be less than zero");
	}
	catch (Exception error)
	{
		error.PrintError();
		id_ = 1;
	}
}
void lab9::Detail::set_name(const std::string name)
{
	try
	{
		if (name != "")
		{
			name_ = name;
			return;
		}
		throw Exception("name not set");
	}
	catch (Exception error)
	{
		error.PrintError();
		name_ = "unnamed";
	}
}
void lab9::Detail::set_mass(int mass)
{
	try
	{
		if (mass > 0)
		{
			mass_ = mass;
			return;
		}
		throw Exception("mass cannot be less than zero");
	}
	catch (Exception error)
	{
		error.PrintError();
		mass_ = 1;
	}
}
bool lab9::Detail::operator == (Detail operand) const
{
	return (this->id_ == operand.id_) ? true : false;
}
bool lab9::Detail::operator < (Detail operand) const
{
	return (this->id_ < operand.id_) ? true : false;
}
bool lab9::Detail::operator > (Detail operand) const
{
	return (this->id_ > operand.id_) ? true : false;
}
bool lab9::Detail::operator <= (Detail operand) const
{
	return (this->id_ <= operand.id_) ? true : false;
}
std::ostream& lab9::operator << (std::ostream& out, Detail obj)
{
	out << "ID: " << obj.get_id() << "; name: " << obj.get_name() << "; mass: " << obj.get_mass() << ";" << std::endl;
	return out;
}