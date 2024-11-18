class Solution {
public:
    // T.C.=O(n*k), S.C.=O(1)
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<=n-k; i++)
        {
            int val = nums[i];
            for(int j=i+1; j<i+k; j++)
            {
                if(nums[j] - nums[j-1] != 1)
                {
                    val = -1;
                    break;
                }
                val = nums[j];
            }
            
            ans.push_back(val);
        }

        return ans;
    }
};