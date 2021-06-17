# Food delivery to tech park

Created Time: Jan 01, 2021 10:23 AM
Do Date: Jan 01, 2021
Last edited time: Mar 01, 2021 8:47 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 1800
Pomos (25 mins): 2
Relates: Cherry%20Pickup%20-%20LeetCode%20a73c725479264cd2a914d52d1a898d4b.md
Status: waiting
Tags: swiggy

A Delivery Partner can deliver multiple orders to a Tech Park at the same time. On the way back to the starting point, the Delivery Partner may pick up additional orders for the next trip to the Tech Park. A map of restaurant locations where orders are

placed, has been created and represented as a square matrix.

The matrix is filled with cells, and each cell will have an initial value as follows:

1. A value 0 represents a path.
2. A value of 1 represents a restaurant with an order.
3. A value of -1 represents an obstruction.

The rules of motion are as follows:

- The Delivery Partner starts at (0, 0)and the Tech Park is at (n-1, n-1). Movement toward the Tech Park is right or down through valid path cells.
- After reaching (n-1, n-1), the Delivery Partner travels back to (0, 0)by moving left or up through valid path cells. When passing through a path cell containing a restaurant with an order, the order is picked up. Once picked up, the cell becomes an empty path cell.
- If there is no valid path between (0, 0)and (n-1, n-1), then no orders can be collected.

The ultimate goal is to collect and deliver as many orders as possible.

**Constraints**:

n <= 100

For example, consider the following grid:

**Input:**

```cpp
0  1
-1 0
```

**Output**:

1

Start at the top left corner. Move right one, collecting an order. Move down one to the Tech Park. Cell (1, 0) is blocked, so the return

path is the reverse of the path to the Tech Park. All paths have been explored, and 1 order was collected.

**Input:**

```cpp
0 1 -1
1 0 -1
1 1  1
```

**Output**:

5

---