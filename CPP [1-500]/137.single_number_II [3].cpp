class Solution {
public:
    int singleNumber(vector<int>& nums) { // T.C.=O(32*n), S.C.=O(1)
        int ans = 0;
        for(int i=0; i<32; i++)
        {
            unsigned int mask = 1 << i;
            int setBitCount = 0;
            for(int num: nums)
                if(num & mask)
                    setBitCount++;
            setBitCount %= 3;
            ans = ans | (setBitCount << i);
        }
        return ans;
    }
};
/*
# count the set bits for each num at 0th, 1st, 2nd, ..., 31th bit position
# reduce set bit count mod 3 which can only be 0 or 1 here, as all the numbers contributing a set bit 
  at the ith position and freq 3 will be reduced to 0 and the unique number's bit will be left
# build the ans number at each ith bit
*/