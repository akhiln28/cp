#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool isPossible(int n, int v)
{
    int k = n/v;
    // cout << k << " " << n << " " << v << endl;
    return n/k == v;
}

void possibleValues(vector<int> &values, int n)
{
    values.push_back(n);
    int k = 2;
    
    while(true)
    {
        int value = n/k;
        if(values[values.size() - 1] != value)
            values.push_back(value);
        else break;
        k++;
    }

    int cur = values[values.size() - 1];
    for(int i = cur - 1; i >= 1; i--)
    {
        if(isPossible(n, i))
            values.push_back(i);
    }
    if(values[values.size() - 1] != 0) values.push_back(0);
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;   
        vector<int> values;
        possibleValues(values, n);
        cout << values.size() << endl;
        for(int i = values.size() - 1; i >= 0; i--)
        {
            cout << values[i] << " ";
        }cout << endl;
    }
    return 0;
}