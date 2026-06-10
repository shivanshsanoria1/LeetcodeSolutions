class Solution {
public:
    int countOnes(int n)
    {
        int c=0;
        while(n > 0)
        {
            if(n % 10 == 1)
                c++;
            n=n/10;
        }
        return c;
    }
    
    int countDigitOne(int n) {
        int ans=0;
        for(int i=1; i<=n; i++)
            ans += countOnes(i);
        return ans;
    }
};