class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) { //T.C.=O(n^2) , S.C.=O(1)
        int n=nums.size();
        for(int i=0; i<n-1; i++)
        {
            int curr_sum=nums[i];
            for(int j=i+1; j<n; j++)
            {
                curr_sum+=nums[j];
                if(curr_sum%k==0)
                    return true;
            }
        }
        return false;
    }
};