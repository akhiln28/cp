# Number of subsets with zero sum - GeeksforGeeks

Created Time: Dec 27, 2020 1:26 PM
Do Date: Jan 08, 2021
Last edited time: May 11, 2021 9:10 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Knapsack-e1ea6dfd10d74218b7477511a6be96f8
Points: 1500
Source: https://www.geeksforgeeks.org/number-of-subsets-with-zero-sum/?ref=rp
Status: done
Tags: knapsack

Given an array ‘arr’ consisting of integers, the task is to find the number of subsets such that their sum is equal to zero. Empty subset should also be considered.

**Examples:**

> Input : arr[] = {2, 2, -4} Output : 2 All possible subsets: {} = 0 {2} = 2 {2} = 2 {-4} = -4 {2, 2} = 4 {2, -4} = -2 {2, -4} = -4 {2, 2, -4} = 0 Since, {} and {2, 2, -4} are only possible subsets with sum 0, ans will be 2. Input : arr[] = {1, 1, 1, 1} Output : 1 {} is the only possible subset with sum 0, thus ans equals 1.

One **simple** approach is to generate all possible subsets recursively and count number of subsets with sum equals 0. Time complexity of this approach will be O(2^n).

A better approach will be using **[Dynamic programming](http://www.geeksforgeeks.org/dynamic-programming/)**.
 Let’s suppose sum of all the elements we have selected upto index ‘i-1’ is ‘S’. So, starting from index ‘i’, we have to find number of subsets of the sub-array{i, N-1} with sum equals -S.
Let’s define dp[i][S]. It means number of the subset of the subarray{i, N-1} of ‘arr’ with sum equals ‘-S’.
 If we are at ith index, we have two choices, i.e. to include it in the sum or leave it.
 Thus, the required recurrence relation becomes

> dp[i][s] = dp[i+1][s+arr[i]] + dp[i+1][s]

Below is the implementation of above approach:

**Time Complexity :** O(n*S), where n is the number of elements in the array and S is the sum of all the elements.

---