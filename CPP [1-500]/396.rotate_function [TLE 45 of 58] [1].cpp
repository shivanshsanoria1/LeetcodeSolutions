class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(), ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=0; j<n; j++)
            {
                int index=(j+i)%n;
                sum+=index*nums[j];
            }
            ans= max(ans,sum);
        }
        return ans;
    }
};