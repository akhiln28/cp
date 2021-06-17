# Range tree - Wikipedia

[https://en.wikipedia.org/wiki/Range_tree#:~:text=Data%20structure,-An%20example%20of&text=A%20range%20tree%20on%20a,contained%20in%20its%20left%20subtree.](https://en.wikipedia.org/wiki/Range_tree#:~:text=Data%20structure,-An%20example%20of&text=A%20range%20tree%20on%20a,contained%20in%20its%20left%20subtree.)

![880px-1-dimensional-range-tree.svg.png](880px-1-dimensional-range-tree.svg.png)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **range tree** is an [ordered tree](https://en.wikipedia.org/wiki/Ordered_tree_data_structure) [data structure](https://en.wikipedia.org/wiki/Data_structure) to hold a list of points. It allows all points within a given range to be [reported](https://en.wikipedia.org/wiki/Range_query) efficiently, and is typically used in two or higher dimensions. Range trees were introduced by [Jon Louis Bentley](https://en.wikipedia.org/wiki/Jon_Louis_Bentley) in 1979.[[1]](https://en.wikipedia.org/wiki/Range_tree) Similar data structures were discovered independently by Lueker,[[2]](https://en.wikipedia.org/wiki/Range_tree) Lee and Wong,[[3]](https://en.wikipedia.org/wiki/Range_tree) and Willard.[[4]](https://en.wikipedia.org/wiki/Range_tree) The range tree is an alternative to the [k-d tree](https://en.wikipedia.org/wiki/K-d_tree). Compared to k-d trees, range trees offer faster query times of (in [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation))

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/9312fe5a8de4d58497ddcac118796736c2d06629](9312fe5a8de4d58497ddcac118796736c2d06629)

but worse storage of

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/4a35f590b482e5c2772ac500016102d1d829200e](4a35f590b482e5c2772ac500016102d1d829200e)

, where n is the number of points stored in the tree, d is the dimension of each point and k is the number of points reported by a given query.

[Bernard Chazelle](https://en.wikipedia.org/wiki/Bernard_Chazelle) improved this to query time

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/d8ec3b35521f0bff4c75d53f8181797721d7f513](d8ec3b35521f0bff4c75d53f8181797721d7f513)

and space complexity

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/85b11376867cb32e5050caecac9ad8985a2e3418](85b11376867cb32e5050caecac9ad8985a2e3418)

.[[5][6]](https://en.wikipedia.org/wiki/Range_tree)

## Data structure[[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=1)]

![Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/440px-1-dimensional-range-tree.svg.png](440px-1-dimensional-range-tree.svg.png)

An example of a 1-dimensional range tree. Each node which is not a leaf stores the maximum value in its left subtree.

A range tree on a set of 1-dimensional points is a balanced [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) on those points. The points stored in the tree are stored in the leaves of the tree; each internal node stores the largest value contained in its left subtree. A range tree on a set of points in d-dimensions is a [recursively defined](https://en.wikipedia.org/wiki/Recursive_data_type) multi-level [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree). Each level of the data structure is a binary search tree on one of the d-dimensions. The first level is a binary search tree on the first of the d-coordinates. Each vertex v of this tree contains an associated structure that is a (d−1)-dimensional range tree on the last (d−1)-coordinates of the points stored in the subtree of v.

## Operations[[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=2)]

### Construction[[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=3)]

A 1-dimensional range tree on a set of n points is a binary search tree, which can be constructed in

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/9d2320768fb54880ca4356e61f60eb02a3f9d9f1](9d2320768fb54880ca4356e61f60eb02a3f9d9f1)

time. Range trees in higher dimensions are constructed recursively by constructing a balanced binary search tree on the first coordinate of the points, and then, for each vertex v in this tree, constructing a (d−1)-dimensional range tree on the points contained in the subtree of v. Constructing a range tree this way would require

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/9c081c8af02814b7a0807c486f03ead35d9aebcc](9c081c8af02814b7a0807c486f03ead35d9aebcc)

time.

This construction time can be improved for 2-dimensional range trees to

