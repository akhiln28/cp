---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Mar 09, 2021
Last edited time: Mar 09, 2021 8:35 AM
Points: 1600
Pomos (25 mins): 2
Status: done
---

# Asteroid Collision

We are given an array `asteroids` of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
**Example 1:**
```
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```
**Example 2:**
```
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```
**Example 3:**
```
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```
**Example 4:**
```
Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
```
**Constraints:**
- `2 <= asteroids.length <= 104`
- `1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`
---
```java
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> row; 
        for (int i = 0; i < asteroids.size(); i++)
        {
            // when asteroid[i] is positive just push back
            if (row.size() == 0 or asteroids[i] > 0) row.push_back(asteroids[i]); 
            // asteroid[i] is negative 
            else if (asteroids[i] < 0 and row.back() < 0) row.push_back(asteroids[i]); 
            else 
            {
                while (row.size() and row.back() > 0 and abs(asteroids[i]) > row.back())
                    row.pop_back();
                if (row.size() and row.back() == abs(asteroids[i])) row.pop_back(); 
                else if (row.size() == 0 or row.back() < 0) row.push_back(asteroids[i]); 
            }
        }
        return row; 
        
    }
};
```
Patterns: [Array](Array.md)[Stack](Stack.md)