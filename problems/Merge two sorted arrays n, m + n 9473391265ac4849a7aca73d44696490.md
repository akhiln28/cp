# Merge two sorted arrays n, m + n

Created Time: Dec 27, 2020 7:41 PM
Do Date: Dec 27, 2020
Last edited time: Mar 01, 2021 3:43 PM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1200
Problem Statement: Given two arrays of size n and m + n (contains only m elements). Merge them into one without any extra space. 
Status: done

Given two arrays of size n and m + n (contains only m elements). Merge them into one without any extra space. 

---

First move the elements in the second array to right most. 

```cpp
vector<int> v1(n), v2(m + n); 

int i = 0, j = n, idx = 0; 
while (i < n and j < m + n)
	if (v1[i] < v2[j]) v2[idx] = v1[i], i++; 
	else v2[idx] = v2[j], j++; 
	idx++;

while (i < n)
	v2[idx] = v1[i], i++, idx++; 

while (j < m + n)
	v2[idx] = v[j], j++, idx++; 

for (int i = 0; i < n + m; i++) cout << v2[i] << " "; cout << endl; 
```