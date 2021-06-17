# Furthest Building You Can Reach - LeetCode

Created Time: Jan 15, 2021 5:38 PM
Last edited time: Mar 01, 2021 3:42 PM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1700
Pomos (25 mins): 2
Source: https://leetcode.com/problems/furthest-building-you-can-reach/
Status: ok
Tags: new

You are given an integer array `heights` representing the heights of buildings, some `bricks`, and some `ladders`.

You start your journey from building `0` and move to the next building by possibly using bricks or ladders.

While moving from building `i` to building `i+1` (**0-indexed**),

- If the current building's height is **greater than or equal** to the next building's height, you do **not** need a ladder or bricks.
- If the current building's height is **less than** the next building's height, you can either use **one ladder** or `(h[i+1] - h[i])` **bricks**.

*Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.*

**Example 1:**

![Furthest%20Building%20You%20Can%20Reach%20-%20LeetCode%200b7b5e229ca5495b8f4c6dd0cd0f1a1c/q4.gif](q4.gif)

```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

**Example 2:**

```
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

**Example 3:**

```
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

**Constraints:**

- `1 <= heights.length <= 10^5`
- `1 <= heights[i] <= 10^6`
- `0 <= bricks <= 10^9`
- `0 <= ladders <= heights.length`

---

Found below in the leetcode discuss

```
Heap heap store k height difference that we need to use ladders.
Each move, if the height difference d > 0,
we push d into the priority queue pq.
If the size of queue exceed ladders,
it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return A.length - 1.
```

```cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq; 
        int n = heights.size(); 
        for (int i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i]; 
            if (diff > 0)
            {
                pq.push(diff);
								// need to use bricks as we ran out of ladders
                if (pq.size() > ladders)
                {
                    bricks -= pq.top();
                    pq.pop(); 
                }
            }
            if (bricks < 0) return i;
        }
        return n - 1;
    }
```

- BFS solution I thought Initially

    ```cpp
    class Solution {
    public:
        int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
            queue<vector<int>> q; 
            q.push({0, bricks, ladders}); 
            set<vector<int>> se;
            se.insert({0, bricks, ladders});
            int ans = 0; 
            while (q.size())
            {
                int size = q.size(); 
                for (int i = 0; i < size; i++)
                {
                    auto cur = q.front(); q.pop();
                    if (cur[0] == heights.size() - 1) return cur[0];
                    else ans = max(ans, cur[0]);
                    int diff = max(0, heights[cur[0] + 1] - heights[cur[0]]); 
                    if (cur[1] >= diff) 
                    {
                        vector<int> n1{cur[0] + 1, cur[1] - diff, cur[2]};
                        if (se.find(n1) == se.end())
                            q.push(n1), se.insert(n1);
                    }
                    if (diff and cur[2]) 
                    {
                        vector<int> n2{cur[0] + 1, cur[1], cur[2] - 1};
                        if (se.find(n2) == se.end()) 
                            q.push(n2), se.insert(n2);
                    }
                }
            }
            return ans;
        }
    };
    ```