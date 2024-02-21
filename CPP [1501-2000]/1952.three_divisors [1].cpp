class Solution {
public:
    bool isThree(int n) {
        if(n==1)
            return false;
        int d=1; //n has one divisor '1'
        for(int i=2; i<=n/2; i++)
            if(n%i==0)
                d++;
        d++; //the number itself is divisor
        return d==3 ? true : false;
    }
};