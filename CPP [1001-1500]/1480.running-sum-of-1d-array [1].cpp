class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> run_sum(n);
        run_sum[0]= nums[0];
        for(int i=1; i<n; i++)
            run_sum[i]= run_sum[i-1] + nums[i];
        return run_sum;
    }
};