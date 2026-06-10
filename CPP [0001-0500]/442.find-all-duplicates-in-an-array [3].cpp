class Solution {
private:
    void restoreArray(vector<int>& nums) {
        for(int& num: nums)
            num = abs(num);
    }

public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> findDuplicates(vector<int>& nums) { 
        int n=nums.size();
        vector<int> ans;

        if(n < 2)
            return ans;

        for(int i=0; i<n; i++) 
        {
            // index [i] points to index [abs(nums[i]) - 1]
            int idx = abs(nums[i]) - 1;

            // change the sign of element at index 'idx'
            nums[idx] = -nums[idx]; 

            // if element at index 'idx' is +ive, 
            // then abs(nums[i]) is the duplicate
            if(nums[idx] > 0) 
                ans.push_back(abs(nums[i])); 
        }

        restoreArray(nums); // not-required

        return ans;
    }
};