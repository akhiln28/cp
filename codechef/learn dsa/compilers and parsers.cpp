#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;
        int ans = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else if (st.top() == '<' && s[i] == '>')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            
            if (st.empty())
            {
                ans = max(ans, (int)i + 1);
            }
        }
        cout << ans << endl;
    }
}