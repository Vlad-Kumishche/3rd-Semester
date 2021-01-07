#ifndef SHOES_H
#define SHOES_H
#include "Headers.h"
#include "Exception.h"
class Shoes
{
public:
	Shoes();
	Shoes(int id, int quantity, int price, string name);
	~Shoes();

	int get_id() const;
	string get_name() const;
	int get_quantity() const;
	int get_price() const;

	void set_id(int id);
	void set_name(const string name);
	void set_quantity(int quantity);
	void set_price(int price);

	bool operator == (Shoes operand) const;
	bool operator < (Shoes operand) const;
	bool operator > (Shoes operand) const;
	bool operator <= (Shoes operand) const;
	
	string ToString();
private:
	int id_;
	int price_;
	int quantity_;
	string name_;
};
#endif