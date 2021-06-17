# Amazon | Telephonic Round | SDE - 2 - LeetCode Discuss

Created Time: Jan 14, 2021 11:53 PM
Do Date: Jan 17, 2021
Last edited time: Mar 01, 2021 3:43 PM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1500
Problem Statement: Given an even number (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only first such pair.
Source: https://leetcode.com/discuss/interview-question/1017012/amazon-telephonic-round-sde-2
Status: done

Given an even number $n$ (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only first such pair.

Input : 8

Output : (3,5)

Follow Up : Print all pairs that sum up to the input number.

---

We can get the list of all primes less than the given number $n$. And then we can use two pointer technique to find all the pairs that sum up to $n$. As shown below. 

we are using [Sieve of Eratosthenes - GeeksforGeeks](Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42.md) 

```cpp
#define max_n 1e6

// sieve of eratosthenes
void get_primes(vector<int> &primes)
{
    vector<int> is_prime(max_n, true);
    for (int p = 2; p * p <= max_n; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= max_n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= max_n; p++)
    {
        if (is_prime[p])
            primes.push_back(p);
    }
}

int main()
{
    vector<int> primes;
    get_primes(primes); 
    int n; cin >> n; 
    int i = 0, j = primes.size() - 1; 
		// two pointer technique
    while (i < j)
    {
        if (primes[i] + primes[j] == n) 
        {
            cout << primes[i] << " " << primes[j] << endl;
            i++, j--;
        }
        else if (primes[i] + primes[j] < n) i++;
        else j--;
    }
    return 0;
}
```