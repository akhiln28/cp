/*
    title: segment_tree.cpp
    author: Akhil
    date: 2020-09-18
    time: 13:36:16
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

struct segment_tree
{
    int size;
    vector<long long> sums;
    segment_tree(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        int mid = (lx + rx)/2;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < arr.size()) sums[x] = arr[lx];
            return;
        }
        int mid = (lx + rx)/2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    long long sum(int x, int l, int r, int lx, int rx)
    {
        if (lx >= r || rx <= l) return 0; 
        if (lx >= l && rx <= r) return sums[x];

        int mid = (lx + rx)/2;
        long long s1 = sum(2 * x + 1, l, r, lx, mid);
        long long s2 = sum(2 * x + 2, l, r, mid, rx);
        return s1 + s2; 
    }

    long long sum(int l, int r)
    {
        return sum(0, l, r, 0, size);
    }
};


int main()
{
    int n, m;
    cin >> n >> m;

    segment_tree st(n);

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    st.build(arr); 
    while (m--)
    {
        int op; cin >> op;
        if (op == 1) {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }
    return 0; 
}