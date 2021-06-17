# Minimum operations needed to make all frequencies equal

Created Time: Jan 27, 2021 9:23 AM
Last edited time: May 20, 2021 9:56 AM
Pomos (25 mins): 1
Status: waiting
Tags: microsoft

You are given a string containing only lowercase alphabets. In one operation you can change an alphabet to any other alphabet. Find the minimum number of operations you need to perform to make the frequencies of all the alphabets equal. (when frequency of an alphabet reaches zero it is not considered). 

---

Initial thoughts:

1. sort the alphabets based on their frequencies. 
2. now we have to remove a subset of alphabets and make the frequencies of all the remaining alphabets equal.