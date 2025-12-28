string Solution::convertToTitle(int n) {
    string ans="";
    while(n > 0)
    {
        n--;
        int rem= n%26;
        ans+= (char)(rem+65);
        n/=26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
