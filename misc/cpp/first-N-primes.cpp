#include <bits/stdc++.h>
using namespace std;

// T.C.=O(sqrt(num))
bool isPrime(int num){
    // 0 and 1 are not prime
    if(num <= 1)
        return false;
    
    // 2 is prime
    if(num == 2)
        return true;
    
    // any even num > 2 is not prime
    if(num % 2 == 0)
        return false;
    
    // check divisibility by odd nums in range [3, sqrt(num)]
    for(int i=3; i*i <= num; i += 2)
        if(num % i == 0)
            return false;
    
    return true;
}

vector<int> findPrimes(int n){
    if(n <= 0)
        return {-1};
        
    vector<int> primes;
    primes.push_back(2);
    
    if(n == 2)
        return primes;
    
    for(int num = 3; primes.size() < n; num += 2)
        if(isPrime(num))
            primes.push_back(num);
    
    return primes;
}

int main(){
    int n = 26;
    
    cout<<"The first "<<n<<" primes are: "<<endl;
    
    vector<int> primes = findPrimes(n);
    
    for(int i=0; i<primes.size(); i++)
        cout<<i+1<<" -> "<<primes[i]<<endl;
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}