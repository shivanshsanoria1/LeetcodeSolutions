vector<int> Solution::powerfulDivisors(vector<int> &arr) {
    int n=arr.size(), max_num=INT_MIN;
    for(int i=0; i<n; i++) //find max num in array
        max_num= max(max_num,arr[i]);
    vector<int> dp(max_num+1); //make a dp array to store freq of divisors of 0 to max_num
    dp[0]=0;
    for(int i=1; i<max_num+1; i++)
    {
        dp[i]++;
        for(int j=2*i; j<max_num+1; j=j+i)
            dp[j]++;
    }
    vector<int> ans(n);
    for(int i=0; i<n; i++) //for every element in arr, check how many numbers from 1 to that element have 2^m factors
    {
        int count=0;
        for(int j=1; j<=arr[i]; j++)
        {
            int divisor= dp[j];
            if((divisor & (divisor-1)) == 0) //check if divisor is a power of 2
                count++;
        }
        ans[i]=count;
    }
    return ans;
}
