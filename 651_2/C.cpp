#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include <utility>

#define max_n 100001

int arr[max_n];
using namespace std;

long long pureeven(long long n)
{
    while (n % 2 == 0)
        n /= 2;
    return n;
}

int main()
{
    int t;
    long long n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n & 1)
        {
            if (n == 1)
                cout << "FastestFinger" << endl;
            else
                cout << "Ashishgup" << endl;
        }
        else if (!(n & 1))
        {
            
            if (pureeven(n) == 1)
            {
                if (n == 2)
                    cout << "Ashishgup" << endl;
                else
                    cout << "FastestFinger" << endl;
            }
            else
            {
                if (n / pureeven(n) <= 2)
                {
                    cout << "FastestFinger" << endl;
                }
                else
                    cout << "Ashishgup" << endl;
            }
        }
    }
    return 0;
}
