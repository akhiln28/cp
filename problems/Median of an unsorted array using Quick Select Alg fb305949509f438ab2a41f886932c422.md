# Median of an unsorted array using Quick Select Algorithm - Geeksforgeeks

Created Time: Feb 12, 2021 7:57 AM
Last edited time: May 23, 2021 8:53 AM
Points: 2000
Source: https://www.geeksforgeeks.org/median-of-an-unsorted-array-in-liner-time-on/#:~:text=Median%20of%20a%20sorted%20array,elements%20when%20n%20is%20even.&text=Naive%20Approach%3A,arr%5Bn%2F2%5D.
Status: waiting

Given an unsorted array **arr[]** of length **N**, the task is to find the median of of this array. **[Median](https://www.geeksforgeeks.org/program-for-mean-and-median-of-an-unsorted-array/)** of a sorted array of size N is defined as the middle element when n is odd and average of middle two elements when n is even.**Examples:**

> Input: arr[] = {12, 3, 5, 7, 4, 19, 26} Output: 7 Sorted sequence of given array arr[] = {3, 4, 5, 7, 12, 19, 26} Since the number of elements is odd, the median is 4th element in the sorted sequence of given array arr[], which is 7Input: arr[] = {12, 3, 5, 7, 4, 26} Output: 6 Since number of elements are even, median is average of 3rd and 4th element in sorted sequence of given array arr[], which means (5 + 7)/2 = 6

**Naive Approach:**

- [Sort the array](https://www.geeksforgeeks.org/sorting-algorithms/) arr[] in increasing order.
- If number of elements in **arr[]** is odd, then median is **arr[n/2]**.
- If the number of elements in **arr[]** is even, median is **average of arr[n/2] and arr[n/2+1]**.

Please refer to [this article](https://www.geeksforgeeks.org/program-for-mean-and-median-of-an-unsorted-array/) for implementation of above approach.**Efficient Approach: using [Randomized QuickSelect](https://www.geeksforgeeks.org/quickselect-algorithm/)**

- Randomly pick pivot element from **arr[]** and the using the **partition step** from the [quick sort](http://www.geeksforgeeks.org/quick-sort/) algorithm arrange all the elements smaller than the pivot on its left and the elements greater than it on its right.
- If after the previous step, the position of the chosen pivot is the middle of the array then it is the required median of the given array.
- If the position is before the middle element then repeat the step for the subarray starting from previous starting index and the chosen pivot as the ending index.
- If the position is after the middle element then repeat the step for the subarray starting from the chosen pivot and ending at the previous ending index.
- Note that in case of even number of elements, the middle two elements have to be found and their average will be the median of the array.

Below is the implementation of the above approach:

**Time Complexity:**

1. Best case analysis: O(1)
2. Average case analysis: O(N)
3. Worst case analysis: O(N^2)

Wonder how? 
Reference: [ByStanfordUniversity](https://web.stanford.edu/class/archive/cs/cs161/cs161.1138/lectures/09/Small09.pdf)

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the **[DSA Self Paced Course](https://practice.geeksforgeeks.org/courses/dsa-self-paced?utm_source=geeksforgeeks&utm_medium=article&utm_campaign=gfg_article_dsa_content_bottom)** at a student-friendly price and become industry ready.