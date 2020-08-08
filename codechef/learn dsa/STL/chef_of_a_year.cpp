#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main() 
{
    int n, m; cin >> n >> m;
    map<string, string> chef_country;
    map<string, int> chef_score;
    map<string, int> country_score;
    for (size_t i = 0; i < n; i++)
    {
        string chef, country;
        cin >> chef >> country;
        chef_country[chef] = country;
    }
    for (size_t i = 0; i < m; i++)
    {
        string chef; cin >> chef;
        chef_score[chef]++;
        country_score[chef_country[chef]]++;
    }
    string max_country, max_chef; int max = 0;
    for(auto it : country_score)
    {  
        if (max < it.second)
        {
            max = it.second;
            max_country = it.first;
        }
    }
    max = 0;
    for (auto it : chef_score)
    {
        if (max < it.second)
        {
            max = it.second;
            max_chef = it.first;
        }
    }
    cout << max_country << endl;
    cout << max_chef << endl;
}

