#ifndef FILE_H
#define FILE_H

#include "Headers.h"
#include "Exception.h"
#include "Shoes.h"
class File
{
public:

	File();
	~File();

	void OpenBinFile(string path);

	void BubbleSortById();
	void BubbleSortByPrice();
	void BubbleSortByQuantity();
	void BubbleSortByName(bool need_to_output = true);
	void SortByNameWithPriceLessThanX(int required_price, bool need_to_delete);
	void Swap(int i, int j);

	void Insert(Shoes* object, int index = -1);
	void ReadIntoSingleObject(Shoes* object, int index);

	void Print();

	Shoes* GetObjectByIndex(int index);
	Shoes* DeleteObject(int index);
	void DeleteObjectWithQuantityLessThanX(int required_quantity);

	int GetLength();
	void SetSeek(int s);
	bool IsOpen();
	void Close();
private:
	string path;
	fstream file;
	int length;
};
#endif