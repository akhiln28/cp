# Minimum operations to make frequency of all characters equal K - GeeksforGeeks

Created Time: Jan 27, 2021 9:26 AM
Do Date: Jan 27, 2021
Last edited time: May 11, 2021 8:58 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98
Points: 1500
Source: https://www.geeksforgeeks.org/minimum-operations-to-make-frequency-of-all-characters-equal-k/
Status: ok
Tags: unverified

Given a string S of length N. The task is to find the minimum number of steps required on strings, so that it has exactly **K** different alphabets all with the same frequency.

**Note**: In one step, we can change a letter to any other letter.

**Examples:**

```
Input: S = "abbc", N = 4, K = 2
Output: 1 
In one step convert 'c' to 'a'. Hence string has 
two different letters a and b both 
occurring 2 times. 
```

---

**Initial approach:**

1. N%k should be 0. Number of characters required = N/k. 
2. Calculate the frequencies of all the alphabets. Total number of alphabets in the final answer is max(N/k, #present in given string). 
3. Now for each alphabet add the abs(k - freq[i]) to answer. 
4. return ans / 2