#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// print the smallest integer m >= n that is a good number. the nearest good number...

// returnes whether if n is a good number or not
bool isGood(long long n)
{ 
    if(n == 1 || n == 0)
        return true;
    int exp = log(n)/log(3);
    if(n >= 2 * pow(3, exp))
    {
        return false;
    }
    return isGood(n - pow(3, exp));
}

bool Case1(long long n)
{
    int exp = log(n)/log(3);
    if(n < 2 * pow(3, exp))
        return true;
    else
        return false;
}

long long Nextn(long long n)
{
    if(isGood(n))
        return n;
    else 
    {
        int exp = log(n)/log(3);
        if(!Case1(n) || !Case1(n - pow(3, exp)))
            return pow(3, exp + 1);
        else 
        {
            long long temp = Nextn(n - pow(3, exp));
            if(pow(3, exp) == temp)
                return pow(3, exp + 1);
            else
                return pow(3, exp) + temp;
        }
    }
}

int main()
{
    int q;
    long long n;
    cin >> q;
    while(q--)
    {
        cin >> n;
        cout <<  Nextn(n) << endl;
    } 
    return 0;
}