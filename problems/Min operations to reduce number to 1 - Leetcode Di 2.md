---
Created Time: Jan 09, 2021 11:53 AM
Do Date: Jan 09, 2021
Last edited time: May 11, 2021 9:01 AM
Points: 1600
Source: https://leetcode.com/discuss/interview-question/538568/google-onsite-min-operations-to-reduce-number-to-1
Status: done
Tags: google, new
---

# Min operations to reduce number to 1 - Leetcode Discuss

Given a positive integer `n` and 3 operations on `n`:
1. n - 1
2. n / 2 (if n is even)
3. n / 3 (if n % 3 == 0)
Find the minimum number of above operations to reduce `n` to 1.
**Example 1:**
```
Input: n = 9
Output: 2
Explanation:
Step 1: 9 / 3 = 3
Step 2: 3 / 3 = 1
```
**Example 2:**
```
Input: n = 8
Output: 3
Explanation:
Step 1: 8 / 2 = 4
Step 2: 4 / 2 = 2
Step 3: 2 - 1 = 1
```
**Example 3:**
```
Input: n = 28
Output: 4
```
**Constrains:** 
`n<=10^18`
---
An awesome method I found in the leetcode discuss.
```cpp
layer = []
def min_ops(target: int) -> int:
    if target <= 1:
        return 0
    
    visited = {target}
    # layer = [target]
    global layer
    layer.append(target)
    ops = 0
    
    while True:
        next_layer = []
        
        for num in layer:
            if num == 1:
                return ops
                
            if num - 1 not in visited:
                next_layer.append(num - 1)
                visited.add(num - 1)
            if not num % 2 and num // 2 not in visited:
                next_layer.append(num // 2)
                visited.add(num // 2)
            if not num % 3 and num // 3 not in visited:
                next_layer.append(num // 3)
                visited.add(num // 3)
            
        layer = next_layer
        ops += 1
    
    return 0
input = int(input())
print(min_ops(input))
print("layer size: ", len(layer))
```
The standard dp does not work in this case. So, I used memorization. Works like a charm. 
```cpp
#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
unordered_map<long long, long long> mp; 
long long count_ops(long long n)
{
	if (n == 1) return 0; 
	if (mp.find(n) != mp.end()) return mp[n]; 
	long long ans = 1e18; 
	if (n % 3 == 0 and n % 2 == 0) 
		ans = min(1 + count_ops(n/2), 1 + count_ops(n/3)); 
	else if (n % 3 == 0) 
		ans = 1 + count_ops(n/3); 
	else if (n % 2 == 0) 
		ans = 1 + count_ops(n/2); 
	else 
		ans = 1 + count_ops(n - 1); 
	mp[n] = ans; 
	return ans;  
}
int main()
{
	long long n; cin >> n; 
	mp.clear(); 
	auto start = high_resolution_clock::now(); 
	cout << count_ops(n) << endl;
	auto end = high_resolution_clock::now(); 
	cout << "time taken: " << duration_cast<milliseconds>(end - start).count() << endl;
	cout << "map size: " << mp.size() << endl;
	cout << "log2: " << log(n)/log(2.0) << endl;
	cout << "log3: " << log(n)/log(3.0) << endl;
  return 0;
}
```
Patterns: [Dp](Dp.md)[Number%20Theory](Number%20Theory.md)[Linear%20DP](Linear%20DP.md)