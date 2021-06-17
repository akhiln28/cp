# Probability that the second best is the runner up

Created Time: Feb 10, 2021 1:04 PM
Do Date: Feb 10, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1200
Status: done

given 2n people, they participate in the tournament. what the probability that the person with the second highest strength is the runner up. 

$$\frac{2n-2}{2n - 1} \times \frac{n - 2}{n - 1}\times \frac{n/2 - 2}{n/2 - 1} ...$$

$$\Rightarrow \frac{n}{2n-1}$$