---
Created Time: Dec 04, 2020 4:12 PM
Do Date: Dec 04, 2020
Last edited time: Dec 20, 2020 8:45 AM
Points: 2000
Pomos (25 mins): 2
Problem Statement: Given a n chocolates with i^th chocolate having s_i sweetness and t_i expiry time. You are given Q queries like (x, y), for each query return the number of chocolates whose sweetness greater than x and expiry time greater than y.
Status: ok
Tags: optimization, sharechat
---

# Quality of chocolates

Given a n chocolates with i^th chocolate having s_i sweetness and t_i expiry time. You are given Q (≤ 10^5)  queries like (x, y), for each query return the number of chocolates whose sweetness greater than x and expiry time greater than y. (#chocolates ≤ 10^5) 
---
I found today that this problem can be solved in O(n log n) using k-d tree [K Dimensional Tree | Set 1 (Search and Insert) - GeeksforGeeks](https://www.notion.so/K-Dimensional-Tree-Set-1-Search-and-Insert-GeeksforGeeks-c608913badbe46b8b145ee8e978a4fb5)
Patterns: 