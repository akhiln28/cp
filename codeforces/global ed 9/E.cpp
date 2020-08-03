#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#include <algorithm>

#define max_n 1001
#define SWAP(x, y) (x ^= y ^= x)

int arr[max_n];
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int max_idx = max_element(arr, arr + i) - arr;
        if (arr[i] < arr[max_idx])
        {
            SWAP(arr[max_idx], arr[i]);
            ans.push_back(make_pair(max_idx + 1, i + 1));
        }
    }
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}