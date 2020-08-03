#include <iostream>
#include <functional>
#include <algorithm>

#define max_n 1000001
using namespace std;

int arr[max_n];

int main(){
    int n, q, x;
    cin >> n >> q;
    for (int i = 0;i < n;i++)
    {
        cin >> x;
        arr[x]++;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        if (x > 0 && arr[x] > 0) 
        {
            arr[x]--;
        }
        else if (x < 0)
        {
            
        }
    }
    return 0;
}