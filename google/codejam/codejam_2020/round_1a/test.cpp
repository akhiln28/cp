#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    long double f = 0; 
    int n; cin >> n; 
    for (int i = 1; i <= n; i++)
    {
        f += 1.0/i;
    }
    cout << f << " " << log(n) << endl;
    
    return 0; 
}