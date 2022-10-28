#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// function to generate all prime numbers till n

vector<int> find_primes(int n)
{
    vector<bool> is_prime(n+5, true);
    
    int root = sqrt(n);
    for(int i=2; i<=root; i++) {
        if(is_prime[i] == true) {
            for(int j=i*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for(int i=2; i<=n; i++) {
        if(is_prime[i] == true) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main()
{
    int n; cin >> n;
    vector<int> primes = find_primes(n);
    
    for(auto prime: primes) {
        cout << prime << " ";
    }
    
    cout << '\n';

    return 0;
}