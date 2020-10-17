#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int carry(vector<int> &digits)
{
    int car = 1, idx = 0; 
    while (!digits[idx]) idx++;
    digits[idx] = 0;
    for (int i = idx + 1; i < digits.size(); i++)
    {
        int nd = (digits[i] + car) % 10; 
        car = (digits[i] + car)/10;
        digits[i] = nd;
    }
    if (car) digits.push_back(car);
    return accumulate(digits.begin(), digits.end(), 0);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        long long n; int s; cin >> n >> s;
        vector<int> digits;
        long long n1 = n;
        while (n1)
        {
            digits.push_back(n1 % 10), n1 /= 10;
        }
        int s1 = accumulate(digits.begin(), digits.end(), 0);
        while (s1 > s)
        {
            s1 = carry(digits);
        }
        long long n2 = 0, f = 1; 
        for (int i = 0; i < digits.size(); i++)
        {
            n2 += f * digits[i], f *= 10;
        }
        cout << n2 - n << endl;
    }
    return 0;
}