class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        while(1)
        {
            int mini = INT_MAX;
            for(int i=0; i<n; i++)
            {
                if(nums[i] == 0) // skip the 0's
                    continue;
                mini = min(mini, nums[i]);
            }
            if(mini == INT_MAX)
                break;
            for(int i=0; i<n; i++)
                if(nums[i] >= mini)
                    nums[i] -= mini;
            count++;
        }
        return count;
    }
};