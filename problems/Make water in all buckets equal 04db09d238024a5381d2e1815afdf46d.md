# Make water in all buckets equal

Created Time: Dec 19, 2020 9:39 PM
Last edited time: Feb 22, 2021 9:23 PM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242
Points: 1600
Pomos (25 mins): 1
Status: ok
Tags: de shaw, new, unproven

Given an array of positive integers, each of which represent the number of litres of water in that particular bucket,

1. we have to make the litres of water in every bucket equal.
2. We are allowed to do two types of operations any number of times:
3. We can altogether remove a bucket from the sequence
4. We can remove some water from a bucket

We have to tell what is the minimum number of litres removed to make all buckets have the same amount of water.

Eg.

Input:

1 2 3

Output:

2

Explanation:

We remove bucket 1 and remove 1 liter from Bucket 3, so total water removed is 2 liter

(the amount of water in the bucket removed gets added to the total water removed).

---

I found an interesting answer [here](https://www.careercup.com/forumpost?id=5763807620628480)

> *The value final water in each bucket must among one of them. Otherwise you can reduce the answer even further if you have considered the*

I thought I could solve it using binary search. But it is not possible. The below program shows that binary search can't pin point the final value in the buckets for minimum. I think it is definitely dp. I would have been little easier if I have known the constraints. 

```cpp
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

#define max_n 100

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % max_n;
    }
    
    int mine = *min_element(v.begin(), v.end());
    int maxe = *max_element(v.begin(), v.end());
    for (int i = mine; i <= maxe; i++)
    {
        int sum = 0; 
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] >= i) sum += v[j] - i; 
            else sum += v[j]; 
        }
        cout << sum << " "; 
    }cout << endl;
    
    return 0;
}
```