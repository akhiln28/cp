---
Created Time: Dec 18, 2020 12:31 PM
Do Date: Dec 18, 2020
Last edited time: Apr 08, 2021 8:12 AM
Points: 1600
Relates: Sieve%20of%20Eratosthenes%20in%200(n)%20time%20complexity%20-%20Ge%20fc6cd41328db4ba486bd06895ef941cf.md
Source: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
Status: done
Tags: de shaw
---

# Sieve of Eratosthenes - GeeksforGeeks

Following is the algorithm to find all the prime numbers less than or equal to a given integer *n* by the Eratosthene’s method:
1. Create a list of consecutive integers from 2 to *n*: (2, 3, 4, …, *n*).
2. Initially, let *p* equal 2, the first prime number.
3. Starting from *p*, count up in increments of *p* and mark each of these numbers greater than or equal to *p2* itself in the list. These numbers will be *p(p+1)*, *p(p+2)*, *p(p+3)*, etc..
    2
4. Find the first number greater than *p* in the list that is not marked. If there was no such number, stop. Otherwise, let *p* now equal this number (which is the next prime), and repeat from step 3.
When the algorithm terminates, all the numbers in the list that are not marked are prime.
![Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes1.jpg](Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes1.jpg)
![Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes2.jpg](Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes2.jpg)
![Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes3.jpg](Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes3.jpg)
![Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes4.jpg](Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes4.jpg)
![Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes5.jpg](Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42/SieveofEratosthenes5.jpg)
```cpp
// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <bits/stdc++.h> 
using namespace std; 
void SieveOfEratosthenes(int n) 
{ 
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 
	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 
	// Print all prime numbers 
	for (int p=2; p<=n; p++) 
	if (prime[p]) 
		cout << p << " "; 
} 
// Driver Program to test above function 
int main() 
{ 
	int n = 30; 
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl; 
	SieveOfEratosthenes(n); 
	return 0; 
}
```
The drawback of the above method is that we can find primes only up to 10^6 max because of array limit. 
What is the complexity of the above algorithm?
Patterns: [Number%20Theory](Number%20Theory.md)