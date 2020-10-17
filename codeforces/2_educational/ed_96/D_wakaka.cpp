#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
string to_string(string s)
{
    return '"' + s + '"';
}
string to_string(const char *s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v)
{
    string res = "{";
    for (const auto &x : v)
        res += (res == "{" ? "" : ", ") + to_string(x);
    return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
typedef long long ll;
typedef long double ld;
// char str[200005];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        string str;
        // scanf("%d%s", &n, str);
        cin >> str;
        int run = 0;
        vector<int> runs;
        for (int i = 0; i < str.length(); ++i)
        {
            run++;
            if (i + 1 == str.length() || str[i] != str[i + 1])
            {
                runs.push_back(run);
                run = 0;
            }
        }
        int ans = 0;
        // for (int i = 0; i < runs.size(); i++)
        //     cout << runs[i] << " ";
        // cout << endl;
        for (int i = 0, j = 0; i < runs.size(); ++i)
        {
            j = max(j, i);
            while (j < runs.size())
            {
                if (runs[j] > 1)
                    break;
                ++j;
            }
            if (j == runs.size())
            {
                runs.pop_back();
                --j;
            }
            else
            {
                --runs[j];
            }
            ++ans;
        }
        printf("%d\n", ans);
    }
}
