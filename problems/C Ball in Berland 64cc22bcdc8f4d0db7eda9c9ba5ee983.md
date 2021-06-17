# C. Ball in Berland

Created Time: Jan 25, 2021 9:02 AM
Do Date: Jan 25, 2021
Last edited time: Jan 25, 2021 9:08 AM
Points: 1300
Status: done
Tags: complementary

Given a k pairs of girls and boys, find the number of ways to choose 2 paris such there is no common boy or common girl in this two pairs. 

```cpp
int main()
{
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> x(k), y(k); 
        for (int i = 0; i < k; i++) cin >> x[i]; 
        for (int i = 0; i < k; i++) cin >> y[i]; 
        vector<int> deg1(a + 1), deg2(b + 1); 
        for (int i = 0; i < k; i++)
        {
            deg1[x[i]]++; 
            deg2[y[i]]++; 
        }
        long long ans = 0; 
        for (int i = 0; i < k; i++)
        {
            ans += (k - deg1[x[i]] - deg2[y[i]] + 1);
        }
        cout << (ans / 2) << endl;
    }
    return 0;
}
```