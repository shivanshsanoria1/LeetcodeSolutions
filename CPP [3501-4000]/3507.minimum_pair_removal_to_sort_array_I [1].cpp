class Solution {
private:
    bool isNonDecreasing(vector<int>& nums){
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] > nums[i])
                return false;

        return true;
    }

    int findMinSumPairIdx(vector<int>& nums){
        int minSum = INT_MAX;
        int idx = 0;
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] + nums[i] < minSum)
            {
                minSum = nums[i-1] + nums[i];
                idx = i;
            }

        return idx;
    }

public:
    // T.C.=O(n^2), S.C.=O(n)
    // Simulation
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> nums2 = nums;
        int ops = 0;
        while(!isNonDecreasing(nums2))
        {
            ops++;
            int idx = findMinSumPairIdx(nums2);
            vector<int> temp;
            
            for(int i=0; i<idx-1; i++)
                temp.push_back(nums2[i]);

            temp.push_back(nums2[idx-1] + nums2[idx]);

            for(int i=idx+1; i<nums2.size(); i++)
                temp.push_back(nums2[i]);

            nums2 = temp;
        }

        return ops;
    }
};