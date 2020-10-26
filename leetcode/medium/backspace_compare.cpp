#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<char> value(string s)
    {
        vector<char> v(s.length());
        int ptr = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#') if (ptr) ptr--;
            else v[ptr] = s[i], ptr++;
        }
        return vector<char> (v.begin(), v.begin() + ptr);
    }
    bool backspaceCompare(string S, string T) {
        auto v1 = value(S), v2 = value(T);
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < v2.size(); i++)
        {
            cout << v2[i] << " ";
        }
        cout << endl;
        return value(S) == value(T);
    }
};

int main()
{
    string s1, s2; cin >> s1 >> s2;
    Solution s;
    cout << s.backspaceCompare(s1, s2) << endl;
    return 0;
}