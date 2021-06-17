# Minimum Cost Path with Left, Right, Bottom and Up moves allowed - GeeksforGeeks

Created Time: Dec 26, 2020 10:16 AM
Last edited time: Mar 01, 2021 3:42 PM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1700
Relates: Swiggy%20Mascot%20Travel%2095ff829855de46f7b4f8ca1d1501620c.md
Source: https://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/?ref=rp
Status: ok
Tags: graph, path cost

Given a two dimensional grid, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum.

**Note :** It is assumed that negative cost cycles do not exist in input matrix.This problem is extension of below problem.[Min Cost Path with right and bottom moves allowed.](https://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/)In previous problem only going right and bottom was allowed but in this problem we are allowed to go bottom, up, right and left i.e. in all 4 direction.Examples:

![https://media.geeksforgeeks.org/wp-content/uploads/costMatrix.png](https://media.geeksforgeeks.org/wp-content/uploads/costMatrix.png)

```
A cost grid is given in below diagram, minimum 
cost to reach bottom right from top left 
is 327 (= 31 + 10 + 13 + 47 + 65 + 12 + 18 + 
6 + 33 + 11 + 20 + 41 + 20)

The chosen least cost path is shown in green.
```

---

Given a two dimensional grid, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum.**Note :** It is assumed that negative cost cycles do not exist in input matrix.
This problem is extension of below problem.[Min Cost Path with right and bottom moves allowed.](https://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/)
In previous problem only going right and bottom was allowed but in this problem we are allowed to go bottom, up, right and left i.e. in all 4 direction.
Examples:

```
A cost grid is given in below diagram, minimum 
cost to reach bottom right from top left 
is 327 (= 31 + 10 + 13 + 47 + 65 + 12 + 18 + 
6 + 33 + 11 + 20 + 41 + 20)

The chosen least cost path is shown in green.

Click to enlarge
```

![Minimum%20Cost%20Path%20with%20Left,%20Right,%20Bottom%20and%20Up%20%20b4e2d561d652469fb88e5204618bc344/costMatrix.png](costMatrix.png)

It is not possible to solve this problem using dynamic programming similar to previous problem because here current state depends not only on right and bottom cells but also on left and upper cells. We solve this problem using [dijkstra’s algorithm](https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/). Each cell of grid represents a vertex and neighbor cells adjacent vertices. We do not make an explicit graph from these cells instead we will use matrix as it is in our dijkstra’s algorithm. 
In below code [Dijkstra’ algorithm’s implementation](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/) is used. The code implemented below is changed to cope with matrix represented implicit graph. Please also see use of dx and dy arrays in below code, these arrays are taken for simplifying the process of visiting neighbor vertices of each cell.

**Output:**

```
327

```

This article is contributed by **[Utkarsh Trivedi](https://in.linkedin.com/in/utkarsh-trivedi-253069a7)**. If you like GeeksforGeeks and would like to contribute, you can also write an article using [contribute.geeksforgeeks.org](http://www.contribute.geeksforgeeks.org/) or mail your article to contribute@geeksforgeeks.org. See your article appearing on the GeeksforGeeks main page and help other Geeks.
Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the **[DSA Self Paced Course](https://practice.geeksforgeeks.org/courses/dsa-self-paced?utm_source=geeksforgeeks&utm_medium=article&utm_campaign=gfg_article_dsa_content_bottom)** at a student-friendly price and become industry ready.