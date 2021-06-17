# Find Median from Data Stream - LeetCode

Created Time: Jan 14, 2021 11:47 PM
Do Date: Jan 14, 2021
Last edited time: Feb 22, 2021 9:22 PM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242
Points: 1800
Source: https://leetcode.com/problems/find-median-from-data-stream/
Status: ok

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,

`[2,3,4]`, the median is `3`

`[2,3]`, the median is `(2 + 3) / 2 = 2.5`

Design a data structure that supports the following two operations:

- void addNum(int num) - Add a integer number from the data stream to the data structure.
- double findMedian() - Return the median of all elements so far.

**Example:**

```
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2

```

**Follow up:**

1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?
2. If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

---

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double> left; // max heap
    priority_queue<double, vector<double>, greater<int>> right; // min heap
    MedianFinder() {
    }
    
    void addNum(int num) {
        int left_max = (left.size())?left.top():-1;
        
        if (num <= left_max) left.push(num); 
        else right.push(num);
        
        if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
        else if (right.size() < left.size() - 1)
        {
            right.push(left.top());
            left.pop(); 
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) return (left.top() + right.top())/2;
        else return left.top();
    }
};
```