#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
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
    title: kickstart_2021A_4.cpp
    author: Akhil
    date: 2021-03-21
    time: 11:09:26
    ==================================================
    Given a matrix which contains some corrupted values (-1) and row xors and column xors. And another matrix B denote the cost to restore each element. Find the minimum total cost to recover the matrix.
    We can find a single missing element using a xor of elements.

    Simulation?
    while (missing)
        for each missing index
            if row or col = 1:
                update
        none of row or col == 1 then update the front of the missing.
    Greedy?
    Dynamic programming?

    2
    3
    A
    1 -1 0 x 1
    0 1 0 x 1
    1 1 1 x 1
    x x x
    0 0 1
    B
    0 1 0
    0 0 0
    0 0 0
    R
    1 1 1
    C
    0 0 1
    2
    -1 -1
    -1 -1
    1 10
    100 1000
    1 0
    0 1

*/
int main()
{
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n;
        cin >> n;
        vector<vector<int>> A(n, vector<int>(n));
        vector<vector<int>> B(n, vector<int>(n));
        vector<int> row_count(n), col_count(n);
        list<array<int, 3>> missing;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> B[i][j];
                if (B[i][j])
                {
                    row_count[i]++;
                    col_count[j]++;
                    missing.push_back({B[i][j], i, j});
                }
            }
        }
        missing.sort();
        vector<int> R(n), C(n), R1(n), C1(n);

        for (int i = 0; i < n; i++)
        {
            cin >> R[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> C[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] != -1) R1[i] ^= A[i][j];
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i][j] != -1) C1[j] ^= A[i][j];
            }
        }
        long long ans = 0;

        while (missing.size())
        {
            bool flag = false;
            auto it = missing.begin();
            while (it != missing.end())
            {
                auto nxt = next(it);
                int r = (*it)[1], c = (*it)[2];
                if (row_count[r] == 1)
                {
                    row_count[r] = 0;
                    A[r][c] = R[r] ^ R1[r];
                    R1[r] = R[r];
                    col_count[c]--;
                }
                else if (col_count[c] == 1)
                {
                    col_count[c] = 0;
                    A[r][c] = C[c] ^ C1[c];
                    C1[c] = C[c];
                    row_count[r]--;
                }
                if (A[r][c] != -1)
                {
                    flag = true;
                    missing.erase(it);
                }
                it = nxt;
            }
            if (flag == false)
            {
                int r = missing.front()[1], c = missing.front()[2];
                missing.pop_front();
                ans += B[r][c];
                row_count[r]--;
                col_count[c]--;

            }
        }

    }
    return 0;
}