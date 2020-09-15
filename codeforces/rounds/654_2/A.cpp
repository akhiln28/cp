#include <iostream>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (int)ceil((float)n / 2) << endl;
    }
    return 0;
}