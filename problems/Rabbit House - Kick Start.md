---
Created Time: Mar 20, 2021 1:56 PM
Last edited time: May 23, 2021 8:53 AM
Source: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14
Status: waiting
---

# Rabbit House - Kick Start

![kickstart-fb.jpg](Rabbit%20House%20-%20Kick%20Start%20fd15c4ff54be48fd9c071db388b094eb/kickstart-fb.jpg)
### Problem
Barbara got really good grades in school last year, so her parents decided to gift her with a pet rabbit. She was so excited that she built a house for the rabbit, which can be seen as a 2D grid with  rows and  columns.
Rabbits love to jump, so Barbara stacked several boxes on several cells of the grid. Each box is a cube with equal dimensions, which match exactly the dimensions of a cell of the grid.
However, Barbara soon realizes that it may be dangerous for the rabbit to make jumps of height greater than  box, so she decides to avoid that by making some adjustments to the house. For every pair of adjacent cells, Barbara would like that their absolute difference in height be at most  box. Two cells are considered adjacent if they share a common side.
As all the boxes are superglued, Barbara cannot remove any boxes that are there initially, however she can add boxes on top of them. She can add as many boxes as she wants, to as many cells as she wants (which may be zero). Help her determine what is the minimum total number of boxes to be added so that the rabbit's house is safe.
### Input
Then,  lines follow, each with  integers. The -th integer on -th line, , represents how many boxes are there initially on the cell located at the -th row and -th column of the grid.
### Output
For each test case, output one line containing `Case #:` , where  is the test case number (starting from 1) and  is the minimum number of boxes to be added so that the rabbit's house is safe.
### Limits
### Test Set 1
### Test Set 2
### Sample
In Sample Case #1, the absolute difference in height for every pair of adjacent cells is already at most  box, so there is no need to add any extra boxes.
In Sample Case #2, the absolute difference in height of the left-most cell and the middle cell is  boxes. To fix that, we can add  boxes to the middle cell. But then, the absolute difference of the middle cell and the right-most cell will be  boxes, so Barbara can fix that by adding  box to the right-most cell. After adding these  boxes, the safety condition is satisfied.
In Sample Case #3, the cell in the middle of the grid has an absolute difference in height of  boxes with all of its four adjacent cells. One solution is to add exactly  box to all of the middle's adjacent cells, so that the absolute difference between any pair of adjacent cells will be at most  box. That requires  boxes in total.
Patterns: 