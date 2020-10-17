#include <bits/stdc++.h>
using namespace std;

int power(long long n, int x)
{
    int ans = 0;
    while(n % x == 0)
    {
        n /= x;
        ans++;
    }
    return ans;
}

int main() 
{
    int t;
    cin >> t;
    long long n;
    while(t--)
    {
        cin >> n;
        int pow2 = 0, pow3 = 0;
        while(n % 2 == 0)
        {
            n /= 2;
            pow2++;
        }
        while(n%3 == 0)
        {
            n /= 3;
            pow3++;
        }
        if (pow3 < pow2 || n != 1) 
        {
            cout << "-1" << endl;
        }
        else 
        {
            if(pow3 == pow2)
            {
                cout << pow3 << endl;
            }
            else cout << 2 * pow3 - pow2 << endl;
        }
    }
    return 0;

}

