#include "Headers.h"
#include "Exception.h"
#include "Detail.h"
#include "Algorithms.h"

int main()
{
	lab9::Algorithms Alg;
	std::cout << "FIRST ALGORITHM" << std::endl << std::endl;
	Alg.First("1st.txt");
	system("pause");
	system("CLS");

	std::cout << "SECOND ALGORITHM" << std::endl << std::endl;
	std::set<lab9::Detail> Detail_set
	{
		lab9::Detail(2, "bolt", 1),
		lab9::Detail(4, "hinge", 15),
		lab9::Detail(1, "beam", 295),
		lab9::Detail(3, "armature", 115),
		lab9::Detail(7, "lag", 512),
		lab9::Detail(9, "frame", 2300),
		lab9::Detail(8, "bar", 1250)
	};
	Alg.Second(Detail_set.begin(), Detail_set.end());
	system("pause");
	system("CLS");

	std::cout << "THIRD ALGORITHM" << std::endl;
	Alg.Third(Detail_set.begin(), Detail_set.end(), "3rd.txt");

}