class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) //edge case
            return INT_MAX;
        else if(dividend==INT_MIN && divisor==1) //edge case
            return INT_MIN;
        long int dd=abs(dividend),dv=abs(divisor);
        int quo=0;
        while(dd>=dv)
        {
            long int dv2=dv; //divisor2 is the highest divisor that does not exceed dividend
            int mul=1; //keeps count of num. of times divisor2 is multiplied
            while(dd>=(dv2<<1)) //divisor >= 2 times the dividend2
            {
                dv2=dv2<<1; //double the dividen2
                mul=mul<<1;
            }
            quo=quo+mul;
            dd=dd-dv2; //remove the highest divisor from the dividend
        }
        if((dividend<0)^(divisor<0)) //dividend and divisor are +ive and -ive
            return -quo;
        return quo; //dividend and divisor are either both +ive or both -ive
    }
};