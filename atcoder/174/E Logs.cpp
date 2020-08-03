#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    
    return 0;
}