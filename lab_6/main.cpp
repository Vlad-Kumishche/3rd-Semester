#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
#include <Windows.h>

using namespace std;

//Allows to get a string.
//The function itself dynamically
//allocates memory for the string
char *get_string(int*);

//Allows you to get a number
//entered from the keyboard,
//both fractional and integer
template<typename T>
T GetNum();

//Allows initialization of generic type, manually and randomly
template <typename T>
void initArr(T*, int, int);

//Allows you to enter a value in the range between A and B
int ChoiceBetween(int, int);

//Finds the max value in a generic type array
template <typename T>
T max_val(T*, int);

//Explicit specialization for char*
//The function compares English letters alphabetically,
//but Russian ones by ASCII code.
//Russian and English among themselves also by ASCII code
template <>
char max_val<char>(char*, int);

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Please select a data type:\n 1. int\n 2. double\n 3. char*\n 4. long long\n 5. float\nYour choice: ";
	int dataType = ChoiceBetween(1, 5);

	cout << "\nFill the array:\n 1. random numbers\n 2. manually\nYour choice: ";
	int initMethod = ChoiceBetween(1, 2);

	int size;
	//You don't need to set the length of the char* for manual input
	if (dataType != 3 || initMethod != 2)
	{
		cout << "Enter the size of the array: ";
		size = GetNum<int>();
	}

	switch (dataType)
	{
	case 1:
	{
		int* arr = new int[size];
		initArr<int>(arr, size, initMethod);
		cout << "Max value: " << max_val<int>(arr, size) << endl;
	}
	break;
	case 2:
	{
		double* arr = new double[size];
		initArr<double>(arr, size, initMethod);
		cout << "Max value: " << max_val<double>(arr, size) << endl;
	}
	break;
	case 3:
	{
		if (initMethod == 1)
		{
			char* arr = new char[size];
			initArr<char>(arr, size, initMethod);
			cout << "Max value: " << max_val<char>(arr, size) << endl;
		}
		else
		{
			cout << "Please enter the string: ";
			char* arr = nullptr;
			bool flag;

			//input check
			do
			{
				flag = false;
				arr = get_string(&size);
				if (arr[0] == '\0')
				{
					cout << "Enter at least one character: ";
					flag = true;
				}
			} while (flag);

			cout << "Max value: " << max_val<char>(arr, size) << endl;
		}
		
	}
	break;
	case 4:
	{
		long long* arr = new long long[size];
		initArr<long long>(arr, size, initMethod);
		cout << "Max value: " << max_val<long long>(arr, size) << endl;
	}
	break;
	case 5:
	{
		float* arr = new float[size];
		initArr<float>(arr, size, initMethod);
		cout << "Max value: " << max_val<float>(arr, size) << endl;
	}
	break;
	}
}
char *get_string(int *len) {
	*len = 0;
	int capacity = 1;
	char *s = (char*)malloc(capacity * sizeof(char));
	char c = getchar();
	while (c != '\n') {
		s[(*len)++] = c;
		if (*len >= capacity) {
			capacity *= 2;
			s = (char*)realloc(s, capacity * sizeof(char));
		}
		c = getchar();
	}
	s[*len] = '\0';
	return s;
}

template<typename T>
T GetNum() 
{
	//Input buffer clear 
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	bool failInput;
	string value;
	T return_val;
	do
	{
		failInput = false;
		getline(cin, value);
		if (typeid(T).name() == typeid(double).name() || typeid(T).name() == typeid(float).name())
		{
			if (value.find_first_not_of("0123456789.") != std::string::npos || value.empty()) {
				failInput = true;
				cout << "Incorrect entry, try again: ";
			}
		}
		else
		{
			if (value.find_first_not_of("0123456789") != std::string::npos || value.empty()) {
				failInput = true;
				cout << "Incorrect entry, try again: ";
			}
		}

		if (!failInput) {
			try
			{
				if (typeid(T).name() == typeid(double).name() || typeid(T).name() == typeid(float).name())
					return_val = stod(value);
				else
					return_val = stoi(value);
			}
			catch (...)
			{
				failInput = true;
				cout << "Incorrect entry, try again: ";
			}
		}
	} while (failInput);
	return return_val;
}

template <typename T>
void initArr(T* arr, int size, int initMethod)
{
	if (initMethod == 1)
	{
		cout << "\nGenerated array:\n";
		for (int i = 0; i < size; i++)
		{
			if (typeid(T).name() == typeid(double).name() || typeid(T).name() == typeid(float).name())
			{
				double f = (double)rand() / RAND_MAX;
				arr[i] = f * (double)rand();
			}
			else if (typeid(T).name() == typeid(char).name())
			{
				//A ... Z, a ... z and a couple of non-letters
				arr[i] = (rand()%58)+65;
				//replace non-letters with spaces
				if (arr[i] <= 96 && arr[i] >= 91)
					arr[i] = ' ';
				cout << (char)arr[i];
				continue;
			}
			else
			{
				arr[i] = rand();
			}
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			//Manual string input is implemented inside
			//the switch construction in the main function
			//therefore there is no implementation here

			cout << "arr[" << i << "] = ";
			arr[i] = GetNum<T>();
		}
	}
}

int ChoiceBetween(int a, int b)
{
	bool flag;
	int answer;
	do
	{
		answer = GetNum<int>();
		if (answer <= b && answer >= a)
			flag = true;
		else
		{
			cout << "The answer must be between " << a << " and " << b << ": ";
			flag = false;
		}

	} while (!flag);
	return answer;
}

template <typename T>
T max_val(T* arr, int size)
{
	T max = arr[0];
	for (int i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

template <>
char max_val<char>(char* arr, int size)
{
	char max = SCHAR_MIN;
	bool EngCapitalLetter = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= 122 && arr[i] >= 97)
		{
			char spec = arr[i] - 32;
			if (max < spec && arr[i] != ' ')
			{
				max = spec;
				EngCapitalLetter = false;
			}

		}
		else
			if (max < arr[i] && arr[i] != ' ')
			{
				max = arr[i];
				EngCapitalLetter = true;
			}
	}

	return EngCapitalLetter ? max : max + 32;
}