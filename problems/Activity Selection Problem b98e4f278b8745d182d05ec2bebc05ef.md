# Activity Selection Problem

Created Time: Dec 18, 2020 10:56 PM
Do Date: Dec 18, 2020
Last edited time: Mar 04, 2021 8:12 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Intervals-ebd124f2083d4f999c01b25e664d9e01
Points: 1500
Pomos (25 mins): 1
Relates: Minimum%20Number%20of%20Arrows%20to%20Burst%20Balloons%2091093d276b474230a2c9984ed9939327.md, Video%20Stitching%20-%20Leetcode%205cb996b015aa4962a4c544fcef454657.md, Remove%20Interval%20Overlaps%20binarysearch%2041f76b1430c94254b13badf18ea8da0b.md, Partition%20Labels%20-%20Leetcode%203c0b164a082e4c2a92af739735bf3531.md
Source: https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
Status: ok
Tags: de shaw, standard

Let us consider the [Activity Selection problem](http://en.wikipedia.org/wiki/Activity_selection_problem) as our first example of Greedy algorithms. Following is the problem statement.*You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.*
 Example:

```
Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]

```

---

Sort the activities by finish times. And greedily choose the one with least finish time (if possible).