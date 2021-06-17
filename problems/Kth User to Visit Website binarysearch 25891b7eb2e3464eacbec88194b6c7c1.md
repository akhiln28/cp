# Kth User to Visit Website | binarysearch

Created Time: Jan 16, 2021 1:36 PM
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Source: https://binarysearch.com/problems/Kth-User-to-Visit-Website
Status: waiting

You are given a two-dimensional list of integers `requests` and an integer `k`. Each element `requests[i]` contains `[start, end]` representing an inclusive interval for the possible times when user `i` visited the website. Each user visits the site exactly once.

Return the users who may have been the `k`th (0-indexed) user to visit the site, sorted in ascending order. You can assume that the site can serve an unlimited number of users at any time.

**Constraints**

- `1 ≤ n ≤ 100,000` where `n` is the length of `requests`
- `0 ≤ k < n`

### **Output**

### **Explanation**

If users visited the site at timestamps `[3, 3, 4]`, then user `0` and `1` may have been the `k`th user. If they visited the site at `[4, 3, 4]`, then user `0` and `2` may have been the `k`th user.

### **Output**

### **Explanation**

The only possible timestamps are `[0, 0, 1, 2, 2]`. Only the last two users could've been the `3`rd user to visit the site.

### **Output**

### **Explanation**

If users visited the site at these timestamps `[60, 5, 21, 22]`, then user `2` would've been the `k`th user. If they visited the site at `[60, 5, 23, 22]`, then `3` would've been the `k`th user.