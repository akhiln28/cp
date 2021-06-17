# CPU Scheduling

Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 20, 2021 9:55 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1700
Problem Statement: given tasks with id, queue time, and duration. at any time cpu chooses task with minimum duration. find the order of the tasks execution.
Status: waiting
Tags: own, simulation

Given tasks with id, queue time, and duration. at any time cpu chooses task with minimum duration. find the order of the tasks execution. (non preemption cpu)

---

```cpp
vector<int> find_order(vector<int> times, vector<int> durations)
{
		int n = times.size();
		vector<int> tasks(n); 
		for (int i = 0; i < n; i++) tasks[i] = i; 
		
		return {};
}
```