class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> findValidElements(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(i == 0 || i == n-1){
                ans.push_back(nums[i]);
                continue;
            }

            bool isPeak = true;
            for(int j=i-1; j>=0; j--)
                if(nums[j] >= nums[i]){
                    isPeak = false;
                    break;
                }
            if(isPeak){
                ans.push_back(nums[i]);
                continue;
            }

            isPeak = true;
            for(int j=i+1; j<n; j++)
                if(nums[i] <= nums[j]){
                    isPeak = false;
                    break;
                }
            if(isPeak)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};