---
Created Time: Mar 20, 2021 8:42 AM
Do Date: Mar 22, 2021
Last edited time: Mar 22, 2021 8:02 AM
Points: 1500
Pomos (25 mins): 1
Source: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414bfb
Status: done
---

# Kick_Start - Kick Start

### Problem
Ksenia is very fond of reading so she kicks off each day by reading a fragment from her favourite book before starting with the rest of her morning routine. A fragment is simply a [substring](https://en.wikipedia.org/wiki/Substring) of the text. Ksenia is somewhat superstitious and believes that her day will be lucky if the fragment she reads starts with the string KICK, then goes on with 0 or more characters, and eventually ends with the string START, even if the overall fragment makes little sense.
Given the text of the book, count the number of different lucky fragments that Ksenia can read before the book gets old and she needs to buy another one. Two fragments are considered to be different if they start or end at different positions in the text, even if the fragments read the same. Also note that different lucky fragments may overlap.
### Input
The first line of the input gives the number of test cases **T**. **T** lines follow, each containing a single string **S** consisting of upper case English letters only.
### Output
For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the number of different lucky fragments in the text of this test case.
### Limits
Memory limit: 1 GB.
 1 ≤ **T** ≤ 100.**S** consists of upper-case English letters only.
### Test Set 1
Time limit: 20 seconds.
 1 ≤ |**S**| ≤ 1000.
### Test Set 2
Time limit: 40 seconds.
 1 ≤ |**S**| ≤ 105.
![Kick_Start%20-%20Kick%20Start%203ccb1a261f3c4404b86f364296fe2a53/Untitled.png](Kick_Start%20-%20Kick%20Start%203ccb1a261f3c4404b86f364296fe2a53/Untitled.png)
Patterns: [Cumulative](Cumulative.md)[String](String)