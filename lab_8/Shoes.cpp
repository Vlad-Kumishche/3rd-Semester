#include "Shoes.h"

Shoes::Shoes() : id_(0), quantity_(0), price_(0), name_("unnamed") {}
Shoes::Shoes(int id, int quantity, int price, string name) : id_(id), quantity_(quantity), price_(price), name_(name) {}
Shoes::~Shoes()
{
	id_ = 0;
	name_ = "";
	quantity_ = 0;
	price_ = 0;
}

int Shoes::get_id() const
{
	return id_;
}
string Shoes::get_name() const
{
	return name_;
}
int Shoes::get_quantity() const
{
	return quantity_;
}
int Shoes::get_price() const
{
	return price_;
}

void Shoes::set_id(int id)
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
		id_ = 0;
	}
}
void Shoes::set_name(const string name)
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
void Shoes::set_quantity(int quantity)
{
	try
	{
		if (quantity > 0)
		{
			quantity_ = quantity;
			return;
		}
		throw Exception("quantity cannot be less than zero");
	}
	catch (Exception error)
	{
		error.PrintError();
		quantity_ = 0;
	}
}
void Shoes::set_price(int price)
{
	try
	{
		if (price > 0)
		{
			price_ = price;
			return;
		}
		throw Exception("price cannot be less than zero");
	}
	catch (Exception error)
	{
		error.PrintError();
		price_ = 0;
	}
}

bool Shoes::operator == (Shoes operand) const
{
	return (this->id_ == operand.id_) ? true : false;
}
bool Shoes::operator < (Shoes operand) const
{
	return (this->id_ < operand.id_) ? true : false;
}
bool Shoes::operator > (Shoes operand) const
{
	return (this->id_ > operand.id_) ? true : false;
}
bool Shoes::operator <= (Shoes operand) const
{
	return (this->id_ <= operand.id_) ? true : false;
}

string Shoes::ToString()
{
	string res = "Vendor code: " + to_string(this->id_) + " Price: " + to_string(this->price_) + " Quantity: " + to_string(this->quantity_) + " Name: " + name_;
	return res;
}