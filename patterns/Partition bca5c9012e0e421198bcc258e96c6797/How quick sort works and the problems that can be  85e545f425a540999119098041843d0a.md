# How quick sort works and the problems that can be solved using partition logic. - LeetCode Discuss

[https://leetcode.com/discuss/general-discussion/1083445/how-quick-sort-works-and-the-problems-that-can-be-solved-using-partition-logic](https://leetcode.com/discuss/general-discussion/1083445/how-quick-sort-works-and-the-problems-that-can-be-solved-using-partition-logic)

Hello Everyone. As we all know there are several categories of problems to practice from trees to stack to dfs, bfs, recursions, dynamic programming and etc. I have come across few interesting set of problems that can be solved and works faster if we know the logic of quick sort.

So, I’m here to share how quick sort works and list of problems that can be solved using quick sort. Hope this helps some learning and I’m open to any suggestion, improvements and corrections.

**How Quick Sort Works?**
 Idea of quick sort is choosing a **pivot** element for every iteration and place it in its actual position.

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/31046c58-5e58-4a1c-96c0-9a0aa25a0cdb_1614325310.7473564.png](31046c58-5e58-4a1c-96c0-9a0aa25a0cdb_1614325310.7473564.png)

After every Iteration, the chosen pivot will be placed at where it **exactly has to be**, the **values lesser than the pivot** will be placed on the **left side** of pivot and **values greater than the pivot** will be placed on the **right side** of the pivot.

The pivot element can be your first element or last element or any random element based on where you are implementing your quick sort.

Here, we are going to choose the last element in an array as our Pivot.

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/28aa325d-d315-4a6f-b36c-c8b4042a3be6_1614325410.031191.png](28aa325d-d315-4a6f-b36c-c8b4042a3be6_1614325410.031191.png)

Consider the above example, first we are choosing the **pivot as 10**, the last element in array. After the first iteration, elements less than 10 will be placed first and elements greater than 10 will be placed later, and 10 come and sit in its actual position.

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/ed4e2102-07e2-41d8-b701-20789113df62_1614325458.559234.png](ed4e2102-07e2-41d8-b701-20789113df62_1614325458.559234.png)

The above representation is just for a better understanding of how pivot will be placed. But actually, **it swaps with the element present in its actual position**. In second iteration, Pivot is 15. Now numbers less than 15 are placed before 15 and numbers greater than 15 are placed after 15. And 15 occupy its actual position.

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/29f92ef7-9919-4f27-96ff-d3982b2d29c4_1614325526.2434015.png](29f92ef7-9919-4f27-96ff-d3982b2d29c4_1614325526.2434015.png)

These steps will be repeated till array gets completely sorted.

Quick sort is said to be the **fastest** out of all sorting techniques because it is based on **divide and conquer**. We actually divide our array based on the pivot element, further divide and sort them till we get our result.

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/a76a27d5-5773-4e15-8179-e8c1528e1063_1614384002.5261338.png](a76a27d5-5773-4e15-8179-e8c1528e1063_1614384002.5261338.png)

**Implementation:**

```
int partition(int[] arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
      if (arr[j] <= pivot) {
        i++;
        swap(arr[i],arr[j]);
      }
	  }
	swap(arr[i+1],pivot);
    }

```

1. We first consider our last element as pivot “pivot = arr[right]”
2. Have two pointers i and j. **Job of pointer i is to remember the place where numbers less than the pivot ends**. j is there to scan the array.
3. If we find any number less than pivot, we move that in the i range.
4. Finally, once we shifted all numbers less that pivot to one side, and numbers greater than pivot to other side, we **swap pivot to its exact position** (i.e, exactly between numbers less than pivot and greater than pivot).

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/d4bbf793-091a-4fe2-9396-04f9487b6e31_1614325729.2622538.png](d4bbf793-091a-4fe2-9396-04f9487b6e31_1614325729.2622538.png)

In the above example, we considered 10 as our pivot. After first iteration, 10 moved its actual position. And now, the pivot is 15 (i.e. last element of array), and the iteration continues till the array get sorted.

As I said quick sort works based on divide and conquer, we first call our partition method to place our pivot element at its position, once placed, we divide the array till pivot **“quicksort(arr, left, pivotFinalRestingPosition - 1)”** and after pivot **“quicksort(arr, pivotFinalRestingPosition + 1, right)”** to sort them separately.

```
  private void quicksort(int[] arr, int left, int right) {
    if (left < right) {
      int pivotFinalRestingPosition = partition(arr, left, right);
      quicksort(arr, left, pivotFinalRestingPosition - 1);
      quicksort(arr, pivotFinalRestingPosition + 1, right);
    }
  }

```

Now we know how quick sort works. Let’s now dive into few problems that can be solved with the help of quick sort.

**Problem Statement:** Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Solution:** As we know in a sorted array, the kth largest element will be at the position n-k. We can approach the same problem by sorting the array and returning the value at position n-k. Or implement a minheap. In both the cases, we have to iterate through the array completely to reach our solution.

As we discussed, in quick sort, we are going to select a Pivot and after every iteration, Pivot will be placed in its actual position. Our Partition method is going to return the position of the pivot after placing it in its actual position. If the position of pivot is going to be n-k, then our code returns the value at that position and loop terminates.

```
int finalIndex = partition(nums, left, right);
      if (finalIndex == n - k) {
        return nums[finalIndex];
      }

```

