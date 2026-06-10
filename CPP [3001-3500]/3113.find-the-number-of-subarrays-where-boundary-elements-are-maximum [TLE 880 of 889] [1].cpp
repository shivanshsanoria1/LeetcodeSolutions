class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            int maxNum = nums[i];

            for(int j=i; j<n; j++)
            {
                maxNum = max(maxNum, nums[j]);

                if(nums[i] == nums[j] && nums[i] == maxNum)
                    count++;
            }
        }

        return count;
    }
};