# Convert BST to Max Heap - GeeksforGeeks

Created Time: Dec 24, 2020 5:52 PM
Last edited time: Dec 24, 2020 6:49 PM
Points: 1200
Source: https://www.geeksforgeeks.org/convert-bst-to-max-heap/
Status: ok
Tags: de shaw, new

Given a [Binary Search Tree](https://www.geeksforgeeks.org/binary-search-tree-data-structure/) which is also a Complete Binary Tree. The problem is to convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Examples:

```
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  
 
Output :       7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap.
All the nodes in the Max Heap satisfies the given
condition, that is, values in the left subtree of
a node should be less than the values in the right
subtree of the node. 

```

**Pre Requisites**: [Binary Seach Tree](https://www.geeksforgeeks.org/binary-search-tree-data-structure/) | [Heaps](https://www.geeksforgeeks.org/heap-data-structure/)

**Approach**
 1. Create an array **arr[]** of size n, where n is the number of nodes in the given BST.
 2. Perform the inorder traversal of the BST and copy the node values in the **arr[]** in sorted
 order.
 3. Now perform the postorder traversal of the tree.
 4. While traversing the root during the postorder traversal, one by one copy the values from the array **arr[]** to the nodes.

```cpp
// C++ implementation to convert a given 
// BST to Max Heap 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	Node *left, *right; 
}; 

/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. */
struct Node* getNode(int data) 
{ 
	struct Node* newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode; 
} 

// Function prototype for postorder traversal 
// of the given tree 
void postorderTraversal(Node*); 

// Function for the inorder traversal of the tree 
// so as to store the node values in 'arr' in 
// sorted order 
void inorderTraversal(Node* root, vector<int>& arr) 
{ 
	if (root == NULL) 
		return; 

	// first recur on left subtree 
	inorderTraversal(root->left, arr); 

	// then copy the data of the node 
	arr.push_back(root->data); 

	// now recur for right subtree 
	inorderTraversal(root->right, arr); 
} 

void BSTToMaxHeap(Node* root, vector<int> arr, int* i) 
{ 
	if (root == NULL) 
		return; 

	// recur on left subtree 
	BSTToMaxHeap(root->left, arr, i); 

	// recur on right subtree 
	BSTToMaxHeap(root->right, arr, i); 

	// copy data at index 'i' of 'arr' to 
	// the node 
	root->data = arr[++*i]; 
} 

// Utility function to convert the given BST to 
// MAX HEAP 
void convertToMaxHeapUtil(Node* root) 
{ 
	// vector to store the data of all the 
	// nodes of the BST 
	vector<int> arr; 
	int i = -1; 

	// inorder traversal to populate 'arr' 
	inorderTraversal(root, arr); 

	// BST to MAX HEAP conversion 
	BSTToMaxHeap(root, arr, &i); 
} 

// Function to Print Postorder Traversal of the tree 
void postorderTraversal(Node* root) 
{ 
	if (!root) 
		return; 

	// recur on left subtree 
	postorderTraversal(root->left); 

	// then recur on right subtree 
	postorderTraversal(root->right); 

	// print the root's data 
	cout << root->data << " "; 
} 

// Driver Code 
int main() 
{ 
	// BST formation 
	struct Node* root = getNode(4); 
	root->left = getNode(2); 
	root->right = getNode(6); 
	root->left->left = getNode(1); 
	root->left->right = getNode(3); 
	root->right->left = getNode(5); 
	root->right->right = getNode(7); 

	convertToMaxHeapUtil(root); 
	cout << "Postorder Traversal of Tree:" << endl; 
	postorderTraversal(root); 

	return 0; 
}
```

**Output:**

```
Postorder Traversal of Tree:
1 2 3 4 5 6 7 
```

**Time Complexity**: O(n)

**Auxiliary Space**: O(n)
 where, n is the number of nodes in the tree

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the **[DSA Self Paced Course](https://practice.geeksforgeeks.org/courses/dsa-self-paced?utm_source=geeksforgeeks&utm_medium=article&utm_campaign=gfg_article_dsa_content_bottom)** at a student-friendly price and become industry ready.