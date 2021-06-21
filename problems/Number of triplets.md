---
Created Time: Dec 18, 2020 8:29 AM
Last edited time: Feb 22, 2021 9:23 PM
Points: 1500
Problem Statement: Given an array of numbers find the number of triplets such that Ai < Aj < Ak or Ai > Aj > Ak for all (i < j < k). 
Related To: Insert%20Stream%20of%20Numbers%20Return%20number%20of%20numbers%20%201f941522ea964a8dad1b9c38ad3ecaa8.md
Source: https://www.geeksforgeeks.org/de-shaw-internship-interview-experience-on-campus-2021/
Status: ok
Tags: de shaw, unverified
---

# Number of triplets

Given an array of numbers find the number of triplets such that Ai < Aj < Ak or Ai > Aj > Ak for all (i < j < k). 
---
For each i, find the number of integers Aj such that Aj > Ai and j > i in O(n^2), say Bi
Also for each i, find the number of integers Aj such that Aj < Ai and j > i in O(n^2), say Ci
For each i, j
if Ai < Aj, then ans += Bj
if Ai > Aj, then ans += Cj
return ans; 
I think it should be solved in O(nlogn).
Patterns: [Array](Array.md)