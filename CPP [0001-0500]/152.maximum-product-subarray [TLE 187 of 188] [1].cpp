class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), ans=nums[0];
        for(int i=0; i<n; i++)
        {
            int pro=1;
            for(int j=i; j<n; j++)
            {
                pro=pro*nums[j];
                if(pro > ans)
                    ans=pro;
            }
        }
        return ans;
    }
};