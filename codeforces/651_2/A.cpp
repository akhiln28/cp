#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include <utility>

#define max_n 100001

int arr[max_n];
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << n/2 << endl;
    }
    return 0;
}

