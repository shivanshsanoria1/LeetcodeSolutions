class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<vector<int>> threeSum(vector<int>& nums) { 
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0; i<n-2; i++)
        {
            // to handle duplicates
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;

            int left = i+1, right = n-1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // to handle duplicates
                    while(left < right && nums[left] == nums[left + 1]) 
                        left++;
                    // to handle duplicates
                    while(left < right && nums[right] == nums[right - 1]) 
                        right--;

                    left++;
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                    right--;
            }
        }
        
        return ans;
    }
};