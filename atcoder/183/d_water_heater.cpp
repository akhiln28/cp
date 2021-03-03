#include <iostream>
#include <vector>

#define ll long long
#define max_n 2e5+1

using namespace std;

int main()
{
    int n, w; cin >> n >> w;
    vector<ll> cum(max_n); 
    for (int i = 0; i < n; i++)
    {
        int s, t, p; 
        cin >> s >> t >> p;
        cum[s] += p; 
        cum[t] -= p; 
    }

    if (cum[0] > w) 
    {
        cout << "No" << endl;
        return 0; 
    }
    for (int i = 1; i < n; i++)
    {
        cum[i] += cum[i - 1]; 
        if (cum[i] > w)
        {
            cout << "No" << endl;
            return 0; 
        }
    }
    cout << "Yes" << endl;    
    return 0;
}