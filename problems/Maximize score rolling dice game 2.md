---
Created Time: Dec 07, 2020 7:58 PM
Do Date: Dec 07, 2020
Last edited time: May 19, 2021 10:00 PM
Points: 1500
Problem Statement: You play a dice game. You have to maximize the score. First time you can roll a dice, you can stick with the score on the dice or you can go for second round and the score will be the one appearing on the second round. What is the best strategy to maximize the expected score?
Status: ok
Tags: interview, mathisys
---

# Maximize score rolling dice game

The expected score in the second round is 3.5. So, if you get 1, 2 or 3 in the first round you go for the second round. 
With the above strategy we will have the expected score 
$1/6 \times (4 + 5 + 6) + 3/6 \times (3.5) = 4.25$
Instead of 2 rounds, if we have n rounds, what is the expected probability?
- As n increases indefinitely, what will happen to the expected probability?
    It will converge to 6.
Patterns: 