One more advantage of using quick sort here is, once we place the pivot, we know the values after pivot are going to be greater than pivot and values before the index of pivot are going to be less than pivot. So, if the position of pivot>n-k, we consider sorting only the first half of the array (i.e. before pivot) and leave the other half (i.e. after pivot). Or if position of pivot<n-k, we can consider sorting only the second half and leave the first half.

```
  int finalIndex = partition(nums, left, right);
      if (finalIndex == n - k) {
        return nums[finalIndex];
      } else if (finalIndex > n - k) {
        right = finalIndex - 1;
      } else {
        left = finalIndex + 1;
      }

```

For every iteration, the **Time takes to find the Kth largest element reduces by half as we reduce the size of array to half everytime.**

There is a drawback in this. That is **what if we choose a bad pivot?**

Consider the array [9,8,7,6,5,4,3,2,1]. If we choose ‘1’ as our pivot, and we have to return 8th largest element. In this case 1 is the least value, array is going to be almost of size n for every iteration.

To avoid that, we are going to choose a random number from our array as our pivot. It reduces the chance of choosing a bad pivot every time.

**Complete Code:**

```

class Solution {
    public int findKthLargest(int[] nums, int k) {
    int n = nums.length;
    int left = 0;
    int right = n - 1;

    Random rand = new Random(0);

    while (left <= right) {
      int choosenIndex = rand.nextInt(right - left + 1) + left;

      int finalIndex = partition(nums, left, right, choosenIndex);
      if (finalIndex == n - k) {
        return nums[finalIndex];
      } else if (finalIndex > n - k) {
        right = finalIndex - 1;
      } else {
        left = finalIndex + 1;
      }
    }

    return -1;
  }

  private int partition(int[] arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    int lesserIndex = left;
    swap(arr, pivotIndex, right);

    for (int i = left; i < right; i++) {
      if (arr[i] < pivotValue) {
        swap(arr, i, lesserIndex);
        lesserIndex++;
      }
    }

    swap(arr, right, lesserIndex);

    return lesserIndex;
  }

  private void swap(int[] arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
  }
}

```

The same approach can be used for **“Kth smallest element in an array”** by looking for pivot’s position as k.

**2. [Move Zeros:](https://leetcode.com/problems/move-zeroes/)**

**Problem Statement:**
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

**Solution:** The idea here is to use 0 as pivot and make one pass of partition process. Every time it encounters the non-pivot element, it swaps with the pivot (i.e. 0).

```
class Solution {
    public void moveZeroes(int[] nums) {
    int j = 0;
    for (int i = 0; i < nums.length; i++)
    {
        if (nums[i] != 0) 
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }
    }
}

```

![How%20quick%20sort%20works%20and%20the%20problems%20that%20can%20be%20%2085e545f425a540999119098041843d0a/e01cf200-688e-4a9c-9246-6115152d6b9a_1614326378.5300426.png](e01cf200-688e-4a9c-9246-6115152d6b9a_1614326378.5300426.png)

**Similar Problems:2a) Sort Binary arrayProblem statement:** Sort the array contains only 0s and 1s. Where all 0s come first followed by all 1s.

**Solution:** Idea is to have 1 as our pivot. In one pass all 0s (technically numbers less than pivot) will be arranged before 1s.

**2b) Arrange negative and positive numbersProblem statement:** Given an array with negative and positive integers, arrange all negative numbers first followed by positive numbers.

**Solution:** Assign our pivot to 0, In first pass all elements less than 0 (i.e. negative integers) will group together in front followed by the positive numbers.

**Problem statement:** Given an unsorted integer array nums, find the smallest missing positive integer.

**Solution:** Though there are lot of ways in solving this problem, we want to do it in O(n) time and constant space.

Here, the array has both negative and positive integers. But we want to check only the positive numbers. We can set out pivot value as 0, and sort based on numbers greater than 0 to left of pivot and numbers less than 0 to the right side.

So that the positive numbers will be grouped to 0 to j th index. We can ignore rest of the array.

```
int partition(int[] A){
    int j=-1;
    for(int i=0;i<A.length;i++){
        if(A[i]>0){
            j++;
            swap(A[i],A[j]);
        }
    }
    return j;
}

```

Here, j is actually the index of where positive integers ends after partition. We can scan our array from 0 to j and find the result.

Since the output possibly can be from 1 to j+1, we assign each value’s index to negative number. And scan array again, if you find a positive integer at index i (1<=i<=j), then that i is the first missing positive number.

```
int firstMissingPositive(int[] A) {
    var j = Partition(A);
    for(i = 0 to j){
        if(A[i]<=j)
            A[A[i]-1]=-A[A[i]-1];
    }
    for(i = 0 to j){
        if(A[i]>0){
            return i+1;
        }
    }
    return j+1;
}

```

**4. [Sort Array by Parity](https://leetcode.com/problems/sort-array-by-parity/)Problem Statement:** Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

**Solution:** Here set the pivot as even number (i.e. check if the number is even or odd). For every odd number it encounters, it swaps with the even number.

```
class Solution {
    public int[] sortArrayByParity(int[] A) {
            int j=-1;
    for(int i=0;i<A.length;i++){
        if(A[i]%2==0){
            j++;
            Swap(A[i],A[j]);
        }
    }
    return A;

    }
}

```

**5. [Sort colors](https://leetcode.com/problems/sort-colors/):Problem statement:** Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

**Solution:** Here set our pivot to 1, after one pass values less than pivot (i.e. 0s) will be moved to front, and values greater than 1 (i.e. 2s) will be moved after 1s.

Happy Learning!!! Don’t forget to upvote if you like this. Thank you!