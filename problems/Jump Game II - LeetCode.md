---
Created Time: Jan 13, 2021 7:00 PM
Do Date: Jan 17, 2021
Last edited time: May 11, 2021 8:59 AM
Points: 2000
Source: https://leetcode.com/problems/jump-game-ii/
Status: done
---

# Jump Game II - LeetCode

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
**Example 1:**
```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
**Example 2:**
```
Input: nums = [2,3,0,1,4]
Output: 2
```
**Constraints:**
- `1 <= nums.length <= 3 * 10^4`
- `0 <= nums[i] <= 10^5`
---
Awesome discussion. 
Greedy and BFS. 
[Concise O(n) one loop JAVA solution based on Greedy - LeetCode Discuss](https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy)
```cpp
public int jump(int[] A) {
	int jumps = 0, curEnd = 0, curFarthest = 0;
	for (int i = 0; i < A.length - 1; i++) {
		curFarthest = Math.max(curFarthest, i + A[i]);
		if (i == curEnd) {
			jumps++;
			curEnd = curFarthest;
		}
	}
	return jumps;
}
```
Patterns: [BFS](BFS.md)