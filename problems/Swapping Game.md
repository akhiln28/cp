---
Created Time: Dec 20, 2020 8:51 AM
Last edited time: Mar 01, 2021 8:48 AM
Points: 1800
Pomos (25 mins): 1
Source: https://www.geeksforgeeks.org/de-shaw-interview-experience-2/
Status: ok
Tags: de shaw, unverified
---

# Swapping Game

You are given two arrays arr1 and arr2. Both the arrays are of Same Size(n).
Now as a Player You have to maximize the Value of Sum(arr1,arr2) for given two Arrays arr1 and arr2 each having N elements.
Interesting part of the Game is that to maximize the Sum(arr1,arr2) for doing So You are allowed to Swap arr1[i] & arr2[i] any number of times for Any Position i. (0<= i < n).
given function sum
```cpp
long long Sum(int arr1[], int arr2[],int n)
{
    int value_of_sum = 0;
    for(int i=0;i<n;i++)
    {
        value_of_sum = value_of_sum + abs(arr1[i]-arr2[i]); //Java & Python Coders remember abs() means absolute positive value.
        if(i < n-1)
        {
            value_of_sum = value_of_sum + abs(arr1[i+1] - arr2[i]);
        }
    }
    return value_of_sum;
}
```
Explanation :
input
n = 4
arr1[] = {2,3,4,1}
arr2[] = {2,4,1,1}
Ouput
11
Here we will swap arr1[2] and arr2[2]. (Swap)
arr1[] = {2,3,1,1}
arr2[] = {2,4,4,1}
for this type of arrangement we have our maximum Define Sum.
Sum = abs(arr1[0]-arr2[0]) + abs(arr1[1]-arr2[0]) + abs(arr1[1]-arr2[1]) + abs(arr1[2]-arr2[1]) ....
Sum = abs(2-2) + abs(3-2) + abs(3-4) + abs(1-4) + abs(1-4) + abs(1-4) + abs(1-1) = 11
---
$dp[i][0] = max(dp[i - 1][0] + |a_1[i] - a_2[i]| + |a_1[i] - a_2[i - 1]|, dp[i - 1][1] + |a_1[i] - a_2[i]| + |a_1[i] - a_1[i - 1]|)$
Patterns: [Array](Array.md)[Dp](Dp.md)