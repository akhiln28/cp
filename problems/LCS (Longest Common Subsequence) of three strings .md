---
Created Time: Dec 18, 2020 9:08 AM
Do Date: Dec 18, 2020
Last edited time: Mar 01, 2021 8:46 AM
Points: 1500
Related To: Longest%20Common%20Subsequence%20-%20LeetCode%20cc8345d83aa849a2aecabcf273efd124.md
Source: https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/
Status: done
Tags: de shaw
---

# LCS (Longest Common Subsequence) of three strings - GeeksforGeeks

Given 3 strings of all having length < 100,the task is to find the longest common sub-sequence in all three given sequences.
**Examples:**
```
Input : str1 = "geeks"  
        str2 = "geeksfor"  
        str3 = "geeksforgeeks"
Output : 5
Longest common subsequence is "geeks"
i.e., length = 5
Input : str1 = "abcd1e2"  
        str2 = "bc12ea"  
        str3 = "bd1ea"
Output : 3
Longest common subsequence is "b1e" 
i.e. length = 3.
```
---
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t; cin >> t;
	while (t--)
	{
	    string s1, s2, s3; 
	    // int temp; cin >> temp >> temp >> temp; 
	    cin >> s1 >> s2 >> s3; 
	    int x = s1.length(), y = s2.length(), z = s3.length();  
	    int dp[x + 1][y + 1][z + 1]; 
	    memset(dp, 0, sizeof(dp)); 
	    for (int i = 1; i <= x; i++)
	    {
	        for (int j = 1; j <= y; j++)
	        {
	            for (int k = 1; k <= z; k++)
	            {
	                if (s1[i - 1] == s2[j - 1] and s2[j - 1] == s3[k - 1]) dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1]; 
	                else dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
	            }
	        }
	    }
	    cout << dp[x][y][z] << endl;
	}
	return 0;
}
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[Dp](Dp.md)