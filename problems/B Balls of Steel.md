---
Created Time: Dec 05, 2020 8:17 PM
Do Date: Dec 12, 2020
Last edited time: Mar 01, 2021 3:43 PM
Points: 1000
Problem Statement: Given the coordinates of n distinct balls. In one operation you can charge the ball so that all the balls within the manhattan distance k will merge into the charged ball. Find the minimum number of operations you need to merge all the balls otherwise return -1. 
Source: https://codeforces.com/contest/1450/problem/B
Status: done
Tags: logic, simulation
---

# B. Balls of Steel

We claim the answer is always −1 or 1.
In fact, suppose in the first operation of a solution we select a point pp. If we aren't done, there will at least one point with distance more than k from pp. However, there will be no point within distance k of p, no matter how we perform future operations. So it is impossible for pp to merge with a new point, and a solution with more than 1 operation will be impossible.
To see if the answer is 1, ***we should check if there is some point p within distance k from all other points***. Otherwise, the answer is −1. Complexity is O(n^2) to compute pairwise distances.
Patterns: [patterns/Greedy](patterns/Greedy.md)