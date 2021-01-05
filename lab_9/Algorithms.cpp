#include "Algorithms.h"
void lab9::Algorithms::Show(std::set<Detail>::const_iterator begin, std::set<Detail>::const_iterator end)
{
	while (begin != end)
	{
		std::cout << *begin;
		++begin;

	}
}
void lab9::Algorithms::First(std::string path)
{
	std::ifstream f;
	f.open(path);
	if (!f.is_open())
	{
		std::cout << "File open error" << std::endl;
		return;
	}
	else
	{
		std::cout << "File " << path << " is opened" << std::endl;
	}
	std::unordered_multimap<int, char> char_set;
	int index = 0;
	auto iter = char_set.begin();
	bool is_correct = true;
	std::string message;
	while (f.is_open() && !f.eof() && is_correct)
	{
		std::string line;
		getline(f, line);
		if (!line.empty())
		{
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == '(' ||
					line[i] == '{' ||
					line[i] == '[' ||
					line[i] == '<')
				{
					char_set.emplace(index++, line[i]);
					std::cout << "Read parenthesis '" << line[i] << "'" << std::endl;
				}

				if (line[i] == ')' ||
					line[i] == '}' ||
					line[i] == ']' ||
					line[i] == '>')
				{
					char opening;
					if (!char_set.empty())
					{
						iter = char_set.end();
						--iter;
						opening = (*iter).second;
					}
					else
					{
						std::cout << "Read parenthesis '" << line[i] << "' nested incorrectly" << std::endl;
						message = "Nested parentheses are INCORRECT";
						is_correct = false;
						break;
					}
					char closing;
					switch (opening)
					{
					case '(':
						closing = ')';
						break;
					case '{':
						closing = '}';
						break;
					case '[':
						closing = ']';
						break;
					case '<':
						closing = '>';
						break;
					}
					if (line[i] == closing)
					{
						std::cout << "Read parenthesis '" << line[i] << "' nested correctly" << std::endl;
						char_set.erase(iter);
					}
					else
					{
						std::cout << "Read parenthesis '" << line[i] << "' nested incorrectly" << std::endl;
						message = "Nested parentheses are INCORRECT";
						is_correct = false;
						break;
					}
				}
			}
		}
	}
	if (is_correct)
	{
		message = "Nested parentheses are correct";
	}
	std::cout << message << std::endl;
	f.close();
	std::ofstream out;
	out.open("result_" + path);
	if (out.is_open())
	{
		out << message << std::endl;
		std::cout << std::endl << "The result of the algorithm was written to a file named " << "result_" + path << std::endl;
	}
	else
	{
		std::cout << "Result file open error" << std::endl;
		return;
	}
}
int lab9::Algorithms::Second(std::set<Detail>::const_iterator begin, std::set<Detail>::const_iterator end)
{
	std::cout << "It's the function for counting the number of elements whose mass is greater than or equals to X" << std::endl;
	std::cout << "Current Set: " << std::endl;
	Show(begin, end);
	std::cout << std::endl << "Enter X: ";
	int comparison_mass = GetNum();
	int counter = 0;
	std::cout << "Result:" << std::endl;
	while (begin != end)
	{
		if ((*begin).get_mass() >= comparison_mass)
		{
			++counter;
			std::cout << *begin;
		}
		++begin;
	}
	std::cout << "Total: " << counter << std::endl;
	return counter;
}
void lab9::Algorithms::Third(std::set<Detail>::const_iterator begin, std::set<Detail>::const_iterator end, std::string path)
{
	std::cout << "It's the a function that moves a set of elements whose ID is less than or equal to X to a given location" << std::endl;
	std::cout << "File path: " << path << std::endl << std::endl;
	std::cout << "Current Set: " << std::endl;
	Show(begin, end);
	std::cout << std::endl << "Enter X: ";
	int comparison_id = GetNum();

	std::ofstream f;
	f.open(path);
	if (!f.is_open())
	{
		std::cout << "File open error" << std::endl;
		return;
	}
	else
	{
		std::cout << std::endl << "File " << path << " is opened" << std::endl << std::endl;
	}

	std::cout << "Result:" << std::endl;
	while (begin != end)
	{
		if ((*begin).get_id() <= comparison_id)
		{
			std::cout << *begin;
			f << *begin;
		}
		++begin;
	}
	f.close();
	std::cout << std::endl << "Result was written to " << path << std::endl;
}
int lab9::Algorithms::GetNum()
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