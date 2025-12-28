string Solution::findDigitsInBinary(int n) {
    if(n==0)
        return "0";
    string bin;
    while(n>0)
    {
        if(n%2==0)
            bin+="0";
        else
            bin+="1";
        n=n/2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}
