#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    int cnt_w = 0, cnt_r = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == 'W')
            cnt_w++;
        else
            cnt_r++;
    }
    int ans = 0;
    for (int i = 0; i < cnt_r; i++)
    {
        if (s[i] == 'W')
            ans++;
    }
    cout << ans << endl;
}