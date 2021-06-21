---
Created Time: Dec 25, 2020 8:04 PM
Do Date: Dec 25, 2020
Last edited time: Mar 04, 2021 8:12 AM
Points: 1700
Pomos (25 mins): 1
Source: https://practice.geeksforgeeks.org/problems/maximum-intervals-overlap/0#
Status: done
Tags: microsoft, new, nlogn, standard
---

# Find the maximum number of overlaps in intervals

```cpp
// C++ program that print maximum
// number of overlap
// among given ranges
#include <bits/stdc++.h>
using namespace std;
// Function that print maximum
// overlap among ranges
void overlap(vector<pair<int, int> > v)
{
	// variable to store the maximum
	// count
	int ans = 0;
	int count = 0;
	vector<pair<int, char> > data;
	// storing the x and y
	// coordinates in data vector
	for (int i = 0; i < v.size(); i++) {
		// pushing the x coordinate
		data.push_back({ v[i].first, 'x' });
		// pushing the y coordinate
		data.push_back({ v[i].second, 'y' });
	}
	// sorting of ranges
	sort(data.begin(), data.end());
	// Traverse the data vector to
	// count number of overlaps
	for (int i = 0; i < data.size(); i++) {
		// if x occur it means a new range
		// is added so we increase count
		if (data[i].second == 'x')
			count++;
		// if y occur it means a range
		// is ended so we decrease count
		if (data[i].second == 'y')
			count--;
		// updating the value of ans
		// after every traversal
		ans = max(ans, count);
	}
	cout << ans << endl;
}
// Driver code
int main()
{
	vector<pair<int, int> > v
		= { { 1, 2 }, { 2, 4 }, { 3, 6 } };
	overlap(v);
	return 0;
}
```
This is same as the maximum number of workers need to do all the tasks. A worker can only do one task at a time. 
We greedily allocate one worker, when there is an intersection. 
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	//code
	int t; cin >> t;
	while (t--)
	{
	    int n; cin >> n;
	    vector<int> s(n), e(n); 
	    for (int i = 0; i < n; i++) cin >> s[i]; 
	    for (int i = 0; i < n; i++) cin >> e[i]; 
	    
	    sort(s.begin(), s.end());
	    sort(e.begin(), e.end());
	    int j = 0; 
	    int count = 0, time = -1; // count is the number of workers required
	    for (int i = 0; i < n; i++)
	    {
	        if (s[i] > e[j]) j++; // no intersection, assign jth worker to i
	        else count++, time = s[i]; // intersection, assign a new worker to i
	    }
	    cout << count << " " << time << endl;
	}
	return 0;
}
```
The method is similar to the following. 
[http://www.zrzahid.com/maximum-number-of-overlapping-intervals/](http://www.zrzahid.com/maximum-number-of-overlapping-intervals/)
### References:
[Maximum number of overlapping Intervals - GeeksforGeeks](https://www.geeksforgeeks.org/maximum-number-of-overlapping-intervals/)
Patterns: [Cumulative](Cumulative.md)[patterns/Greedy](patterns/Greedy.md)[Intervals](Intervals.md)