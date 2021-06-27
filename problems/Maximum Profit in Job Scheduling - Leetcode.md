---
Created Time: Dec 17, 2020 6:50 PM
Do Date: Dec 19, 2020
Last edited time: Mar 31, 2021 9:00 AM
Points: 2000
Pomos (25 mins): 1
Source: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
Status: done
Tags: swiggy
---

# Maximum Profit in Job Scheduling - Leetcode

We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.
You're given the `startTime` , `endTime` and `profit` arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.
If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.
**Example 1:**
```
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
```
**Example 2:**
```
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
```
**Example 3:**
```
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
```
**Constraints:**
- `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
- `1 <= startTime[i] < endTime[i] <= 10^9`
- `1 <= profit[i] <= 10^4`
---
Sort based on the endtimes and use dp. 
```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(); 
        vector<int> jobs(n); 
        for (int i = 0; i < n; i++) jobs[i] = i; 
        // sorting based on the endtimes
        sort(jobs.begin(), jobs.end(), [&](int i, int j){
            if (endTime[i] != endTime[j]) return endTime[i] < endTime[j]; 
            else return startTime[i] < startTime[j]; 
        });
        vector<int> dp(n); 
        dp[0] = profit[jobs[0]]; 
        for (int i = 1; i < n; i++)
        {
            int ans = -1; 
            int left = 0, right = i - 1; 
            while (left <= right)
            {
                int mid = left + (right - left)/2; 
                if (endTime[jobs[mid]] <= startTime[jobs[i]]) ans = max(ans, mid), left = mid + 1; 
                else right = mid - 1; 
            }
            if (ans != -1) dp[i] = max(profit[jobs[i]] + dp[ans], dp[i - 1]); 
            else dp[i] = max(profit[jobs[i]], dp[i - 1]); 
        }
        return dp[n - 1]; 
    }
};
```
Patterns: [Dp](Dp.md)[Binary%20Search](Binary%20Search.md)
Related: [Delivering Boxes from Storage to Ports](Delivering%20Boxes%20from%20Storage%20to%20Ports.md)