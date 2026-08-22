class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool isMiddleElementUnique(vector<int>& nums) {
        const int n = nums.size();
        for(int i=0; i<n; i++)
            if(i != n/2 && nums[i] == nums[n/2])
                return false;
        
        return true;
    }
};