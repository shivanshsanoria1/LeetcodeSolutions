class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(1)
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) //to handle duplicates
                continue;
            int left=i+1, right=n-1;
            while(left < right)
            {
                if(nums[i]+nums[left]+nums[right] == 0)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]) //to handle duplicates
                        left++;
                    while(left<right && nums[right]==nums[right-1]) //to handle duplicates
                        right--;
                    left++;
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right] < 0)
                    left++;
                else
                    right--;
            }
        }
        return ans;
    }
};