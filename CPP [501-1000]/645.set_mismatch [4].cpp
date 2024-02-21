class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> findErrorNums(vector<int>& nums) { 
        vector<int> ans(2);
        int n=nums.size();
        int sum = 0;
        int correctSum = (n*(n+1))/2;
        int idx = -1;
        for(int i=0; i<n; i++)
        {
            sum += abs(nums[i]);
            // find index corresponding to each element
            // duplicate elements will have same index values
            idx = abs(nums[i]);
            // -ive: element is visited once, +ive: element is visited twice
            // since nums are in range [1,n] and index is in range [0,n-1] so
            // each num is mapped with index-1
            nums[idx - 1] *= -1; 
            // dupliacte found
            if(nums[idx - 1] > 0) 
                ans[0] = abs(nums[i]);
        }
        ans[1] = correctSum - sum + ans[0];

        // restore array (not required)
        for(int i=0; i<n; i++)
            if(nums[i] < 0)
                nums[i] *= -1;
                
        return ans;
    }
};