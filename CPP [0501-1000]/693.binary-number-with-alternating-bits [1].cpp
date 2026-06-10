class Solution {
public:
    bool hasAlternatingBits(int n) {
        int dig=n%2; // store LSB in dig
        n=n/2;
        while(n)
        {
            if(dig==n%2)
                return false;
            dig=n%2;
            n=n/2;
        }
        return true;
    }
};