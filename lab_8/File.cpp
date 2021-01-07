#include "File.h"

File::File() : length(0) {}
File::~File()
{
	Close();
}

void File::OpenBinFile(string path) {
	try
	{
		file.open(path, ios::binary | ios::in | ios::out | ios::trunc);
		path = path;
		if (!file.is_open())
		{
			Exception("OpenBinFile: File open error");
		}
	}
	catch (Exception error)
	{
		error.PrintError();
	}
}

void File::BubbleSortById() {
	cout << "Sort by vendor code:" << endl;
	for (int i = 0; i < GetLength() - 1; i++)
	{
		for (int j = 0; j < GetLength() - i - 1; j++)
		{
			if (GetObjectByIndex(j)->get_id() > GetObjectByIndex(j + 1)->get_id())
			{
				Swap(j, j + 1);
			}
		}
	}
	Print();
}
void File::BubbleSortByPrice() {
	cout << "Sort by price:" << endl;
	for (int i = 0; i < GetLength() - 1; i++)
	{
		for (int j = 0; j < GetLength() - i - 1; j++)
		{
			if (GetObjectByIndex(j)->get_price() > GetObjectByIndex(j + 1)->get_price())
			{
				Swap(j, j + 1);
			}
		}
	}
	Print();
}
void File::BubbleSortByQuantity() {
	cout << "Sort by quantity:" << endl;
	for (int i = 0; i < GetLength() - 1; i++)
	{
		for (int j = 0; j < GetLength() - i - 1; j++)
		{
			if (GetObjectByIndex(j)->get_quantity() > GetObjectByIndex(j + 1)->get_quantity())
			{
				Swap(j, j + 1);
			}
		}
	}
	Print();
}
void File::BubbleSortByName(bool need_to_output) {
	if (need_to_output)
	{
		cout << "Sort by name:" << endl;
	}
	for (int i = 0; i < GetLength() - 1; i++)
	{
		for (int j = 0; j < GetLength() - i - 1; j++)
		{
			if (GetObjectByIndex(j)->get_name() > GetObjectByIndex(j + 1)->get_name())
			{
				Swap(j, j + 1);
			}
		}
	}
	if (need_to_output)
	{
		Print();
	}
}
void File::SortByNameWithPriceLessThanX(int required_price, bool need_to_delete)
{
	BubbleSortByName(false);
	vector<int> deleted_objects;
	for (int i = 0; i < GetLength(); i++)
	{
		if (GetObjectByIndex(i)->get_price() > required_price)
		{
			if (need_to_delete)
			{
				deleted_objects.push_back(i);
			}
		}
		else
		{
			cout << GetObjectByIndex(i)->ToString() << endl;
		}
	}
	int number_of_deleted_objects = 0;
	for (int i : deleted_objects)
	{
		DeleteObject(i - number_of_deleted_objects);
		++number_of_deleted_objects;
	}
	if (!GetLength())
	{
		cout << endl << "None of the elements fit the requirements" << endl;
	}
}
void File::Swap(int i, int j) {
	try
	{
		if (!file.is_open())
		{
			throw Exception("Swap: File open error");
		}
		try
		{
			if (i >= length || i < 0 || j >= length || j < 0)
			{
				throw Exception("Swap: out of bounds");
			}
			Shoes* tmp = GetObjectByIndex(i);
			Insert(GetObjectByIndex(j), i);
			Insert(tmp, j);
		}
		catch (Exception error)
		{
			error.PrintError();
			Terminate();
		}
	}
	catch (Exception error)
	{
		error.PrintError();
		Terminate();
	}
}

void File::Insert(Shoes* object, int index) {
	try
	{
		if (!file.is_open())
		{
			throw Exception("Insert: File open error");
		}
		if (index < 0)
		{
			file.seekg(length * sizeof(Shoes));
			length++;
		}
		else
		{
			try
			{
				if (index >= length)
				{
					throw Exception("Insert: out of bounds");
				}
				file.seekg(index * sizeof(Shoes));
			}
			catch (Exception error)
			{
				error.PrintError();
				Terminate();
			}
		}
		file.write((char*)object, sizeof(Shoes));
	}
	catch (Exception error)
	{
		error.PrintError();
		Terminate();
	}
}
void File::ReadIntoSingleObject(Shoes* object, int index) {
	try
	{
		if (!file.is_open())
		{
			throw Exception("ReadIntoSingleObject: File open error");
		}
		file.seekg(index * sizeof(Shoes));
		file.read((char*)object, sizeof(Shoes));
	}
	catch (Exception error)
	{
		error.PrintError();
		Terminate();
	}
}

void File::Print() {
	for (int i = 0; i < GetLength(); i++)
	{
		cout << GetObjectByIndex(i)->ToString() << endl;
	}
	if (!GetLength())
	{
		cout << "The file is empty" << endl;
	}
	cout << endl;
}

Shoes* File::GetObjectByIndex(int index) {
	try
	{
		if (!file.is_open())
		{
			throw Exception("GetObjectByIndex: File open error");
		}
		try
		{
			if (index >= length || index < 0)
			{
				throw Exception("GetObjectByIndex: out of bounds");
			}
			Shoes* object = new Shoes;
			file.seekg(index * sizeof(Shoes));
			file.read((char*)object, sizeof(Shoes));
			return object;
		}
		catch (Exception error)
		{
			error.PrintError();
			Terminate();
		}
	}
	catch (Exception error)
	{
		error.PrintError();
		Terminate();
	}
}
Shoes* File::DeleteObject(int index) {
	try
	{
		if (!file.is_open())
		{
			throw Exception("DeleteObject: File open error");
		}
		try
		{
			if (index >= length || index < 0)
			{
				throw Exception("DeleteObject: out of bounds");
			}
			Shoes* res = GetObjectByIndex(index);
			for (int i = index + 1; i < GetLength(); i++)
			{
				Shoes* tmp = new Shoes;
				ReadIntoSingleObject(tmp, i);
				Insert(tmp, i - 1);
			}

			length--;

			return res;
		}
		catch (Exception error)
		{
			error.PrintError();
			Terminate();
		}
	}
	catch (Exception error)
	{
		error.PrintError();
		Terminate();
	}
}

void File::DeleteObjectWithQuantityLessThanX(int required_quantity)
{
	cout << endl << "List of deleted objects:" << endl;
	int counter = 0;
	for (int i = 0; i < GetLength(); i++)
	{
		if (GetObjectByIndex(i)->get_quantity() < required_quantity)
		{
			Shoes* to_be_removed = DeleteObject(i);
			cout << to_be_removed->ToString() << endl;
			++counter;
			--i;
		}
	}
	if (!counter)
	{
		cout << "None of the objects meet the conditions for deletion" << endl;
	}
}


int File::GetLength()
{
	return length;
}
void File::SetSeek(int s)
{
	file.seekg(s);
}
bool File::IsOpen()
{
	return file.is_open();
}
void File::Close()
{
	file.close();
}
