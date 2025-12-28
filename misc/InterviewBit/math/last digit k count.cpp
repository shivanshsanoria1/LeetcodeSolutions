int Solution::solve(int a, int b, int last_dig) {
    int ans= (b-a+1)/10; //complete groups of 10
    int rem= (b-a+1)%10; //incomplete group of size 'rem'
    for(int i=a; i<a+rem; i++) //check the first 'rem' numbers
        if(i%10 == last_dig)
        {
            ans++;
            break;
        }
    return ans;
}
