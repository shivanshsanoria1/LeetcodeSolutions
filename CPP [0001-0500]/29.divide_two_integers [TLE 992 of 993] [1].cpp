class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) //edge case
            return INT_MAX;
        else if(dividend==INT_MIN && divisor==1) //edge case
            return INT_MIN;
        int sign=1;
        if((dividend<0)^(divisor<0))
            sign=-1;
        long long int dd=abs(dividend),dv=abs(divisor);
        int quo=0;
        while(dd>=dv)
        {
            dd=dd-dv;
            quo++;
        }
        return quo*sign;
    }
};