#include <iostream>
#include <string>
#include <stack>

using namespace std;

int isOp(char ch)
{
    switch (ch)
    {
    case '(':
        return 1;
        break;
    case ')': 
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;

    default:
        break;
    }
}

bool isChar(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}


string infix_to_postfix(string s)
{
    stack<char> st;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (st.empty())
            st.push(s[i]);
        else if (isOp(s[i]))
        {
            if (isOp(st.top()) && )
        }
        
    }
    
    return s;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << infix_to_postfix(s) << endl;
    }
}