.[[7]](https://en.wikipedia.org/wiki/Range_tree) Let S be a set of n 2-dimensional points. If S contains only one point, return a leaf containing that point. Otherwise, construct the associated structure of S, a 1-dimensional range tree on the y-coordinates of the points in S. Let xm be the median x-coordinate of the points. Let SL be the set of points with x-coordinate less than or equal to xm and let SR be the set of points with x-coordinate greater than xm. Recursively construct vL, a 2-dimensional range tree on SL, and vR, a 2-dimensional range tree on SR. Create a vertex v with left-child vL and right-child vR. If we sort the points by their y-coordinates at the start of the algorithm, and maintain this ordering when splitting the points by their x-coordinate, we can construct the associated structures of each subtree in linear time. This reduces the time to construct a 2-dimensional range tree to

, and also reduces the time to construct a d-dimensional range tree to

.

### Range queries[[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=4)]

![Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/220px-1-dimensional-range-query.svg.png](220px-1-dimensional-range-query.svg.png)

A 1-dimensional range query [x1, x2]. Points stored in the subtrees shaded in gray will be reported. find(x1) and find(x2) will be reported if they are inside the query interval.

A [range query](https://en.wikipedia.org/wiki/Range_query_(data_structures)) on a range tree reports the set of points that lie inside a given interval. To report the points that lie in the interval [x1, x2], we start by searching for x1 and x2. At some vertex in the tree, the search paths to x1 and x2 will diverge. Let vsplit be the last vertex that these two search paths have in common. For every vertex v in the search path from vsplit to x1, if the value stored at v is greater than x1, report every point in the right-subtree of v. If v is a leaf, report the value stored at v if it is inside the query interval. Similarly, reporting all of the points stored in the left-subtrees of the vertices with values less than x2 along the search path from vsplit to x2, and report the leaf of this path if it lies within the query interval.

Since the range tree is a balanced binary tree, the search paths to x1 and x2 have length

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/aae0f22048ba6b7c05dbae17b056bfa16e21807d](aae0f22048ba6b7c05dbae17b056bfa16e21807d)

. Reporting all of the points stored in the subtree of a vertex can be done in linear time using any [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) algorithm. It follows that the time to perform a range query is

[Range%20tree%20-%20Wikipedia%2022ea1e8a4a9d467ab2d1c6a2aee34a50/1a7c999f07c8c2b6ba6e06e8532628f7e1c097b6](1a7c999f07c8c2b6ba6e06e8532628f7e1c097b6)

, where k is the number of points in the query interval.

Range queries in d-dimensions are similar. Instead of reporting all of the points stored in the subtrees of the search paths, perform a (d−1)-dimensional range query on the associated structure of each subtree. Eventually, a 1-dimensional range query will be performed and the correct points will be reported. Since a d-dimensional query consists of

(d−1)-dimensional range queries, it follows that the time required to perform a d-dimensional range query is

, where k is the number of points in the query interval. This can be reduced to

using a variant of [fractional cascading](https://en.wikipedia.org/wiki/Fractional_cascading).[[2][4][7]](https://en.wikipedia.org/wiki/Range_tree)

## See also[[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=5)]

- [kd tree](https://en.wikipedia.org/wiki/K-d_tree)
- [Segment tree](https://en.wikipedia.org/wiki/Segment_tree)
- [Range searching](https://en.wikipedia.org/wiki/Range_searching)

## [[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=6)]

## External links[[edit](https://en.wikipedia.org/w/index.php?title=Range_tree&action=edit&section=7)]

- [Range and Segment Trees](https://www.cgal.org/Manual/latest/doc_html/cgal_manual/SearchStructures/Chapter_main.html) in [CGAL](https://en.wikipedia.org/wiki/CGAL), the Computational Geometry Algorithms Library.
- [Lecture 8: Range Trees](http://www.cs.uu.nl/docs/vakken/ga/2019/slides/slides5b.pdf), Marc van Kreveld.
- [Range Trees](https://github.com/syhlalala/PAM/tree/master/range_query) using [PAM](https://en.wikipedia.org/wiki/PAM_library), the parallel augmented map library.