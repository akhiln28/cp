---
Created Time: Dec 20, 2020 7:18 PM
Do Date: Feb 10, 2021
Last edited time: May 11, 2021 9:00 AM
Points: 1600
Pomos (25 mins): 1
Relates: Longest%20Subarray%20with%20Ones%20after%20Replacement%20(hard%2040338106ed58470a9cda65b842731927.md
Source: https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR
Status: ok
---

# Longest Substring with Same Letters after Replacement

Given a string with lowercase letters only, if you are allowed to **replace no more than ‘k’ letters** with any letter, find the **length of the longest substring having the same letters** after replacement.
**Example 1:**
```
Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
```
**Example 2:**
```
Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
```
**Example 3:**
```
Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
```
Standard sliding window question. 
[educative.io](http://educative.io) code
```cpp
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
class CharacterReplacement {
public:
  static int findLength(const string &str, int k) {
    int windowStart = 0, maxLength = 0, maxRepeatLetterCount = 0;
    unordered_map<char, int> letterFrequencyMap;
    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      letterFrequencyMap[rightChar]++;
      maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[rightChar]);
      // current window size is from windowStart to windowEnd, overall we have a letter which is
      // repeating 'maxRepeatLetterCount' times, this means we can have a window which has one
      // letter repeating 'maxRepeatLetterCount' times and the remaining letters we should replace.
      // if the remaining letters are more than 'k', it is the time to shrink the window as we
      // are not allowed to replace more than 'k' letters
      if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k) {
        char leftChar = str[windowStart];
        letterFrequencyMap[leftChar]--;
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};
int main(int argc, char *argv[]) {
  cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
  cout << CharacterReplacement::findLength("abbcb", 1) << endl;
  cout << CharacterReplacement::findLength("abccde", 1) << endl;
}
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Sliding%20Window](Sliding%20Window.md)