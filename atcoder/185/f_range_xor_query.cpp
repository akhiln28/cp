/*
    title: f_range_xor_query.cpp
    author: Akhil
    date: 2020-12-13
    time: 18:31:43
*/

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
#include <string.h>

using namespace std;

struct segment_tree
{
    int size;
    vector<long long> xors;
    segment_tree(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        xors.assign(2 * size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            xors[x] ^= v;
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
        xors[x] = xors[2 * x + 1] ^ xors[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < arr.size()) xors[x] = arr[lx];
            return;
        }
        int mid = (lx + rx)/2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        xors[x] = xors[2 * x + 1] ^ xors[2 * x + 2];
    }

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    long long sum(int x, int l, int r, int lx, int rx)
    {
        if (lx >= r || rx <= l) return 0; 
        if (lx >= l && rx <= r) return xors[x];

        int mid = (lx + rx)/2;
        long long s1 = sum(2 * x + 1, l, r, lx, mid);
        long long s2 = sum(2 * x + 2, l, r, mid, rx);
        return s1 ^ s2; 
    }

    long long sum(int l, int r)
    {
        return sum(0, l, r, 0, size);
    }
};


int main()
{
    int n, q; cin >> n >> q; 
    vector<int> v(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; 
    }
    segment_tree st(n); 
    st.build(v); 
    while (q--)
    {
        int t, x, y; 
        cin >> t >> x >> y; 
        if (t == 1)
        {
            st.set(x - 1, y);
        }
        else if (t == 2)
        {
            cout << st.sum(x - 1, y) << endl;
        }
    }
    
    return 0;
}