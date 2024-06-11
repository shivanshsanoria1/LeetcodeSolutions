class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    bool checkSubarraySum(vector<int>& nums, int k) { 
        int n=nums.size();

        for(int i=0; i<n-1; i++)
        {
            int sum = nums[i];
            for(int j=i+1; j<n; j++)
            {
                sum += nums[j];
                if(sum % k == 0)
                    return true;
            }
        }

        return false;
    }
};