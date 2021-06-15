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

/*
    title: 1834_single_threaded_cpu.cpp
    author: Akhil
    date: 2021-04-19
    time: 07:39:51
    ==================================================
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& processes) {
        // same as shortest available job first
        // will have to maintain a priority queue of processes based on the completion time
        // will maintain a timer,
        // each iteration,
        // first I will choose the process from the queue, process it and update the timer
        // and then I will push all the process less than or equal to the timer
        // and go to first
        int n = processes.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> tasks(n);

        for (int i = 0; i < n; i++) tasks[i] = i;

        // sorting based on the starting times -> correct
        sort(tasks.begin(), tasks.end(), [&](int i, int j) {
           return processes[i][0] > processes[j][0];
        });

        for (int i = 0; i < n; i++) cout << tasks[i] << " "; cout << endl;

        // initialising timer to minimum start value -> correct
        long long timer = processes[tasks.back()][0];

        vector<int> ans;
        while (ans.size() < n)
        {
            // push all process less than timer
            while (tasks.size() and processes[tasks.back()][0] <= timer)
            {
                // push the length of the task and its index -> correct
                cout << "pushing tasks " << tasks.back() << endl;
                pq.push({processes[tasks.back()][1], tasks.back()});
                tasks.pop_back();
            }
            // process from queue
            auto p = pq.top(); pq.pop();
            cout << p.second << endl;
            ans.push_back(p.second);
            timer += p.first;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> processes{{100, 100}, {10000000, 10000000}};
    Solution obj;
    auto ret = obj.getOrder(processes);
    for (auto e : ret) cout << e << " "; cout << endl;
    return 0;
}