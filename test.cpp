#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

bool isvalid(int n)
    {
        vector<int> digits; 
        while (n)
        {
            digits.push_back(n%10); 
            n /= 10; 
        }
        for (int i = 1; i < digits.size(); i++)
        {
            if (digits[i] > digits[i - 1] + 1 or digits[i] < digits[i - 1] - 1) return false; 
        }
        return true; 
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        stack<int> st; 
        st.push(1);
        int count = 0; 
        while (st.size())
        {
            int factor = 1; 
            int top = st.top(); st.pop();
	    cout << top << endl;
            count++;
            while (top + factor <= m)
            {
                if (top + factor >= n and isvalid(top + factor)) st.push(top + factor); 
                factor *= 10;
            }
        }
        return count; 
    }

int main()
{
	int n, m; cin >> n >> m; 
	cout << steppingNumbers(n, m) << endl;
	return 0; 
}
		
