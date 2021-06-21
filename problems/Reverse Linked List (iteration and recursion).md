---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 04, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1200
Pomos (25 mins): 1
Source: https://leetcode.com/problems/reverse-linked-list/
Status: done
---

# Reverse Linked List (iteration and recursion)

Iteration
```jsx
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr = head, *prev = nullptr; 
        while (ptr)
        {
            auto nxt = ptr->next; 
            ptr->next = prev; 
            prev = ptr; 
            ptr = nxt;
        }
        return prev;
    }
};
```
Recursion
```jsx
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        ListNode *h1 = reverseList(head->next); 
        head->next->next = head;
        head->next = nullptr; 
        return h1; 
    }
};
```
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)