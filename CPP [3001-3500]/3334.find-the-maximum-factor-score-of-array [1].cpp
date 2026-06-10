class Solution {
private:
    typedef long long int lli;

    // returns the product of gcd and lcm of all elements 
    // in the array excluding the element at index 'excludeIdx'
    lli findProductOfGCDandLCM(vector<int>& nums, int excludeIdx){
        int gcdVal = excludeIdx == 0 ? nums[1] : nums[0];
        lli lcmVal = 1;

        for(int i=0; i<nums.size(); i++)
        {
            if(i == excludeIdx)
                continue;
            gcdVal = __gcd(gcdVal, nums[i]);
            lcmVal = (lcmVal * nums[i]) / __gcd(lcmVal, (lli)nums[i]);
        }

        return lcmVal * gcdVal;
    }

public:
    // T.C.=O(n^2 * log(m)), S.C.=O(1)
    // m: max-val in nums[]
    long long maxScore(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0]*nums[0];

        // score without excluding any element
        lli score = findProductOfGCDandLCM(nums, -1);

        // score by excluding the element at index i
        for(int i=0; i<nums.size(); i++)
            score = max(score, findProductOfGCDandLCM(nums, i));
        
        return score;
    }
};