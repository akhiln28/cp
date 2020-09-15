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
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();
    vector<int> v{1, 2, 3, 4, 5, 6};
    auto it = v.end();
    auto end = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(end - start).count() << endl;
    return 0;
}