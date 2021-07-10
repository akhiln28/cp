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
    title: Efficient Shipping.cpp
    author: Akhil
    date: 2021-07-09
    time: 18:28:05
    ==================================================
*/

long getMaxUnits(vector<long> boxes, vector<long> upb, long tsize) {
    int n = boxes.size();
    for (int i = 0; i < n; i++) cout << boxes[i] << " "; cout << endl;
    for (int i = 0; i < n; i++) cout << upb[i] << " "; cout << endl;
    cout << tsize << endl;
    vector<int> products(n);
    for (int i = 0; i < n; i++) products[i] = i;
    sort(products.begin(), products.end(), [&](int i, int j) {
        return upb[i] > upb[j];
    });
    long ans = 0;
    for (int i = 0; i < n; i++) {
        int prod = products[i];
        long num_boxes = min(tsize, boxes[prod]);
        long value = upb[prod] * (num_boxes);
        ans += value;
        tsize -= num_boxes;
    }
    return ans;
}
int main()
{
    vector<long> boxes{3, 1, 6};
    vector<long> upb{2, 7, 4};
    long tsize = 6;
    cout << getMaxUnits(boxes, upb, tsize) << endl;
    return 0;
}