class Solution {
public:
    int maximumGap(vector<int>& nums) { // T.C.=O(nlogn) ; S.C.=O(1)
        int n=nums.size(), diff, max=0;
        if(n<2)
            return 0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<n; i++)
        {
            diff=nums[i]-nums[i-1];
            if(diff > max)
                max=diff;
        }
        return max;
    }
};