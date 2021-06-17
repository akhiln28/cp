# Serialize and Deserialize Binary Tree - LeetCode

Created Time: Jan 21, 2021 12:44 PM
Last edited time: May 23, 2021 8:53 AM
Points: 1700
Pomos (25 mins): 1
Source: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Status: waiting
Tags: microsoft

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://leetcode.com/faq/). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Example 1:**

![Serialize%20and%20Deserialize%20Binary%20Tree%20-%20LeetCode%20f908f79a4aa04eb0bcfbf6a05ea7595e/serdeser.jpg](serdeser.jpg)

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

```

**Example 2:**

```
Input: root = []
Output: [
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

```
Input: root = [1,2]
Output: [1,2]
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `1000 <= Node.val <= 1000`

---

We can store the