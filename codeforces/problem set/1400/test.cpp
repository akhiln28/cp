#include <iostream>

using namespace std;

struct person
{
	int a = 1; 
	// void print()
	// {
	// 	a = 10; 
	// 	cout << "normal print " << a << endl;
	// }
	void print() const 
	{
		cout << "const print " << a << endl;
	}
};

int main()
{
	person p1; 
	p1.print();
	return 0; 
}