class Solution {
public:
    bool hasAlternatingBits(uint32_t n) { //bit manipulation
        uint32_t val= n+(n>>1);
        return (val & (val+1))==0 ? true : false;
    }
};