# Jobs and Processor

Created Time: Apr 02, 2021 8:07 AM
Do Date: Apr 02, 2021
Last edited time: Apr 02, 2021 8:12 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Intervals-ebd124f2083d4f999c01b25e664d9e01
Source: https://leetcode.com/discuss/interview-question/1138514/google-bangalore-onsite-backed-engineer-rejected
Status: ok

Given a processor it should pick up a job from set of available jobs and execute the job which has the least running time duration . Jobs are given in the format

```
[jobId, jobStartTime, durationOfThejob]
```

Job ID is always unique and there could be multiple jobs starting in the same time

i.e if I've jobs

[1,3,2],[2,3,8],[3,4,1]

---

```python
sort available_jobs on a vector based on starting time
priority_queue<job> pq
time = time of the first job in available jobs
while (available_jobs is not empty): 
	add all the jobs <= time from the available_jobs (also removing from available jobs)
	pick the front of the priority queue
```