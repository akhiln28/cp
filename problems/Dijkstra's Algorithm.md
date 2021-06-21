---
Created Time: Mar 06, 2021 4:24 PM
Do Date: Mar 27, 2021
Last edited time: Mar 27, 2021 5:34 PM
Status: done
---

# Dijkstra's Algorithm

I wonder what will be the complexity of the below method:
[Dijkstra's Shortest Path Algorithm using priority_queue of STL - GeeksforGeeks](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/)
```python
1) Initialize distances of all vertices as infinite.
2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs
3) Insert source vertex into pq and make its
   distance as 0.
4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.
           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)
               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) **Insert v into the pq (Even if v is
                    already there)**
               
5) Print distance array dist[] to print all shortest
   paths.
```
Using a set of pairs instead of a priority queue would do the trick. 
```python
initialize set of pair of index and distance size n
initialize distance of size n
distance[source] = 0
set[source] = 0
while (set.size()):
	choose the index with smallest distance
	
```
Patterns: [patterns/Greedy](patterns/Greedy.md)