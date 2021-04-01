#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: m_1802_maximum_value_at_a_given_index_in_a_bounded_array.cpp
    author: Akhil
    date: 2021-03-31
    time: 08:45:07
    ==================================================
    array of postive integers of length n, the consecutive elements differ by atmost 1.
    the sum of all elements does not exceed maxSum.
    now maximise arr[idx].
    n = 4, idx = 2, maxSum = 6
    - - (-) -
    - - (3) - => 1 2 (3) 2 >= 6
    - - (2) - => 1 1 (2) 1 < 6 ✅

    n = 4, idx = 0, maxSum = 4


    We can do binary search for this problem I guess.
    is_possible(leftcount, rightcount, ans, maxSum):
        if (leftcount > ans)
    int left = 0, right = 1e9

*/

class Solution {
public:
    bool is_possible(long long lcount, long long rcount, long long val, long long maxSum)
    {
        long long leftsum = 0, rightsum = 0;
        if (lcount > val - 1) leftsum += (val * (val - 1) / 2) + lcount - val + 1;
        else leftsum += (2 * val - 1 - lcount) * lcount / 2;
        if (rcount > val - 1) rightsum += (val * (val - 1) / 2) + rcount - val + 1;
        else rightsum += (2 * val - 1 - rcount) * rcount / 2;
        return (leftsum + rightsum + val) <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int left = 0, right = 1e9;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            cout << "mid: " << mid << " " << left << " " << right << endl;
            if (is_possible(index, n - index - 1, mid, maxSum)) ans = max(ans, mid), left = mid + 1;
            else right = mid - 1;
        }
        return ans;
    }
};

int main()
{
    int n = 4, idx = 0, maxSum = 4;
    Solution obj;
    auto ret = obj.maxValue(n, idx, maxSum);
    cout << ret << endl;
    return 0;
}