#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isInBetween(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    int min = (A.first > C.first) ? C.first : A.first;
    int max = (A.first > C.first) ? A.first : C.first;

    bool flagx = B.first >= min && B.first <= max;

    min = (A.second > C.second) ? C.second : A.second;
    max = (A.second > C.second) ? A.second : C.second;
    
    bool flagy = B.second >= min && B.second <= max;
    return flagx && flagy;
}

int main()
{
    int n;
    pair<int, int> s;
    cin >> n >> s.first >> s.second;
    vector<pair<int, int>> points(n);

    for(int i = 0;i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    int max_shawarma = 0;
    vector<int> shawarma_counts(n, 0);
    // now checking houses one by one
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(isInBetween(s, points[i], points[j]))
                shawarma_counts[i]++;
        }
        if(max_shawarma < shawarma_counts[i]) 
            max_shawarma = shawarma_counts[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(max_shawarma == shawarma_counts[i])
        {
            cout << max_shawarma << endl;
            cout << points[i].first << " " << points[i].second << endl;
            return 0;
        }
    }
    return 0;
}
