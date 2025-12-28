bool factorsFreqIsPowersOf2(int n) //returns true if number of divisors of n is a power of 2
{
    int c=0;
    for(int i=1; i*i<=n; i++)
        if(n%i==0)
        {
            if(n/i==i) //divisors are equal
                c+=1;
            else
                c+=2;
        }
    float lc=log2(c); //check if c is a power of 2
    return floor(lc) == ceil(lc) ? true : false;
}

vector<int> Solution::powerfulDivisors(vector<int> &arr) {
    int n=arr.size(), max_num=INT_MIN;
    for(int i=0; i<n; i++) //find max num in array
        max_num= max(max_num,arr[i]);
    vector<int> dp(max_num+1); //make a dp array from 0 to max_num
    dp[0]=0;
    for(int i=1; i<max_num+1; i++)
    {
        dp[i]=dp[i-1];
        if(factorsFreqIsPowersOf2(i)==true)
            dp[i]++;
    }
    vector<int> ans(n);
    for(int i=0; i<n; i++)
        ans[i]=dp[arr[i]];
    return ans;
}
