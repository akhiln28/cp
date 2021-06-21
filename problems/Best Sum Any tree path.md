---
Created Time: Jan 23, 2021 2:29 PM
Do Date: Jan 23, 2021
Last edited time: Mar 01, 2021 8:48 AM
Points: 1500
Pomos (25 mins): 1
Status: done
---

# Best Sum Any tree path

![Best%20Sum%20Any%20tree%20path%2060618483423243e89d6081fe5c013b4f/Untitled.png](Best%20Sum%20Any%20tree%20path%2060618483423243e89d6081fe5c013b4f/Untitled.png)
```cpp
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>
using namespace std;
int final_ans;
int dfs(vector<vector<int>> &graph, int i, vector<int> &val)
{
	int ans = val[i];
	vector<int> nbs;
	for (auto j : graph[i])
	{
		nbs.push_back(dfs(graph, j, val));
	}
	sort(nbs.begin(), nbs.end());
	// add top two elements if they are positive
	int largest = (nbs.size()) ? max(0, nbs.back()) : 0;
	int next_largest = (nbs.size() > 1) ? max(0, nbs[nbs.size() - 2]) : 0;
	ans += largest;
	final_ans = max({
		final_ans,
		ans,
		val[i] + largest + next_largest
	});
	return ans;
}
int main()
{
	final_ans = 0;
	int n;
	cin >> n;
	vector<int> val(n), parent(n);
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> parent[i];
	}
	vector<vector<int>> graph(n);
	int root = -1;
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == -1)
			root = i;
		else
			graph[parent[i]].push_back(i);
	}
	dfs(graph, root, val);
	cout << "final_ans: " << final_ans << endl;
	return 0;
}
```
Patterns: [DFS](DFS.md)[Dp](Dp.md)