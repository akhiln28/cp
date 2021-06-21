---
Created Time: Jan 24, 2021 8:09 AM
Last edited time: May 20, 2021 9:56 AM
Source: https://www.geeksforgeeks.org/reduce-the-string-by-removing-k-consecutive-identical-characters/
Status: waiting
Tags: goldman sachs
---

# Reduce the string by removing K consecutive identical characters - GeeksforGeeks

Given a string ‘str’ and an integer ‘k’, the task is to reduce the string by applying the following operation:
> Choose a group of ‘k’ consecutive identical characters and remove them. The operation can be performed any number of times until it is no longer possible.
Finally, print the reduced string.
**Examples:**
> Input: k = 2, str = “geeksforgeeks” Output: gksforgks After the removal of 2 consecutive “e” twice, the string will get reduced to “gksforgks”. Input: k = 3, str = “qddxxxd” Output: q Removal of “xxx” gives “qddd”. Again, removal of “ddd” gives the final string “q”
**Approach:** This problem can be solved using the data structure, [Stack](https://www.geeksforgeeks.org/stack-data-structure/).
- Maintain a stack of the characters while iterating through them one by one.
- When there are ‘k’ identical characters at the top of the stack, pop them out of the stack.
- To implement this, every element of the stack will be a pair of character and it’s consecutive frequency. If the character to be pushed is different from the character which is currently at the top of the stack then it’s frequency will be set to “1”.
- Else, if the character is identical to the character at the top of the stack then it’s frequency will be one greater than the frequency of the element at the top of the stack.
- In the end, the characters which are left in the stack will form the resultant string.
Below is the implementation of the above approach:
```
// Java implementation of the approach 
```
```
import
```
```
java.util.*; 
```
```
class
```
```
GFG { 
```
```
// Function that returns 
```
```
// the reduced string after 
```
```
// performing given operation 
```
```
static
```
```
String remove_k_characters(String st1, 
```
```
int
```
```
n, 
```
```
int
```
```
k) 
```
```
{ 
```
```
// Stack to store the character 
```
```
Stack<Entity> st = 
```
```
new
```
```
Stack<Entity>(); 
```
```
int
```
```
i = 
```
```
0
```
```
; 
```
```
for
```
```
(i = 
```
```
0
```
```
; i < n; i++) { 
```
```
// the current character 
```
```
char
```
```
x = st1.charAt(i); 
```
```
// if the stack is not empty 
```
```
// and the frequency of the element 
```
```
// at the top of the stack is = k 
```
```
// then pop k elements 
```
```
if
```
```
(st.size() > 
```
```
0
```
```
&& st.peek().frequency == k) { 
```
```
// stores the character at 
```
```
// the top of the stack 
```
```
char
```
```
curr = st.peek().character; 
```
```
// while the character 
```
```
// at the top of the stack is curr 
```
```
// pop the character from the stack 
```
```
while
```
```
(st.size() > 
```
```
0
```
```
&& st.peek().character == curr) 
```
```
st.pop(); 
```
```
} 
```
```
// if the stack is not empty 
```
```
// and the top element of the 
```
```
// stack is = x, 
```
```
if
```
```
(st.size() > 
```
```
0
```
```
&& st.peek().character == x) { 
```
```
// increase it's frequency and 
```
```
// push it to the stack 
```
```
Entity new_top = 
```
```
new
```
```
Entity(x, st.peek().frequency + 
```
```
1
```
```
); 
```
```
st.push(new_top); 
```
```
} 
```
```
// if the current element is 
```
```
// not equal to the character 
```
```
// at the top of the stack 
```
```
else
```
```
{ 
```
```
Entity new_top = 
```
```
new
```
```
Entity(x, 
```
```
1
```
```
); 
```
```
st.push(new_top); 
```
```
} 
```
```
} 
```
```
// if the last pushed character 
```
```
// has k frequency, then pop the 
```
```
// top k characters. 
```
```
if
```
```
(st.size() > 
```
```
0
```
```
&& st.peek().frequency == k) { 
```
```
// get the character 
```
```
// at the top of the stack 
```
```
char
```
```
curr = st.peek().character; 
```
```
// while the character 
```
```
// at the top of the stack is 
```
```
// curr, pop it from the stack 
```
```
while
```
```
(st.size() > 
```
```
0
```
```
&& st.peek().character == curr) 
```
```
st.pop(); 
```
```
} 
```
```
// Stores the string in 
```
```
// reversed fashion from stack 
```
```
String stack_string = 
```
```
""
```
```
; 
```
```
while
```
```
(st.size() > 
```
```
0
```
```
) 
```
```
stack_string += st.pop().character; 
```
```
String reduced_string = 
```
```
""
```
```
; 
```
```
// reverse the stack string 
```
```
for
```
```
(i = stack_string.length() - 
```
```
1
```
```
; i >= 
```
```
0
```
```
; i--) 
```
```
reduced_string += stack_string.charAt(i); 
```
```
return
```
```
reduced_string; 
```
```
} 
```
```
// Driver code 
```
```
public
```
```
static
```
```
void
```
```
main(String[] args) 
```
```
{ 
```
```
int
```
```
k = 
```
```
2
```
```
; 
```
```
String st = 
```
```
"geeksforgeeks"
```
```
; 
```
```
String ans = remove_k_characters(st, st.length(), k); 
```
```
System.out.println(ans); 
```
```
} 
```
```
static
```
```
class
```
```
Entity { 
```
```
char
```
```
character; 
```
```
int
```
```
frequency; 
```
```
Entity(
```
```
char
```
```
p, 
```
```
int
```
```
q) 
```
```
{ 
```
```
character = p; 
```
```
frequency = q; 
```
```
} 
```
```
} 
```
```
} 
```
**Time Complexity** – O(N)
 Each element gets pushed into stack only once.
![Reduce%20the%20string%20by%20removing%20K%20consecutive%20identi%200b50352df36f49f3b01fd83e851305e3/GFG-CP-Article-2.png](Reduce%20the%20string%20by%20removing%20K%20consecutive%20identi%200b50352df36f49f3b01fd83e851305e3/GFG-CP-Article-2.png)
Patterns: 