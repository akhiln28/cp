#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <utility>

#define max_n 1000001

using namespace std;

int arr[max_n];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // cout << s << endl;
        // cout << "lalal" << endl;
        for (int i = 0; i < s.size(); i++)
        {
            arr[i] = (s[i] == '+') ? 1 : -1;
        }
        // cout << "lalal" << endl;
        for (int i = 1; i < s.size(); i++)
        {
            arr[i] += arr[i - 1];
        }
        // cout << "lalal" << endl;

        int curr = 0, value = 0;
        long long ans = 0;
        // cout << "lalal" << endl;
        while (curr != s.size())
        {
            while (curr < s.size() && arr[curr] + value >= 0)
                curr++;
            ans += (long long)curr + 1;
            value++;
        }
        cout << ans - 1<< endl;
    }
    return 0;
}