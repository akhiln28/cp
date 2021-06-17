# Bit Sum

Created Time: Dec 10, 2020 8:12 PM
Do Date: Dec 10, 2020
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Points: 1500
Problem Statement: Given an array of n integers, you must perform k operations. In each operation Choose any number on the list. In the binary representation of the number, choose a bit that is 0 and make it 1.make any 0 → 1. Find the least possible sum after k such operations?
Source: https://binarysearch.com/problems/Bit-Sum
Status: done
Tags: pending

Given an array of n integers, you must perform k operations. In each operation Choose any number on the list. In the binary representation of the number, choose a bit that is 0 and make it 1.make any 0 → 1. Find the least possible sum after k such operations?

---

We need to chose an element which has zero closest to least significant digit, lets call this postion priority. We store the elements in the set based on the priority. 

We perform k such operations on the element at the start of the set and re-insert after we are done.   

```cpp
struct comp{
    bool operator()(const int &a, const int &b) const {
        int x = 0, y = 0; 
        int a1 = a, b1 = b; 
        while (a1 % 2) a1 /= 2, x++; 
        while (b1 % 2) b1 /= 2, y++; 
        return x < y; 
    }
};
int solve(vector<int>& nums, int k) {
    int mod = 1e9 + 7; 
    multiset<int, comp> s; 
    for (auto e : nums) s.insert(e); 
    long long ans = accumulate(nums.begin(), nums.end(), 0LL); 
    for (int i = 0; i < k; i++)
    {
        auto it = s.begin(); 
        int n = *it;
        int x = 0; 
        while (n % 2) x++, n /= 2; 
        
        ans = (ans + (1 << x)) % mod; 
        int n1 = *it + (1 << x); 
        s.erase(it);
        s.insert(n1); 
    }
    return ans; 
}
```

### Complexity

Time: O(n logn)