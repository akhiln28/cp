---
Created Time: Dec 24, 2020 4:58 PM
Last edited time: Dec 25, 2020 7:06 PM
Points: 1500
Source: https://practice.geeksforgeeks.org/problems/stock-span-problem/0
Status: done
Tags: de shaw
---

# Stock span problem | Practice | GeeksforGeeks

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all **n** days. 
The span **Si** of the stock’s price on a given day **i** is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
**Input:**
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].
**Output:**
 For each testcase, print the span values for all days.
**Constraints:**
 1 ≤ T ≤ 100
 1 ≤ N ≤ 200
 1 ≤ C[i] ≤ 800
**Example:Input:**
 2
 7
 100 80 60 70 60 75 85
 6
 10 4 5 90 120 80
**Output:**
 1 1 1 2 1 4 6
 1 1 2 4 5 1
![Stock%20span%20problem%20Practice%20GeeksforGeeks%209a49be69a1a74be1ab0b60dcd999dcde/Stock_span.png](Stock%20span%20problem%20Practice%20GeeksforGeeks%209a49be69a1a74be1ab0b60dcd999dcde/Stock_span.png)
---
This is a famous stack problem. I am an idiot to not figure out this sooner. 
I am thinking of the following method, using the stock span of the previously computed prices. 
```cpp
dp[i] - stock span of ith element
for i in range(n)
	int j = i - 1; 
	while (price[j] < price[i]) j -= dp[j] - 1
	dp[i] = i - j + 1
```
I wonder what the complexity of the above code 🤔
Patterns: 