class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y, set_bits=0;
        while(z>0)
        {
            set_bits+=(z&1);
            z=z>>1;
        }
        return set_bits;
    }
};