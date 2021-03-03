#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

struct cls {
    char ch;
    double d;
};

int main()
{
    cout << sizeof(cls) << endl;
    cls obj; 
    cout << &obj << endl;
    cout << &(obj.ch) << endl;
    cout << &(obj.d) << endl;
    return 0;
}