---
Created Time: Jan 15, 2021 9:28 PM
Do Date: Jan 15, 2021
Last edited time: Mar 01, 2021 3:43 PM
Points: 1300
Source: https://binarysearch.com/problems/Rocketship-Rescue
Status: done
---

# Rocketship Rescue | binarysearch

You are given a list of integers `weights` representing peoples' weights and an integer `limit` representing the weight limit of one rocket ship.
Each rocketship can take at **most two people**.
Return the minimum number of rocket ships it would take to rescue everyone to Mars.
**Constraints**
- `n ≤ 100,000` where `n` is the length of `weights`
- `max(weights) ≤ limit`
****Example 1****
****Input****
```cpp
weights = [200, 300, 200]
limit = 400
```
****Output****
`2`
### **Explanation**
It would take one rocket ship to take the two people whose weights are `200`, and another to take the person whose weight is `300`.
---
```cpp
int solve(vector<int>& weights, int limit) {
    int n = weights.size(); 
    sort(weights.begin(), weights.end());
    int rockets = 0, left = 0, right = n - 1; 
    while (left <= right)
    {
        if (weights[right] + weights[left] <= limit) 
        {
            rockets++; 
            right--;
            left++;
        }
        else
        {
            rockets++;
            right--;
        }
    }
    return rockets; 
}
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)