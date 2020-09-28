#include <iostream>

class Array {
private:
	unsigned length;
	int* arr;
public:
	Array();
	Array(unsigned);
	Array(const Array&);
	~Array();

	void print();
	int get(unsigned);
	void handle_set(unsigned);
	void set(unsigned, int);
	void random_init(int);
	void handle_init();
	int get_length();

	
	bool operator < (Array B);
	bool operator > (Array B);
	Array operator + (Array B);

	friend std::ostream& operator<<(std::ostream&, const Array&);

	void shellSort();
};