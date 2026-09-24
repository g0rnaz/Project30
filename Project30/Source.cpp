#include "Header.h"
int main()
{
	srand(time(0));

	Myvector<int> obj(5);

	cout << obj.isempty() << endl;
	obj.setat(1, 0);
	cout << obj.GetUpperBound() << endl;
	obj.setat(1, 3);
	obj.Print();
	obj.freextra();
	obj.Print();
	obj.insertat(1,2);
	obj.Print();
	obj.add(1, 4);
	obj.Print();
	obj.append(obj);
	obj.Print();
}