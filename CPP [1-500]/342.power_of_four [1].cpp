class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0)
        {
            while(n%4==0)
                n=n/4;
            if(n==1)
                return true;
        }
        return false;
    }
};