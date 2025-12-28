vector<int> Solution::primesum(int n) {
    vector<int> ans;
    vector<bool> primes(n+1,true);
    primes[0]=false;
    primes[1]=false;
    for(int i=2; i*i<=n; i++)
        if(primes[i]==true)
            for(int j=i*i; j<=n; j=j+i)
                primes[j]=false;
    int left=2, right=n;
    while(left <= right)
    {
        if(primes[left]==false)
        {
            left++;
            continue;
        }
        if(primes[right]==false)
        {
            right--;
            continue;
        }
        if(left+right==n)
        {
            ans.push_back(left);
            ans.push_back(right);
            break;
        }
        else if(left+right < n)
            left++;
        else
            right--;
    }
    return ans;
}