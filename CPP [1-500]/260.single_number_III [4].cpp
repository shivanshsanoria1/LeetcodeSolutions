class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Bit-manipulation
    vector<int> singleNumber(vector<int>& nums) {
        int axb = 0; // a^b
        for(int num: nums)
            axb ^= num;
        
        int mask = 1;
        while((axb & mask) == 0)
            mask = mask << 1;

        int x0 = 0, x1 = 0;
        for(int num: nums)
        {
            if((num & mask) == 0)
                x0 ^= num;
            else
                x1 ^= num;
        }

        return {x0, x1};
    }
};
/*
# suppose the 2 unique nums are 'a' and 'b'
# taking the xor of all nums in nums[], will result in (a xor b)
  since all the nums which appear twice will cancel out (as A^A = 0)
# the value a^b will have atleast 1 set-bit
# we then generate a mask with only 1 set-bit at a place where a^b also has a set-bit
# take the xor of all nums in nums[] by putting them in 2 different groups x0 and x1
# x0: nums whose bit is 0, where the mask has its set-bit
# x1: nums whose bit is 1, where the mask has its set-bit
# the 2 distinct nums 'a' and 'b' will fall in different groups x0 and x1
# all others nums (with freq 2) in groups x0 and x1 will cancel out (as A^A = 0)
# thus x0 = a, x1 = b
*/