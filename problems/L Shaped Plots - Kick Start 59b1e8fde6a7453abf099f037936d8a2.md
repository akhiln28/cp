# L Shaped Plots - Kick Start

Created Time: Mar 20, 2021 1:56 PM
Do Date: Mar 22, 2021
Last edited time: Mar 28, 2021 10:50 PM
Source: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c509
Status: done

### Problem

A segment is a nonempty sequence of consecutive cells such that all cells are in the same row or the same column. We define the length of a segment as number of cells in the sequence.

A segment is called "good" if all the cells in the segment contain only s.

An "L-shape" is defined as an unordered pair of segments, which has all the following properties:

- Each of the segments must be a "good" segment.
- The two segments must be perpendicular to each other.
- The segments must share one cell that is an endpoint of both segments.
- The length of the longer segment is twice the length of the shorter segment.

We need to count the number of L-shapes in the grid.

Below you can find two examples of correct L-shapes,

![L%20Shaped%20Plots%20-%20Kick%20Start%2059b1e8fde6a7453abf099f037936d8a2/examples_correct.png](examples_correct.png)

and three examples of **invalid** L-shapes.

![L%20Shaped%20Plots%20-%20Kick%20Start%2059b1e8fde6a7453abf099f037936d8a2/examples_incorrect.png](examples_incorrect.png)

Note that in the shape on the left, two segments do not share a common endpoint. The next two shapes do not meet the last requirement, as in the middle shape both segments have the same length, and in the last shape the longer segment is longer than twice the length of the shorter one.

### Input

### Output

For each test case, output one line containing `Case #:` , where  is the test case number (starting from 1) and  is the number of L-shapes.

### Limits

### Test Set 1

### Test Set 2

### Sample

```
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0

```

```
Case #1: 1
Case #2: 9

```

In Sample Case #1, there is one L-shape.

![L%20Shaped%20Plots%20-%20Kick%20Start%2059b1e8fde6a7453abf099f037936d8a2/sample1.png](sample1.png)

In Sample Case #2, there are nine L-shapes.

The first three L-shapes are shown on the picture below.

![L%20Shaped%20Plots%20-%20Kick%20Start%2059b1e8fde6a7453abf099f037936d8a2/sample2.png](sample2.png)