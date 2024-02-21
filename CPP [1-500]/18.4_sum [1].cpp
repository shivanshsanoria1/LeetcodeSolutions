class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { //T.C.=O(n^3) , S.C.=O(1)
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-3; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) //to handle duplicates
                continue;
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) //to handle duplicates
                    continue;
                long int curr_target= (long int)target-nums[i]-nums[j]; //long int is used to prevent int overflow
                int left=j+1, right=n-1;
                while(left < right)
                {
                    if(nums[left]+nums[right] == curr_target)
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left+1]) //to handle duplicates
                            left++;
                        while(left < right && nums[right] == nums[right-1]) //to handle duplicates
                            right--;
                        left++;
                        right--;
                    }
                    else if(nums[left]+nums[right] < curr_target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
};