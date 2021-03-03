#include <iostream>
#include <vector>

using namespace std; 

int main()
{
	long long N; cin >> N; 
	vector<long long> factors;
	N *= 2; 
	for (long long i = 1; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			if (N / i == i) factors.push_back(i); 
			else factors.push_back(i), factors.push_back(N/i); 
		}
	}
	int ans = 0; 
	for (auto n : factors)
	{
		ans += ((N / n  - n + 1) % 2 == 0); 
	}
	cout << ans << endl;
	return 0; 
}
