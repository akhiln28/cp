#include <iostream>
#include <string>

#define max_n 200001

using namespace std;

int arr[max_n];

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        string ans = "YES";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i - j == (arr[j] - arr[i]) % n)
                    ans = "NO";
            }
        }
        cout << ans << endl;
    }
    return 0;
}