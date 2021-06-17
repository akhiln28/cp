# Finding Pairs With a Certain Sum - LeetCode

Created Time: May 16, 2021 9:31 AM
Day Completed: https://www.notion.so/17-May-21-Monday-e59b42d68145406195040c6d206d286b
Last edited time: May 16, 2021 9:32 AM
Pattern: https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
Status: done

# Problem Statement

You are given two integer arrays `nums1` and `nums2`. You are tasked to implement a data structure that supports queries of two types:

1. **Add** a positive integer to an element of a given index in the array `nums2`.
2. **Count** the number of pairs `(i, j)` such that `nums1[i] + nums2[j]` equals a given value (`0 <= i < nums1.length` and `0 <= j < nums2.length`).

Implement the `FindSumPairs` class:

- `FindSumPairs(int[] nums1, int[] nums2)` Initializes the `FindSumPairs` object with two integer arrays `nums1` and `nums2`.
- `void add(int index, int val)` Adds `val` to `nums2[index]`, i.e., apply `nums2[index] += val`.
- `int count(int tot)` Returns the number of pairs `(i, j)` such that `nums1[i] + nums2[j] == tot`.

### Constraints

- `1 <= nums1.length <= 1000`
- `1 <= nums2.length <= 105`
- `1 <= nums1[i] <= 109`
- `1 <= nums2[i] <= 105`
- `0 <= index < nums2.length`
- `1 <= val <= 105`
- `1 <= tot <= 109`
- At most `1000` calls are made to `add` and `count` **each**.

### **Examples**

```
Input
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
Output
[null, 8, null, 2, 1, null, null, 11]

Explanation
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4

```

## Algorithm

```python

```

### Explanation

## Solution

```cpp
class FindSumPairs {
public:
    unordered_map<int, set<int>> mp; 
    vector<int> nums1, nums2; 
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // nums1[i], nums2[j]
        this->nums1 = nums1; 
        this->nums2 = nums2; 
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]].insert(i); 
        }
    }
    
    void add(int index, int val) {
        if (val == 0) return; 
        // remove cur index in mp
        int cur = nums2[index]; 
        mp[cur].erase(index);
        mp[cur + val].insert(index); 
        nums2[index] = cur + val; 
        if (mp[cur].size() == 0)
        {
            mp.erase(cur);
        }
    }
    
    int count(int tot) {
        int ans = 0; 
        for (int i = 0; i < nums1.size(); i++)
        {
            int target = tot - nums1[i]; 
            if (mp.find(target) != mp.end())
            {
                ans += mp[target].size();
            }
        }
        return ans; 
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
```