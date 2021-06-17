# Print all the cycles in an undirected graph - GeeksforGeeks

Created Time: Feb 14, 2021 9:15 AM
Last edited time: May 20, 2021 9:55 AM
Points: 1800
Source: https://www.geeksforgeeks.org/print-all-the-cycles-in-an-undirected-graph/
Status: waiting

Given an undirected graph, print all the vertices that form cycles in it. **Pre-requisite:** [Detect Cycle in a directed graph using colors](https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/)

![Print%20all%20the%20cycles%20in%20an%20undirected%20graph%20-%20Geek%2023c6ce1d74d149f494bb69590a416b5b/Screen-Shot-2018-08-21-at-7.17.58-PM.png](problems/Print%20all%20the%20cycles%20in%20an%20undirected%20graph%20-%20Geek%2023c6ce1d74d149f494bb69590a416b5b/Screen-Shot-2018-08-21-at-7.17.58-PM.png)

In the above diagram, the cycles have been marked with dark green color. The output for the above will be

> 1st cycle: 3 5 4 6 2nd cycle: 11 12 13

**Approach:** Using the [graph coloring method](https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/), mark all the vertex of the different cycles with unique numbers. Once the graph traversal is completed, push all the similar marked numbers to an adjacency list and print the adjacency list accordingly. Given below is the algorithm:

- Insert the edges into an adjacency list.
- Call the DFS function which uses the coloring method to mark the vertex.
- Whenever there is a partially visited vertex, **backtrack** till the current vertex is reached and mark all of them with cycle numbers. Once all the vertexes are marked, increase the cycle number.
- Once Dfs is completed, iterate for the edges and push the same marked number edges to another adjacency list.
- Iterate in another adjacency list and print the vertex cycle-number wise.

Below is the implementation of the above approach:

```
// C++ program to print all the cycles
```

```
// in an undirected graph
```

```
#include <bits/stdc++.h>
```

```
using
```

```
namespace
```

```
std;
```

```
const
```

```
int
```

```
N = 100000;
```

```
// variables to be used
```

```
// in both functions
```

```
vector<
```

```
int
```

```
> graph[N];
```

```
vector<
```

```
int
```

```
> cycles[N];
```

```
// Function to mark the vertex with
```

```
// different colors for different cycles
```

```
void
```

```
dfs_cycle(
```

```
int
```

```
u, 
```

```
int
```

```
p, 
```

```
int
```

```
color[],
```

```
int
```

```
mark[], 
```

```
int
```

```
par[], 
```

```
int
```

```
& cyclenumber)
```

```
{
```

```
// already (completely) visited vertex.
```

```
if
```

```
(color[u] == 2) {
```

```
return
```

```
;
```

```
}
```

```
// seen vertex, but was not completely visited -> cycle detected.
```

```
// backtrack based on parents to find the complete cycle.
```

```
if
```

```
(color[u] == 1) {
```

```
cyclenumber++;
```

```
int
```

```
cur = p;
```

```
mark[cur] = cyclenumber;
```

```
// backtrack the vertex which are
```

```
// in the current cycle thats found
```

```
while
```

```
(cur != u) {
```

```
cur = par[cur];
```

```
mark[cur] = cyclenumber;
```

```
}
```

```
return
```

```
;
```

```
}
```

```
par[u] = p;
```

```
// partially visited.
```

```
color[u] = 1;
```

```
// simple dfs on graph
```

```
for
```

```
(
```

```
int
```

```
v : graph[u]) {
```

```
// if it has not been visited previously
```

```
if
```

```
(v == par[u]) {
```

```
continue
```

```
;
```

```
}
```

```
dfs_cycle(v, u, color, mark, par, cyclenumber);
```

```
}
```

```
// completely visited.
```

```
color[u] = 2;
```

```
}
```

```
// add the edges to the graph
```

```
void
```

```
addEdge(
```

```
int
```

```
u, 
```

```
int
```

```
v)
```

```
{
```

```
graph[u].push_back(v);
```

```
graph[v].push_back(u);
```

```
}
```

```
// Function to print the cycles
```

```
void
```

```
printCycles(
```

```
int
```

```
edges, 
```

```
int
```

```
mark[], 
```

```
int
```

```
& cyclenumber)
```

```
{
```

```
// push the edges that into the
```

```
// cycle adjacency list
```

```
for
```

```
(
```

```
int
```

```
i = 1; i <= edges; i++) {
```

```
if
```

```
(mark[i] != 0)
```

```
cycles[mark[i]].push_back(i);
```

```
}
```

```
// print all the vertex with same cycle
```

```
for
```

```
(
```

```
int
```

```
i = 1; i <= cyclenumber; i++) {
```

```
// Print the i-th cycle
```

```
cout << 
```

```
"Cycle Number "
```

```
<< i << 
```

```
": "
```

```
;
```

```
for
```

```
(
```

```
int
```

```
x : cycles[i])
```

```
cout << x << 
```

```
" "
```

```
;
```

```
cout << endl;
```

```
}
```

```
}
```

```
// Driver Code
```

```
int
```

```
main()
```

```
{
```

```
// add edges
```

```
addEdge(1, 2);
```

```
addEdge(2, 3);
```

```
addEdge(3, 4);
```

```
addEdge(4, 6);
```

```
addEdge(4, 7);
```

```
addEdge(5, 6);
```

```
addEdge(3, 5);
```

```
addEdge(7, 8);
```

```
addEdge(6, 10);
```

```
addEdge(5, 9);
```

```
addEdge(10, 11);
```

```
addEdge(11, 12);
```

```
addEdge(11, 13);
```

```
addEdge(12, 13);
```

```
// arrays required to color the
```

```
// graph, store the parent of node
```

```
int
```

```
color[N];
```

```
int
```

```
par[N];
```

```
// mark with unique numbers
```

```
int
```

```
mark[N];
```

```
// store the numbers of cycle
```

```
int
```

```
cyclenumber = 0;
```

```
int
```

```
edges = 13;
```

```
// call DFS to mark the cycles
```

```
dfs_cycle(1, 0, color, mark, par, cyclenumber);
```

```
// function to print the cycles
```

```
printCycles(edges, mark, cyclenumber);
```

```
}
```

**Output:**

```
Cycle Number 1: 3 4 5 6 
Cycle Number 2: 11 12 13 

```

**Time Complexity:** O(N + M), where N is the number of vertexes and M is the number of edges. **Auxiliary Space:** O(N + M)

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the **[DSA Self Paced Course](https://practice.geeksforgeeks.org/courses/dsa-self-paced?utm_source=geeksforgeeks&utm_medium=article&utm_campaign=gfg_article_dsa_content_bottom)** at a student-friendly price and become industry ready.