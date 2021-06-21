---
Created Time: Mar 20, 2021 1:57 PM
Last edited time: May 23, 2021 8:53 AM
Source: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c2c3
Status: waiting
---

# Checksum - Kick Start

### Problem
Grace and Edsger are constructing a  boolean matrix . The element in -th row and -th column is represented by . They decide to note down the checksum (defined as bitwise XOR of given list of elements) along each row and column. Checksum of -th row is represented as . Checksum of -th column is represented as .
Once they finished the matrix, Edsger stores the matrix in his computer. However, due to a virus, some of the elements in matrix  are replaced with  in Edsger's computer. Luckily, Edsger still remembers the checksum values. He would like to restore the matrix, and reaches out to Grace for help. After some investigation, it will take  hours for Grace to recover the original value of  from the disk. Given the final matrix , cost matrix , and checksums along each row () and column (), can you help Grace decide on the minimum total number of hours needed in order to restore the original matrix ?
### Input
The next  lines each contain  integers representing the matrix . -th element on the -th line represents .
The next  lines each contain  integers representing the matrix . -th element on the -th line represents .
### Output
For each test case, output one line containing `Case #:` , where  is the test case number (starting from 1) and  is the minimum number of hours to restore matrix .
![Checksum%20-%20Kick%20Start%20d83f3d37e0fe44f3a2ab189d707b8d01/Untitled.png](Checksum%20-%20Kick%20Start%20d83f3d37e0fe44f3a2ab189d707b8d01/Untitled.png)
### Sample
```
3
3
1 -1 0
0 1 0
1 1 1
0 1 0
0 0 0
0 0 0
1 1 1
0 0 1
2
-1 -1
-1 -1
1 10
100 1000
1 0
0 1
3
-1 -1 -1
-1 -1 -1
0 0 0
1 1 3
5 1 4
0 0 0
0 0 0
0 0 0
```
```
Case #1: 0
Case #2: 1
Case #3: 2
```
In Sample Case #1,  can be restored using the checksum of either 1-st row or 2-nd column. Hence, Grace can restore the matrix without spending any time to recover the data.
In Sample Case #2, Grace spends one hour to recover . After that, she can use checksums of 1-st row and 1-st column to restore  and  respectively. And then she can use checksum of 2-nd row to restore . Hence, Grace can restore the matrix by spending one hour.
In Sample Case #3, Grace can spend one hour to recover  and another hour to recover . After that, she can use checksum to restore the rest of the matrix. Hence, Grace can restore the matrix by spending two hours in total.
Patterns: 