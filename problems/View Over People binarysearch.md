---
Created Time: Mar 19, 2021 8:44 AM
Do Date: Mar 19, 2021
Last edited time: Mar 19, 2021 9:04 AM
Points: 1600
Pomos (25 mins): 1
Source: https://binarysearch.com/problems/View-Over-People
Status: done
---

# View Over People | binarysearch

You are given a list of integers `heights` and an integer `k`. Each element `heights[i]` represents the height of the `i`th person. The `i`th person can see the movie if all `k` people directly to the right of them are shorter. If there’s fewer than `k` people to the right then they can see the movie if all remaining people to the right are shorter.
Return the people that can see the movie, sorted in ascending order.
**Constraints**
- `0 ≤ k ≤ n ≤ 100,000` where `n` is the length of `heights`
### **Output**
### **Explanation**
`heights[0]`, `heights[1]` and `heights[5]` can see the movie.
### **Output**
### **Explanation**
Only the last person can see the movie. Everyone else is blocked by the person in front of them.
Patterns: [Stack](Stack.md)