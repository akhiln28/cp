---
Created Time: Dec 31, 2020 6:11 PM
Do Date: Jan 08, 2021
Last edited time: May 11, 2021 9:00 AM
Points: 1500
Pomos (25 mins): 1
Problem Statement: Given an array of numbers find the number of triplets such that Ai<Aj<Ak or Ai>Aj>Ak for all (i<j<k). | (O(n^2) or O(n log(n)).
Related To: Find%20the%20number%20of%20inversions%20in%20a%20given%20array%206234ecea1659454299cb512a4460bb31.md
Status: ok
---

# Find the number of monotonic triplets

I could think of O(n^2) approach (as shown below) but I cannot think of O(n log n). 
For each element find the number of elements to the right greater than the current element in O(n^2).  And also the number of elements to the left greater than the current element.
Patterns: [Custom%20datastructures](Custom%20datastructures.md)