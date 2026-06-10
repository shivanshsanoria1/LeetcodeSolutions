class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int count = 0;

        for(int i=0; i<n-1; i++)
        {
            leftSum += nums[i];
            rightSum -= nums[i];

            if((leftSum - rightSum) % 2 == 0)
                count++;
        }

        return count;
    }
};