# Swiggy Mascot Travel

Created Time: Dec 17, 2020 6:39 PM
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2000
Pomos (25 mins): 2
Related To: Minimum%20Cost%20Path%20with%20Left,%20Right,%20Bottom%20and%20Up%20%20b4e2d561d652469fb88e5204618bc344.md
Status: waiting
Tags: graph, path cost, swiggy

![Swiggy%20Mascot%20Travel%2095ff829855de46f7b4f8ca1d1501620c/Untitled.png](problems/Swiggy%20Mascot%20Travel%2095ff829855de46f7b4f8ca1d1501620c/Untitled.png)

There is an excitation matrix A of the size NxM where $A[i][j]$ signifies the excitation level of the node present in i th row and j th column. 

All the excitation energy values in the matrix are non-negative. 
Swiggy Mascot has to travel from the left most node in the first row to right most node in the last row using the least energy possible. 
From a node on the matrix, Mascot is allowed to move in only four directions and in each move Mascot can take only one step i.e go one step vertically, horizontally, to the right or to the left. 

The energy required for a move from one node to its adjacent node is the modulus difference between the excitation energies of the nodes i.e ifX, Y are the excitation energies of the two adjacent nodes then energy required for this step is IX-YI . If path P from Source S to destination D is defined as the maximum of all the energies required over the path i.e if P involves traveling through points R, T - then the energy required to travel from Source S to destination D is max(energy_required(S,R), energy_required(R,T), energy_required(T,D)). 

Help Swiggy Mascot in finding the least energy value using which it can travel from the top left most corner to bottom right most corner. 

**Input Format:** 
The first line contains two values N and M. The number of rows and columns respectively, 

The next N lines each contain M space separated values. The j th value in the i th row signifies the excitation energy of the j th node in the ith row. 

**Constraints**: 

$1 \le (N * M) \le 10^5$

$1 \le A[i][j] \le 10^9$

Output Format: 

Output will be a single non-negative value. 

**Sample Input:** 

```cpp
2 2
1 5
4 10
```

**Sample Output:** 

```cpp
5
```

Explanation: 

Mascot will first move to the right and then bottom. The energy required for moving right is 15-1 1 = 4. The energy required to move bottom from there is 110-51 = 5. So, the total energy required is max(4, 5) = 5. We can't have any other path with lesser energy than this. 

---

Lets construct a graph with edges as the energy. Now we need to find the path with least maximum edge. This graph is not a directed acyclic graph. There can be cycles.  So, how about Dijkstra's algorithm.