#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int one = 0, two = 0, three = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                one++;
            if (s[i] == '2')
                two++;
            if (s[i] == '3')
                three++;
        }
        if (!(one && two && three))
        {
            cout << '0' << endl;
            continue;
        }
        for (l = 0; l < s.length(); l++)
        {
            if (s[l] == '1')
            {
                if (one > 1)
                    one--;
                else if (one == 1)
                    break;
            }
            else if (s[l] == '2')
            {
                if (two > 1)
                    two--;
                else if (two == 1)
                    break;
            }
            else if (s[l] == '3')
            {
                if (three > 1)
                    three--;
                else if (three == 1)
                    break;
            }
        }
        for (r = s.length() - 1; r >= 0; r--)
        {
            if (s[r] == '1')
            {
                if (one > 1)
                    one--;
                else if (one == 1)
                    break;
            }
            else if (s[r] == '2')
            {
                if (two > 1)
                    two--;
                else if (two == 1)
                    break;
            }
            else if (s[r] == '3')
            {
                if (three > 1)
                    three--;
                else if (three == 1)
                    break;
            }
        }
        cout << l << " " << r << endl;
        cout << r - l + 1 << endl;
    }

    return 0;
}