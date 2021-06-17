# Job Assignment Problem [Find minimum time to finish all jobs]

Created Time: Jan 09, 2021 9:31 AM
Do Date: Jan 09, 2021
Last edited time: May 11, 2021 9:05 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Backtracking-90d58a7ffa85438e86ce346981bf35b5
Points: 2000
Pomos (25 mins): 2
Source: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
Status: done
Tags: np hard

You are given an integer array `jobs`, where `jobs[i]` is the amount of time it takes to complete the `ith` job.

There are `k` workers that you can assign jobs to. Each job should be assigned to **exactly** one worker. The **working time** of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the **maximum working time** of any worker is **minimized**.

*Return the **minimum** possible **maximum working time** of any assignment.*

**Example 1:**

```
Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
```

**Example 2:**

```
Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
```

**Constraints:**

- `1 <= k <= jobs.length <= 12`
- `1 <= jobs[i] <= 10^7`

---

I found below solution helpful.  Multi knapsack problem...

[C++ Prune Equal Working Time - LeetCode Discuss](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/discuss/1009768/C%2B%2B-Prune-Equal-Working-Time)

```jsx
int worker[12] = {}, res = 0;
int dfs(vector<int>& jobs, int i, int k, int cur) {
    if (cur >= res)
        return res;
    if (i == jobs.size())
        return res = cur;
    unordered_set<int> workTime;
    for (auto j = 0; j < k; ++j) {
        if (!workTime.insert(worker[j]).second)
            continue;
        worker[j] += jobs[i];
        dfs(jobs, i + 1, k, max(cur, worker[j]));
        worker[j] -= jobs[i];
    }
    return res;
}
int minimumTimeRequired(vector<int>& jobs, int k) {
    if (k == jobs.size())
        return *max_element(begin(jobs), end(jobs));
    sort(begin(jobs), end(jobs), greater<int>());
    for (int i = 0; i < jobs.size(); i += k)
        res += jobs[i];
    return dfs(jobs, 0, k, 0);
}
```