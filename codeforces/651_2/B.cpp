#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include <utility>

#define max_n 100001

int arr[max_n];
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n *= 2;
        int x;
        vector<int> evens, odds;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x & 1)
            {
                odds.push_back(i + 1);
            }
            else
                evens.push_back(i + 1);
        }
        if (!(evens.size() & 1))
        {
            for (int i = 2; i < evens.size(); i += 2)
            {
                cout << evens[i] << " " << evens[i + 1] << endl;
            }
            for (int i = 0; i < odds.size(); i += 2)
            {
                cout << odds[i] << " " << odds[i + 1] << endl;
            }
        }
        else
        {
            // cout << "la1" << endl;
            for (int i = 1; i < evens.size(); i += 2)
            {
                // cout << "la2 " << endl;
                cout << evens[i] << " " << evens[i + 1] << endl;
            }
            for (int i = 1; i < odds.size(); i += 2)
            {
                // cout << "la3 " << endl;
                cout << odds[i] << " " << odds[i + 1] << endl;
            }
        }
    }
    return 0;
}
