#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int inc = 0, dec = 0, cons = 0;
        for (size_t i = 1; i < n; i++)
        {
            if (v[i] - v[i - 1] > 0)
                inc++;
            else if (v[i] - v[i - 1] < 0)
                dec++;
            else
                cons++;
        }
        // cout << inc << " " << dec << " " << cons << endl;
        int temp = max(inc, dec) - min(inc, dec);
        if (inc > dec)
        {
            for (size_t i = 1; temp && i < n; i++)
            {
                if (v[i] - v[i - 1] > 0)
                {
                    v[i] *= -1;
                    temp--;
                }
            }
        }
        else
        {
            for (size_t i = 1; i < n && temp; i++)
            {
                if (v[i - 1] > v[i])
                {
                    v[i - 1] *= -1;
                    temp--;
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}