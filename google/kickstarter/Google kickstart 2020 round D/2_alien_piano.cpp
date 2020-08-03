#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 200001

int arr[max_n];

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int K;
        cin >> K;
        for (size_t i = 0; i < K; i++)
        {
            cin >> arr[i];
        }
        bool inc_flag = true;
        if (K > 1)
            inc_flag = arr[1] > arr[0];
        int size = 1, ans = 0;
        for (size_t i = 1; i < K; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                if (inc_flag == true)
                    size++;
                else
                {
                    // cout << "great " << size << endl;
                    inc_flag = true;
                    ans += (size - 1) / 4;
                    size = 2;
                }
            }
            else if (arr[i] < arr[i - 1])
            {
                if (inc_flag == false)
                {
                    size++;
                    // cout << arr[i] << " " << size << endl;
                }
                else
                {
                    // cout << "less " << size << endl;
                    inc_flag = false;
                    ans += (size - 1) / 4;
                    size = 2;
                }
            }
        }
        // cout << size << endl;
        ans += (size - 1) / 4;
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
