# Find the number of inversions in a given array

Created Time: Jan 07, 2021 11:35 PM
Do Date: Jan 07, 2021
Last edited time: May 11, 2021 9:00 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3
Points: 1900
Pomos (25 mins): 1
Relates: Find%20the%20number%20of%20monotonic%20triplets%20bb51474ee1de47b5a6761db5afc6b563.md
Status: ok
Tags: own

Given an array containing integers, find the number of inversions $a_i > a_j, (i < j)$. 

---

I need to think of a solution better than O(n^2). 

For each element we can find the number of elements to the right greater than the current element. Theoretically we can solve this in O(n log n) by maintaining a BST like structure and inserting the elements from the end of the array. At the time of insertion we can find the number of elements in BST greater than the current element. But the implementation is hard.