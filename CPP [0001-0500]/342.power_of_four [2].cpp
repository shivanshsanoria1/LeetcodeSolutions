class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0)
        {
            for(int i=0; i<32; i=i+2) // 32 bit int. is used
            {
                if(n == (1<<i)) // left shift 1 in even places to get powers of 4
                    return true;
            }
        }
        return false;
    }
};