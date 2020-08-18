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

int main()
{
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int r, g, b, w; cin >> r >> g >> b >> w;
        int odds = 0; 
        if (r & 1) odds++;
        if (g & 1) odds++;
        if (b & 1) odds++;
        if (w & 1) odds++;
        string ans = "No"; 
        if (odds == 1 || odds == 0 || odds == 4) ans = "Yes";
        if (odds == 3)
        {
            if (r && g && b) ans = "Yes"; 
        }
        cout << ans << endl;
    }
    
}