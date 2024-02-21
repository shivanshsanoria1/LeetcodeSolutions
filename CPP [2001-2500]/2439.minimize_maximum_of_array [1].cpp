class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int ans = nums[0];
        long long int sum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            sum += nums[i];
            int avg = ceil((double)sum / (i+1));
            ans = max(ans, avg);
        }
        return ans;
    }
};