class Solution {
public:
    int unequalTriplets(vector<int>& nums) { // T.C.=O(n^3), S.C.=O(1)
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i])
                        count++;
        return count;
    }
};