#include <iostream>
#define max_n 1000001
using namespace std;

int arr[max_n];

int rem10powx(int x, int k)
{
    
}

int solve_reminder(int xth, int k)
{
    int cur = 1 % k;
    long long rem = (long long)cur;
    for (int i = 1; i < xth; i++)
    {
        int cur = (10 * cur) % k;
        rem += cur;
    }
    return (int)((7 * rem) % k);
}

int main()
{
    int k;
    cin >> k;
    for (int x = 1; x < 100000; x++)
    {
        if (solve_reminder(x, k) == 0)
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}