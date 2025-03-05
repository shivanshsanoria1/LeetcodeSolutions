class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
        {
            int leftSum = accumulate(nums.begin(), nums.begin() + i+1, 0);
            int rightSum = accumulate(nums.begin() + i+1, nums.end(), 0);

            if((leftSum - rightSum) % 2 == 0)
                count++;
        }

        return count;
    }
};