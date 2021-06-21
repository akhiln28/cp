---
Created Time: May 20, 2021 9:57 AM
Last edited time: May 20, 2021 10:00 AM
Points: 1500
Source: https://leetcode.com/problems/sort-list/
Status: done
---

# Sort List - LeetCode

![https://leetcode.com/static/images/LeetCode_Sharing.png](https://leetcode.com/static/images/LeetCode_Sharing.png)
---
Given the `head` of a linked list, return *the list after sorting it in **ascending order***.
**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?
### Constraints
- The number of nodes in the list is in the range `[0, 5 * 104]`.
- `105 <= Node.val <= 105`
### **Examples**
**Example 1:**
![Sort%20List%20-%20LeetCode%20af8cc0f2d5a24a1e814ca1a4dee7f3f1/sort_list_1.jpg](Sort%20List%20-%20LeetCode%20af8cc0f2d5a24a1e814ca1a4dee7f3f1/sort_list_1.jpg)
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```
**Example 2:**
![Sort%20List%20-%20LeetCode%20af8cc0f2d5a24a1e814ca1a4dee7f3f1/sort_list_2.jpg](Sort%20List%20-%20LeetCode%20af8cc0f2d5a24a1e814ca1a4dee7f3f1/sort_list_2.jpg)
```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```
**Example 3:**
```
Input: head = []
Output: []
```
## Algorithm
```python
```
### Explanation
## Solution
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *middle(ListNode *head)
    {
        ListNode *ptr1 = nullptr, *ptr2 = head; 
        while (ptr2 and ptr2->next)
        {
            ptr1 = (ptr1 == nullptr) ? head : ptr1->next; 
            ptr2 = ptr2->next->next;
        }
        ListNode *mid = ptr1->next;
        ptr1->next = nullptr; 
        return mid; 
    }
    ListNode* mergeList(ListNode *l1, ListNode *l2)
    {
        auto dummy = new ListNode(0); 
        auto tail = dummy; 
        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next; 
                tail = tail->next; 
            }
            else
            {
                tail->next = l2; 
                l2 = l2->next; 
                tail = tail->next; 
            }
        }
        if (l1) tail->next = l1; else tail->next = l2;
        return dummy->next; 
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head; 
        auto mid = middle(head); 
        auto left = sortList(head);
        auto right = sortList(mid); 
        return mergeList(left, right); 
    }
};
```
Patterns: [Sorting%20Algorithms](Sorting%20Algorithms.md)[Divide%20and%20Conquer](Divide%20and%20Conquer.md)