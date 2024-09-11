#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

// returns prime nums in range [1, n]
vector<int> sieveOfEratosthenes(int n){
    if(n < 0)
        return {};
    
    // initially assume all nums are prime
    vector<int> isPrime(n + 1, true);
    // 0 and 1 are not prime
    isPrime[0] = false;
    isPrime[1] = false;
    
    // for every prime num 'i' mark all its 
    // multiples (starting from i^2) as not-prime
    for(int i=2; i<=n; i++)
        if(isPrime[i])
            for(int m=i*i; m<=n; m += i)
                isPrime[m] = false;
    
    vector<int> primes;
    for(int i=2; i<=n; i++)
        if(isPrime[i])
            primes.push_back(i);
    
    return primes;
}

// --------------- END --------------- //

int main() {
    vector<int> primes = sieveOfEratosthenes(100);
    
    for(int prime: primes)
        cout<<prime<<" ";
    cout<<endl;

    return 0;
}