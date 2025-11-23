class Solution {
public:
    uint32_t reverseBits(uint32_t n) { // bit manipulation
        uint32_t dig,num=0;
        for(int i=0; i<32; i++)
        {
            dig=n&1;
            n=n>>1;
            num=num<<1;
            num=num+dig;
        }
        return num;
    }
};