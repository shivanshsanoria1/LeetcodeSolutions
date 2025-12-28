vector<int> Solution::sieve(int n) { // prime nos. upto n (including n) ; sieve of Eratosthenes
    vector<bool> primes(n+1,true); // initially assume all nos. upto n are prime
    if(n>=0)
        primes[0]=false; // 0 is not prime
    if(n>=1)
        primes[1]=false; // 1 is not prime
    for(int i=2; i*i<=n; i++)
        if(primes[i]==true)
            for(int j=i*i; j<=n; j=j+i) // mark all multiples of i as false
                primes[j]=false;
    vector<int> ans;
    for(int i=2; i<=n; i++)
        if(primes[i]==true)
            ans.push_back(i);
    return ans;
}
