class Solution {
public:
    bool hasAlternatingBits(int n) {
        int dig=n&1; //store LSB in dig
        n=n>>1;
        while(n)
        {
            if(dig==(n&1))
                return false;
            dig=n&1;
            n=n>>1;
        }
        return true;
    }
};