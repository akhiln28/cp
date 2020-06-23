#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <vector>
#define max_n 100001
using namespace std;
/*
Find the subsequence whose absolute consequtive difference is as maximum as possible.
among multiple ones print the one with the least length. 

 */

int arr[max_n];

int main() {
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        bool flag = arr[0] < arr[1];
        list<int> lt;
        lt.push_back(arr[0]);
        lt.push_back(arr[1]);
        for (int i = 2; i < n; i++)
        {
            if (flag == true && arr[i] > lt.back())
            {
                lt.pop_back();lt.push_back(arr[i]);
            }
            else if (flag == true && arr[i] < lt.back())
            {
                lt.push_back(arr[i]);
                flag = false;
            }
            else if (flag == false && arr[i] < lt.back())
            {
                lt.pop_back(); lt.push_back(arr[i]);
            }
            else if (flag == false && arr[i] > lt.back())
            {
                lt.push_back(arr[i]);
                flag = true;
            }
        }
        cout << lt.size() << endl;
        for (auto it : lt)
        {
            cout << it << ' ';
        }cout << endl;
    }
    return 0;
}
