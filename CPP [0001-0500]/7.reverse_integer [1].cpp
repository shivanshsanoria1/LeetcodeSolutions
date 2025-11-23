class Solution {
public:
    int reverse(int x) {
        bool isNeg = x < 0;
        int n = abs(x);
        int rev = 0;
        while(n > 0)
        {
            // not possible to reverse without causing int overflow
            if(rev > INT_MAX / 10) 
                return 0;
            rev = rev*10 + n % 10;
            n /= 10;
        };
        return isNeg ? -rev : rev;
    }
};