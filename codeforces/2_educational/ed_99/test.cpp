/*
    title: test.cpp
    author: Akhil
    date: 2020-12-01
    time: 08:51:05
*/

#include <iostream>

using namespace std;

class animal
{
public:
    void print()
    {
        cout << "i am animal" << endl;
    }
    double add(double x, double y) {
        cout << "in double" << endl;
        return x + y; 
    }
    int add(int x, int y)
    {
        cout << "in int" << endl;
        return x + y; 
    }
};

class cat : public animal
{
public:
    void print()
    {
        cout << "i am cat" << endl;
    }
};

int main()
{
    animal *an = new cat();
    an->print();
    an->add(1,2); 
    an->add(1.1, (double) 2); 
    return 0;     
}