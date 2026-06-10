class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int bit = 1;
        unsigned int mul = 1;
        int ans = 0;
        for(int i=0; i<32; i++)
        {
            int setBitCount = 0;
            for(int num: nums)
                if(num & bit)
                    setBitCount++;

            if(setBitCount >= k)
                ans += mul;

            bit = bit << 1;
            mul *= 2;
        }
        return ans;
    }
};