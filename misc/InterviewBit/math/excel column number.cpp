int Solution::titleToNumber(string s) {
    int mul=1, ans=0;
    for(int i=s.length()-1; i>=0; i--)
    {
        ans+= (s[i]-'A'+1)*mul;
        mul*=26;  
    }
    return ans;
}
