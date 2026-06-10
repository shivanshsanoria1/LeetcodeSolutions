class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num=0,dig;
        for(int i=0; i<32; i++)
        {
            dig=n%2;
            num=num*2+dig;
            n=n/2;
        }
        return num;
    }
};