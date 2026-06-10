class Solution {
public:
    int largestPerimeter(vector<int>& nums) { // T.C.=O(nlogn)
        int n=nums.size(), ans=0;
        if(n<3) // no triangle can be formed
            return 0;
        sort(nums.begin(),nums.end());
        for(int i=n-1; i>=2; i--)
            if(nums[i-2]+nums[i-1] > nums[i])
                return nums[i-2]+nums[i-1]+nums[i];
        return 0;
    }
};