#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include <utility>

#define max_n 200001

int arr[max_n];

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        float cost = (float) (c/b);
        if (a == (long long) cost) {
            cout << b - 1 << " " << -1 <<  endl;
        }
        else if (a < (long long) cost) {
            cout << "1 -1" << endl;
        }
        if (a > (long long) cost) {
            long long t1, t2 = b;
            if (a < c) t1 = 1;
            else t1 = -1;
            cout << t1 << " " << t2 << endl;
        }

    }
    return 0;
}