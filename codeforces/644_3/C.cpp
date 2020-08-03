#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <string>
#include <map>

#define max_n 100
using namespace std;


int arr[max_n];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        int odds = 0, evens = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            if (arr[i] & 1) odds++;
            else evens++;
        }
        if (odds & 1) 
        {
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] & 1)
                {
                    if (mp[arr[i] - 1] || mp[arr[i] + 1])
                        flag = true;
                }
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}
