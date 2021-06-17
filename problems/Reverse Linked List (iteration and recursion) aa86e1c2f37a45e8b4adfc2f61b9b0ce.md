# Reverse Linked List (iteration and recursion)

Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 04, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1200
Pomos (25 mins): 1
Source: https://leetcode.com/problems/reverse-linked-list/
Status: done

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