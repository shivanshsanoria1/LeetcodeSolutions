class Solution {
public:
    int largestPerimeter(vector<int>& nums) { // T.C=O(n^3)
        int n=nums.size(),ans=0;
        if(n<3) // no triangle can be formed
            return 0;
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(isValidTriangle(nums[i],nums[j],nums[k])==true)
                        ans=max(ans,nums[i]+nums[j]+nums[k]);
                }
            }
        }
        return ans;
    }
    
    bool isValidTriangle(int a, int b, int c)
    {
        if(a<b+c && b<a+c && c<a+b)
            return true;
        return false;
    }
};