#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    string n; cin >> n;
    long long ans = 0;
    for (int i = 0; i < n.length(); i++)
    {
        ans += n[i] - '0'; 
    }
    cout << ((ans % 9 == 0) ? "Yes" : "No") << endl;
    return 0;
}