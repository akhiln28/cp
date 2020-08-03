#include <iostream>
#include <set>
#include <functional>
#include <vector>
#include <numeric>

#define max_n 200001

using namespace std;

int arr[max_n];

class interval
{
public:
    int l, r;
    interval(int l, int r)
    {
        this->l = l;
        this->r = r;
    }
    int length() const { return r - l + 1; }
    int mid() { return (l + r) / 2; }
    bool operator < (const interval &obj) const
    {
        if (this->length() != obj.length())
            return this->length() > obj.length();
        else
        {
            return this->l < obj.l;
        }
    }
};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            arr[i] = 0;

        set<interval> s;
        interval init(0, n - 1);

        s.insert(init);
        int count = 0;
        while (count <= n - 1)
        {
            count++;
            interval intv = *s.begin();
            s.erase(intv);
            int mid = intv.mid();
            arr[mid] = count;
            if (intv.length() == 1)
                continue;
            interval intv1(intv.l, mid - 1), intv2(mid + 1, intv.r);
            s.insert(intv1);
            s.insert(intv2);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}