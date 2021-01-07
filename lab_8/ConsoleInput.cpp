#include "ConsoleInput.h"

int ConsoleInput::GetNum()
{
	//Input buffer clear 
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	bool failInput;
	std::string value;
	int return_val;
	do
	{
		failInput = false;
		getline(std::cin, value);

		if (value.find_first_not_of("0123456789") != std::string::npos || value.empty())
		{
			failInput = true;
			std::cout << "Invalid input. Enter again: ";
		}
		if (!failInput)
		{
			try
			{
				return_val = stoi(value);
			}
			catch (...)
			{
				failInput = true;
				std::cout << "Invalid input. Enter again: ";
			}
		}
	} while (failInput);
	return return_val;
}
int ConsoleInput::ChoiceBetween(int a, int b)
{
	bool flag;
	int answer;
	do
	{
		answer = GetNum();
		if (answer >= a && answer <= b)
			flag = true;
		else
		{
			std::cout << "Answer must be between " << a << " and " << b << ": ";
			flag = false;
		}

	} while (!flag);
	return answer;
}