# Print Derangements

Created Time: Jan 09, 2021 1:19 PM
Do Date: Mar 09, 2021
Last edited time: May 11, 2021 9:05 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Backtracking-90d58a7ffa85438e86ce346981bf35b5
Points: 1600
Pomos (25 mins): 1
Related To: Permutations%20-%20LeetCode%204d488cfcee04438a872631a4229a572a.md
Status: done
Tags: own

[Permutations/Derangements](https://rosettacode.org/wiki/Permutations/Derangements#C.23)

```cpp
#include <iostream>
#include <vector>
using namespace std;

// will fill idx and recursively call idx + 1
void recur(int idx, vector<int>& nums, vector<bool>& used)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i] == false && i != idx)
        {
            nums[idx] = i; 
            used[i] = true; 
            if (idx + 1 < nums.size()) recur(idx + 1, nums, used);
            else 
            {
                for (int j = 0; j < nums.size(); j++) 
										cout << nums[j] << " "; 
								cout << endl;
            }
            used[i] = false; 
        }
    }
}

void print_derangments(int n)
{
    vector<int> nums(n); 
    vector<bool> used(n);
    recur(0, nums, used);
}

int main()
{
    print_derangments(4);
    return 0;
}
```