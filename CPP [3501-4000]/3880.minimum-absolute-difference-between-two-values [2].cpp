class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minAbsoluteDifference(vector<int>& nums) {
        const int n = nums.size();
        int idx1 = -1, idx2 = -1;
        int minDiff = n;
        for(int i=0; i<n; i++){
            if(nums[i] == 1)
                idx1 = i;
            else if(nums[i] == 2)
                idx2 = i;
            
            if(idx1 >= 0 && idx2 >= 0)
                minDiff = min(minDiff, abs(idx1 - idx2));
        }

        return minDiff == n ? -1 : minDiff;
    }
};