class Solution {
public:
    int subsetXORSum(vector<int>& nums) { //idk how this code works
        int n=nums.size(), ans=0;
        for(int i=0; i<n; i++)
            ans= ans | nums[i];
        return ans*pow(2,n-1);
    }
};