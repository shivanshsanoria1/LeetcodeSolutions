class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(), sum=0, pro_sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            pro_sum+=i*nums[i];
        }
        int ans=pro_sum;
        for(int i=1; i<n; i++)
        {
            pro_sum= (pro_sum-(n-1)*nums[n-i]) + (sum-nums[n-i]); //in each step remove the (last index * last element)
            ans= max(ans,pro_sum); //and add the (sum - last element)
        }
        return ans;
    }
};