#include <bits/stdc++.h>
using namespace std;

bool util(char ch1, char ch2)
{
    return ch1 == '(' && ch2 == ')';
}
int main() 
{
    int t;
    cin >> t;
    long long n;
    while(t--)
    {
        cin >> n;
        stack<char> st;
        char ch;
        for (int i = 0; i < n; i++)
        {
            cin >> ch;
            if (st.empty()) st.push(ch);
            else if (util(st.top(), ch)) 
            {
                st.pop();
            }
            else st.push(ch);
        }
        cout << st.size() / 2 << endl;
        
    }
    return 0;

}

