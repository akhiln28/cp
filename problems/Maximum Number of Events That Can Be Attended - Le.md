---
Created Time: Feb 08, 2021 8:17 AM
Do Date: Feb 08, 2021
Last edited time: Mar 04, 2021 8:11 AM
Points: 1600
Pomos (25 mins): 1
Source: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
Status: ok
---

# Maximum Number of Events That Can Be Attended - LeetCode

Given an array of `events` where `events[i] = [startDayi, endDayi]`. Every event `i` starts at `startDayi` and ends at `endDayi`.
You can attend an event `i` at any day `d` where `startTimei <= d <= endTimei`. Notice that you can only attend one event at any time `d`.
Return *the maximum number of events* you can attend.
**Example 1:**
![Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20-%20Le%20ba60274a205b4a1e9d85a691d1f19c90/e1.png](Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20-%20Le%20ba60274a205b4a1e9d85a691d1f19c90/e1.png)
```
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
```
**Example 2:**
```
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
```
**Example 3:**
```
Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4
```
**Example 4:**
```
Input: events = [[1,100000]]
Output: 1
```
**Example 5:**
```
Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7
```
**Constraints:**
- `1 <= events.length <= 10^5`
- `events[i].length == 2`
- `1 <= startDayi <= endDayi <= 10^5`
---
Sort the events based on their ending times. 
We can map each day with an event. 
Maintain a pointer p to the list of events. 
Now for each day if day is in the event then p++, day++, count++;
```jsx
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int day = 1, ptr = 0, count = 0; 
        priority_queue<int, vector<int>, greater<int>> pq;
        
        while (pq.size() or ptr < events.size())
        {
            while (ptr < events.size() and day <= events[ptr][1] and day >= events[ptr][0])
            {
                pq.push(events[ptr][1]); 
                ptr++;
            }
            while (pq.size() and pq.top() < day)
            {
                pq.pop();
            }
            if (pq.size())
            {
                pq.pop();
                count++;
            }
            day++;
        }
        return count;
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Intervals](Intervals.md)