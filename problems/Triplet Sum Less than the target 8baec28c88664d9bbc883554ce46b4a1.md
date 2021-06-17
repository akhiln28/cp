# Triplet Sum Less than the target

Created Time: Dec 22, 2020 9:34 AM
Last edited time: May 20, 2021 9:56 AM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74
Status: waiting

Given an array `arr` of unsorted numbers and a target sum, **count all triplets** in it such that **`arr[i] + arr[j] + arr[k] < target`** where `i`, `j`, and `k` are three different indices. Write a function to return the count of such triplets.

**Example 1:**

```
Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

```

**Example 2:**

```
Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
```

---

```cpp
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < arr.size() - 2; i++) {
      count += searchPair(arr, target - arr[i], i);
    }
    return count;
  }

 private:
  static int searchPair(const vector<int> &arr, int targetSum, int first) {
    int count = 0;
    int left = first + 1, right = arr.size() - 1;
    while (left < right) {
      if (arr[left] + arr[right] < targetSum) {  // found the triplet
        // since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
        // left and right to get a sum less than the target sum
        count += right - left;
        left++;
      } else {
        right--;  // we need a pair with a smaller sum
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-1, 0, 2, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 3) << endl;
  vec = {-1, 4, 2, 1, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 5) << endl;
}
```