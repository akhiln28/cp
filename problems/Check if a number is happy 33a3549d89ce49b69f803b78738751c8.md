# Check if a number is happy

Created Time: Jan 10, 2021 1:54 PM
Do Date: Jan 10, 2021
Last edited time: May 11, 2021 9:05 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98, https://www.notion.so/Slow-Pointer-ce6e427e91d34fb5999dc3b1532303f6
Points: 1200
Relates: Complexity%20of%20Checking%20Happy%20Number%209ef4fed516874b6eb86ef7889d007f00.md
Status: done

Given an integer n. Check if the number is happy or not? (A number is happy if after some finite operations it is converted to 1, an operation is as follows `n = sum of squares of its digits`)

---

we can solve this using hashing or slow pointer method. 

```cpp
class Solution {
public:
    int sum_of_squares(int n)
    {
        int ans = 0; 
        while (n)
        {
            int d = n % 10;
            ans += d * d; 
            n /= 10; 
        }
        return ans; 
    }
    bool isHappy(int n) {
        unordered_set<int> se; 
        while (true)
        {
            if (n == 1) return true; 
            n = sum_of_squares(n); 
            if (se.find(n) != se.end()) return false; 
            else se.insert(n); 
        }
        return false; 
    }
};
```