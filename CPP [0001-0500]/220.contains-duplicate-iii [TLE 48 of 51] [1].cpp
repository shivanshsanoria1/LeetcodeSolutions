class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        for(int i=0; i<n; i++)
            for(int j=i+1; j <= min(n-1, i + indexDiff); j++)
                if(abs(nums[i] - nums[j]) <= valueDiff)
                    return true;
        return false;
    }
};