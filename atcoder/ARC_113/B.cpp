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

int powermod10(int b, int power)
{
    if (b == 0) return 0; 
    if (power == 0) return 1;
    int temp = powermod10(b, power/2); 
    if (power % 2 == 0)
    {
        return (temp * temp) % 10; 
    }
    else
    {
        return (temp * temp * b) % 10; 
    }
}

int main()
{
    int a, b, c; 
    cin >> a >> b >> c;
    a %= 10;
    b %= 10; 
    c %= 10; 
    int power = pow(b, c);
    cout << "power: " << power << endl;
    cout << powermod10(a, power) << endl;
    /*
        a = 2 -> (2, 4, 8, 6) based on reminder of power (1, 2, 3, 0) (power > 0)
        a = 3 -> (3, 9, 7, 1) based on reminder
        a = 4 -> (4, 6) based on reminder
    */
    return 0;
}