class Solution {
public:
    bool find132pattern(vector<int>& nums) { // T.C.=O(n^3), S.C.=O(1)
        int n=nums.size();
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
            {
                if(nums[i] >= nums[j])
                    continue;
                for(int k=j+1; k<n; k++)
                    if(nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
            }
        return false;
    }
};