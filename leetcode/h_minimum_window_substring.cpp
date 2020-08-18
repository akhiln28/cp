#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    bool contains(vector<int> &window, vector<int> &t_a)
    {
        bool ret = true;
        for (int i = 0; i < window.size(); i++)
        {
            if (window[i] < t_a[i])
                return false;
        }
        return ret;
    }
    string minWindow(string s, string t) {
        vector<int> t_a(256, 0);
        for (int i = 0; i < t.size(); i++)
        {
            t_a[t[i] - 'A']++;
        }
        vector<int> window(256, 0);
        string ans(s.length() + 1, 'A'); 
        int start = 0, end = 0; window[s[0] - 'A']++;
        while (start != s.length())
        {
             
            while (!contains(window, t_a) && end < s.length() - 1)   
            {
                window[s[++end] - 'A']++;
            }
            if (end == s.length() - 1 && !contains(window, t_a)) break;
            while (contains(window, t_a))
            {
                window[s[start++] - 'A']--; 
            }
            start--; window[s[start] - 'A']++;
            if (contains(window, t_a) && ans.length() > end - start + 1)
            {
                ans = s.substr(start, end - start + 1);
            }
            window[s[start] - 'A']--, start++;
        }
        if (ans.length() == s.length() + 1) return "";
        return ans;
    }
};


int main()
{
    string s, t; cin >> s >> t;
    Solution so;
    cout << so.minWindow(s, t).size() << endl;
    return 0; 
}