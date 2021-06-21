---
Created Time: Mar 29, 2021 8:41 AM
Last edited time: Mar 29, 2021 8:41 AM
Source: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
Status: done
---

# Reversort - Code Jam

![codejam-fb.jpg](Reversort%20-%20Code%20Jam%20445bf3512d9d422b81f76007baa55318/codejam-fb.jpg)
### Problem
Note: The main parts of the statements of the problems "Reversort" and "Reversort Engineering" are identical, except for the last paragraph. The problems can otherwise be solved independently.
Reversort is an algorithm to sort a list of distinct integers in increasing order. The algorithm is based on the "Reverse" operation. Each application of this operation reverses the order of some contiguous part of the list.
The pseudocode of the algorithm is the following:
```
Reversort(L):
  for i := 1 to length(L) - 1
    j := position with the minimum value in L between i and length(L), inclusive
    Reverse(L[i..j])
```
After  iterations, the positions  of the list contain the  smallest elements of L, in increasing order. During the -th iteration, the process reverses the sublist going from the -th position to the current position of the -th minimum element. That makes the -th minimum element end up in the -th position.
For example, for a list with  elements, the algorithm would perform  iterations. Here is how it would process :
The most expensive part of executing the algorithm on our architecture is the Reverse operation. Therefore, our measure for the cost of each iteration is simply the length of the sublist passed to Reverse, that is, the value . The cost of the whole algorithm is the sum of the costs of each iteration.
In the example above, the iterations cost , , and , in that order, for a total of .
Given the initial list, compute the cost of executing Reversort on it.
### Input
The first line of the input gives the number of test cases, .  test cases follow. Each test case consists of 2 lines. The first line contains a single integer , representing the number of elements in the input list. The second line contains  distinct integers , , ..., , representing the elements of the input list , in order.
### Output
For each test case, output one line containing `Case #:` , where  is the test case number (starting from 1) and  is the total cost of executing Reversort on the list given as input.
### Limits
Time limit: 10 seconds.
 Memory limit: 1 GB.
### Test Set 1 (Visible Verdict)
### Sample
Sample Case #1 is described in the statement above.
In Sample Case #2, there is a single iteration, in which Reverse is applied to a sublist of size 1. Therefore, the total cost is 1.
In Sample Case #3, the first iteration reverses the full list, for a cost of 7. After that, the list is already sorted, but there are 5 more iterations, each of which contributes a cost of 1.
Patterns: 