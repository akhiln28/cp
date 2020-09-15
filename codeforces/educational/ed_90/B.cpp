#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include <utility>

#define max_n 200001

int arr[max_n];

using namespace std;

int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (st.top() + s[i] - '0' - '0' == 1)
                {
                    st.pop();
                    count++;
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        if (count & 1) cout << "DA" << endl;
        else cout << "NET" << endl;
    }
    return 0;
}