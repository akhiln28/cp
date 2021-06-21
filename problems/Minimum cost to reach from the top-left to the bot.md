---
Created Time: Dec 26, 2020 10:31 AM
Do Date: Jan 08, 2021
Last edited time: May 11, 2021 8:59 AM
Points: 1500
Source: https://www.geeksforgeeks.org/minimum-cost-to-reach-from-the-top-left-to-the-bottom-right-corner-of-a-matrix/?ref=rp
Status: done
Tags: path cost
---

# Minimum cost to reach from the top-left to the bottom-right corner of a matrix - Geeksforgeeks

Given an **N * M** matrix **mat[][]** consisting of lower case characters, the task is to find the minimum cost to reach from the cell **mat[0][0]** to the cell **mat[N-1][M-1]**. If you are at a cell **mat[i][j]**, you can jump to the cells **mat[i+1][j]**, **mat[i][j+1]**, **mat[i-1][j]**, **mat[i][j-1]** (without going out of bounds) with a cost of **1**. Additionally, you can jump to any cell **mat[m][n]** such that **mat[n][m] = mat[i][j]** with a cost of **0**.
**Examples:**
```cpp
Input: mat[][] = {“abc”, “efg”, “hij”}
Output: 4
One of the shortest path will be:
{0, 0} -> {0, 1} -> {0, 2} -> {1, 2} -> {2, 2}
All the edges have a weight of 1, thus the answer is 4.
Input: mat[][] = {“abc”, “efg”, “hbj”}
Output: 2
{0, 0} -> {0, 1} -> {2, 1} -> {2, 2}
1 + 0 + 1 = 2
```
---
Given an **N * M** matrix **mat[][]** consisting of lower case characters, the task is to find the minimum cost to reach from the cell **mat[0][0]** to the cell **mat[N-1][M-1]**. If you are at a cell **mat[i][j]**, you can jump to the cells **mat[i+1][j]**, **mat[i][j+1]**, **mat[i-1][j]**, **mat[i][j-1]** (without going out of bounds) with a cost of **1**. Additionally, you can jump to any cell **mat[m][n]** such that **mat[n][m] = mat[i][j]** with a cost of **0**.
**Examples:**
> Input: mat[][] = {“abc”, “efg”, “hij”} Output: 4 One of the shortest path will be: {0, 0} -> {0, 1} -> {0, 2} -> {1, 2} -> {2, 2} All the edges have a weight of 1, thus the answer is 4. Input: mat[][] = {“abc”, “efg”, “hbj”} Output: 2 {0, 0} -> {0, 1} -> {2, 1} -> {2, 2} 1 + 0 + 1 = 2
**Naive approach:** One approach for solving this problem will be [0-1 BFS](https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/). Visualise the setup as a graph with **N * M** nodes. All the nodes will be connected to adjacent nodes with an edge of weight **1** and the nodes with the same characters with an edge with weight **0**. Now, BFS can be used to find the shortest path from the cell **mat[0][0]** to the cell mat[N-1][M-1]. The time complexity of this will be **O((N * M)2)** because the number of edges will be of the order O((N * M)2).
**Efficient approach:** For each character **X**, find all the characters it is adjacent to. Now, create a graph with a number of nodes as the number of distinct characters in the string each representing a character.
 Each node **X** will have an edge of weight **1** with all the nodes representing the characters adjacent to the character **X** in the real graph. Then a BFS can be run from the node representing **mat[0][0]** to the node representing **mat[N-1][M-1]** in this new graph. The time complexity of this approach will be **O(N * M)** for pre-processing the graph and the time complexity for running the BFS can be considered constant.
Below is the implementation of the above approach:
```cpp
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 26; 
// Function to return 
// the value (x - 97) 
int f(int x) 
{ 
	return x - 'a'; 
} 
// Function to return the minimum cost 
int findMinCost(vector<string> arr) 
{ 
	int n = arr.size(); 
	int m = arr[0].size(); 
	// Graph 
	vector<vector<int> > gr(MAX); 
	// Adjacency matrix 
	bool edge[MAX][MAX]; 
	// Initialising the adjacency matrix 
	for (int k = 0; k < MAX; k++) 
		for (int l = 0; l < MAX; l++) 
			edge[k][l] = 0; 
	// Creating the adjacency matrix 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) { 
			if (i + 1 < n and !edge[f(arr[i][j])][f(arr[i + 1][j])]) { 
				gr[f(arr[i][j])].push_back(f(arr[i + 1][j])); 
				edge[f(arr[i][j])][f(arr[i + 1][j])] = 1; 
			} 
			if (j - 1 >= 0 and !edge[f(arr[i][j])][f(arr[i][j - 1])]) { 
				gr[f(arr[i][j])].push_back(f(arr[i][j - 1])); 
				edge[f(arr[i][j])][f(arr[i][j - 1])] = 1; 
			} 
			if (j + 1 < m and !edge[f(arr[i][j])][f(arr[i][j + 1])]) { 
				gr[f(arr[i][j])].push_back(f(arr[i][j + 1])); 
				edge[f(arr[i][j])][f(arr[i][j + 1])] = 1; 
			} 
			if (i - 1 >= 0 and !edge[f(arr[i][j])][f(arr[i - 1][j])]) { 
				gr[f(arr[i][j])].push_back(f(arr[i - 1][j])); 
				edge[f(arr[i][j])][f(arr[i - 1][j])] = 1; 
			} 
		} 
	// Queue to perform BFS 
	queue<int> q; 
	q.push(arr[0][0] - 'a'); 
	// Visited array 
	bool v[MAX] = { 0 }; 
	// To store the depth of BFS 
	int d = 0; 
	// BFS 
	while (q.size()) { 
		// Number of elements in 
		// the current level 
		int cnt = q.size(); 
		// Inner loop 
		while (cnt--) { 
			// Current element 
			int curr = q.front(); 
			// Popping queue 
			q.pop(); 
			// If the current node has 
			// already been visited 
			if (v[curr]) 
				continue; 
			v[curr] = 1; 
			// Checking if the current 
			// node is the required node 
			if (curr == arr[n - 1][m - 1] - 'a') 
				return d; 
			// Iterating through the current node 
			for (auto it : gr[curr]) 
				q.push(it); 
		} 
		// Updating the depth 
		d++; 
	} 
	return -1; 
} 
// Driver code 
int main() 
{ 
	vector<string> arr = { "abc", 
						"def", 
						"gbi" }; 
	cout << findMinCost(arr); 
	return 0; 
}
```
Patterns: [BFS](BFS.md)