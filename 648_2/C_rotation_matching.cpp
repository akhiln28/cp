#include <iostream>
#include <map>
#include <climits>
#include <algorithm>

#define max_n 200001
using namespace std;

int arr1[max_n];
int arr2[max_n];

int main() {
    int n;
    cin >> n;
    map<int, int> loc1, loc2, shift_count;
    for (int i = 0; i < n;i++)
    {
        cin >> arr1[i];
        loc1[arr1[i]] = i;
    }
    for (int i = 0; i < n;i++)
    {
        cin >> arr2[i];
        loc2[arr2[i]] = i;
    }
    for (int i = 0; i < n;i++)
    {
        int shift = loc2[arr1[i]] - i;
        if (shift < 0) shift += n;
        shift_count[shift]++;
    }
    int max_ans = INT_MIN;
    for (auto i : shift_count)
    {
        max_ans = max(max_ans, i.second);
    }
    cout << max_ans << endl;
    return 0;
}