class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(((nums[i] | nums[j]) & 1) == 0)
                    return true;
        return false;
    }
};