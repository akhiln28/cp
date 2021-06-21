---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 25, 2021
Last edited time: May 11, 2021 8:58 AM
Points: 1500
Pomos (25 mins): 1
Source: leetcode.com
Status: done
Tags: copy structure
---

# Copy List with Random Pointer

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.
Construct a **[deep copy](https://en.wikipedia.org/wiki/Object_copying#Deep_copy)** of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.
For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.
Return *the head of the copied linked list*.
The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:
- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.
Your code will **only** be given the `head` of the original linked list.
**Example 1:**
![https://assets.leetcode.com/uploads/2019/12/18/e1.png](https://assets.leetcode.com/uploads/2019/12/18/e1.png)
```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```
**Example 2:**
![https://assets.leetcode.com/uploads/2019/12/18/e2.png](https://assets.leetcode.com/uploads/2019/12/18/e2.png)
```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```
**Example 3:**
![https://assets.leetcode.com/uploads/2019/12/18/e3.png](https://assets.leetcode.com/uploads/2019/12/18/e3.png)
```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```
**Example 4:**
```
Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.
```
**Constraints:**
- `0 <= n <= 1000`
- `10000 <= Node.val <= 10000`
- `Node.random` is `null` or is pointing to some node in the linked list.
---
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node *ptr = head;
        Node *head2 = new Node(INT_MIN); 
        Node *ptr2 = head2;
        while (ptr)
        {
            Node *n = new Node(ptr->val);
            ptr2->next = n, ptr2 = n;
            mp[ptr] = n;
            ptr = ptr->next;
        }
        
        ptr = head;
        while (ptr)
        {
            mp[ptr]->random = mp[ptr->random];
            ptr = ptr->next;
        }
        return head2->next;
    }
};
```
Patterns: [Matrix](Matrix.md)[Hashing](Hashing.md)