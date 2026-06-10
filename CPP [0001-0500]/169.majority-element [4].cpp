class Solution {
public:
    // T.C.=O(32*n), S.C.=O(1)
    // Bit-manipulation
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majority = 0;

        for(int i=0; i<32; i++)
        {
            unsigned int mask = 1<<i;
            // count of nums having ith bit as 1
            int count1 = 0;

            for(int num: nums)
            {
                // ith bit of num
                int bit = (num & mask) >> i;
                count1 += bit;
            }


            // ith bit of the majority element must be 1
            if(count1 > n/2)
                majority |= 1<<i;
        }

        return majority;
    }
};