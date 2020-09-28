#include "array.h"
using namespace std;

//Default constructor
Array::Array(){
	this->length = 3;
	this->arr = new int[length];

	for (int i = 0; i < this->length; i++)
		this->arr[i] = 0;
}

//Init constructor
Array::Array(unsigned length) {
	this->length = length;
	this->arr = new int[length];

	for (int i = 0; i < this->length; i++)
		this->arr[i] = 0;
}

//Copy Constructor
Array::Array(const Array &B) {
	this->length = B.length;
	this->arr = new int[length];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = B.arr[i];
}

//Destructor
Array::~Array() {
	delete[] this->arr;
}

//Printing the entire array
void Array::print()
{
	cout << "Array: " << endl;
	for (int i = 0; i < this->length; i++)
		cout << this->arr[i] << " ";

	cout << endl;
}

//Get element by index
int Array::get(unsigned i) {
	if (i < this->length)
		return this->arr[i];
	else {
		cout << "\nThere is no such element with index " << i << endl;
		return NULL;
	}
}

//Set element by index
void Array::handle_set(unsigned i) {
	cout << "arr[" << i << "] = ";
	bool failInput;
	do
	{
		failInput = false;
		cin >> this->arr[i];
		if (cin.fail()) {
			failInput = true;
			cout << "Incorrect entry, try again: ";

			//Input buffer clear 
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
	} while (failInput);
}

//Set element value
void Array::set(unsigned i, int value) {
	this->arr[i] = value;
}

void Array::random_init(int lim) {
	for (int i = 0; i < this->get_length(); i++)
		this->set(i, rand() % lim);
}

void Array::handle_init() {
	for (int i = 0; i < this->get_length(); i++)
		this->handle_set(i);
}

int Array::get_length() {
	return this->length;
}

bool Array::operator < (Array B) {
	return (this->length < B.length) ? true : false;
}

bool Array::operator > (Array B) {
	return (this->length > B.length) ? true : false;
}

//Summation principle - array "concatenation"
Array Array::operator + (Array B) {
	int result_length = this->length + B.length;
	Array result(result_length);

	for (int i = 0; i < this->length; i++)
		result.set(i, this->arr[i]);
	for (int i = this->length, j = 0; i < result_length; i++, j++)
		result.set(i, B.arr[j]);

	return result;
}

//Friend stream output function
std::ostream& operator<<(std::ostream &out, const Array &point) {
	for (int i = 0; i < point.length; i++)
		out << point.arr[i] << " ";

	return out;
}

void Array::shellSort() {
	for (int gap = this->length / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < this->length; i += 1)
		{
			int temp = this->arr[i];
			int j;
			for (j = i; j >= gap && this->arr[j - gap] < temp; j -= gap)
				this->arr[j] = this->arr[j - gap];

			this->arr[j] = temp;
		}
	}
}