#include "Headers.h"
#include "Shoes.h"
#include "File.h"
#include "BTree.h"
#include "ConsoleInput.h"

int main()
{
	//---Step 1------------------------------------------
	cout << "Step 1: Filling the file with data" << endl;
	BTree<Shoes> tree;
	Iterator<Shoes> it(&tree);

	File bin_file;
	string path = "test.bin";
	bin_file.OpenBinFile(path);
	
	it.Push(Shoes(345, 11760, 235, "Brogues"));
	it.Push(Shoes(224, 2400, 970, "Patent shoes"));
	it.Push(Shoes(698, 7650, 379, "High heels"));
	it.Push(Shoes(112, 15640, 450, "Suede boots"));
	it.Push(Shoes(887, 276, 1100, "Red Wings"));
	it.Push(Shoes(996, 3350, 150, "Moccasins"));
	it.Push(Shoes(456, 4560, 30, "Slippers"));

	tree.WriteTreeIntoBinFile(bin_file);

	cout << "Filled file:" << endl;
	bin_file.Print();
	system("pause");
	
	//---Step 2------------------------------------------
	system("CLS");
	cout << "Step 2: Demonstration of sorts" << endl;

	bin_file.BubbleSortById();
	bin_file.BubbleSortByPrice();
	bin_file.BubbleSortByQuantity();
	bin_file.BubbleSortByName();

	system("pause");

	//---Step 3------------------------------------------
	system("CLS");
	cout << "Step 3: Demonstration of conditional sorting" << endl << endl;

	cout << "Sort by name with price less than required." << endl
		<< "Please enter the required price: ";
	int required_price = ConsoleInput::GetNum();

	cout << endl << "Do you want to remove inappropriate items?" << endl;
	cout << "1 - no" << endl
		<< "2 - yes" << endl
		<< "Your choice: ";
	int need_to_delete = ConsoleInput::ChoiceBetween(1, 2);
	bin_file.SortByNameWithPriceLessThanX(required_price, (bool)(need_to_delete - 1));
	
	system("pause");
	
	//---Step 4------------------------------------------
	system("CLS");
	cout << "Step 4: Deleting an object from a file conditionally" << endl << endl;

	cout << "Removing objects with a quantity less than required" << endl
		<< "Please enter the required quantity: ";
	int required_quantity = ConsoleInput::GetNum();
	bin_file.DeleteObjectWithQuantityLessThanX(required_quantity);

	cout << endl << "Current file content:" << endl;
	bin_file.Print();
	bin_file.Close();
}
