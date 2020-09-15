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
    void generate(string digits, string str, vector<string> &v)
    {
        if (str.length() == digits.length()) v.push_back(str);
        else
        {
            if (digits[str.length()] == '2')
            {
                generate(digits, str + 'a', v);
                generate(digits, str + 'b', v);
                generate(digits, str + 'c', v);
            }
            if (digits[str.length()] == '3')
            {
                generate(digits, str + 'd', v);
                generate(digits, str + 'e', v);
                generate(digits, str + 'f', v);
            }
            if (digits[str.length()] == '4')
            {
                generate(digits, str + 'g', v);
                generate(digits, str + 'h', v);
                generate(digits, str + 'i', v);
            }
            if (digits[str.length()] == '5')
            {
                generate(digits, str + 'j', v);
                generate(digits, str + 'k', v);
                generate(digits, str + 'l', v);
            }
            if (digits[str.length()] == '6')
            {
                generate(digits, str + 'm', v);
                generate(digits, str + 'n', v);
                generate(digits, str + 'o', v);
            }
            if (digits[str.length()] == '7')
            {
                generate(digits, str + 'p', v);
                generate(digits, str + 'q', v);
                generate(digits, str + 'r', v);
                generate(digits, str + 's', v);
            }
            if (digits[str.length()] == '8')
            {
                generate(digits, str + 't', v);
                generate(digits, str + 'u', v);
                generate(digits, str + 'v', v);
            }
            if (digits[str.length()] == '9')
            {
                generate(digits, str + 'w', v);
                generate(digits, str + 'x', v);
                generate(digits, str + 'y', v);
                generate(digits, str + 'z', v);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        generate(digits, "", v);
        return v;
    }
};