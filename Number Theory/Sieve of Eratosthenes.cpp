#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
#define ll long long
// Function to find all prime
// numbers up to 'n'
vector<ll> findAllPrimes(ll n) {
     // Initialize with 1 (assuming all
     // numbers are prime initially)
    vector<ll> prime(n + 1, 1);
    
    // 0 and 1 are not prime
    prime[0] = prime[1] = 0; 
    
    // Apply Sieve of Eratosthenes
    for (ll i = 2; i*i <= n; ++i) {
        if (prime[i] == 1) {
            for (ll j = i * i; j <= n; j += i) {
                // Mark multiples of prime
                // numbers as not prime
                prime[j] = 0; 
            }
        }
    }
    
    vector<ll> ans;
    // Collect prime numbers
    for (ll i = 2; i <= n; ++i) {
        if (prime[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    ll n = 32;
    vector<ll> primes = findAllPrimes(n);

    cout << "Prime numbers less than or equal to " << n << ":" << endl;
    for (ll prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

/*
Complexity Analysis
Time Complexity: O(N + N*log(log(N)))where N is the input number. The outer loop iterates from 2 to the square root of n which is O(sqrt(n)) iterations.

The inner loop iterates over multiples of each prime number found, marking them as not prime.
In total, the number of operations performed is: O(n/2 + n/3 + n/5 + ….) = O(n log(log(N))
Space Complexity : O(N) where N is the input number as additional space proportional to the input size is needed to store a vector of size ‘n+1’ to store whether each number up to n is prime.
*/
                                
                            