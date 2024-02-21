class Solution {
public:
    bool isGood(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        int minNum = *min_element(nums.begin(), nums.end());
        if(minNum != 1)
            return false;

        int maxNum = *max_element(nums.begin(), nums.end());
        int n=nums.size();
        if(n != maxNum + 1)
            return false;

        sort(nums.begin(), nums.end());
        if(nums[n-1] - nums[n-2] != 0)
            return false;
        for(int i=1; i<n-1; i++)
            if(nums[i] - nums[i-1] != 1)
                return false;
        return true;
    }
};