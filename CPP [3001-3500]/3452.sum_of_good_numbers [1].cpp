class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n=nums.size();
        int sum = 0;

        for(int i=0; i<n; i++)
        {
            sum += nums[i];

            if((i-k >= 0 && nums[i] <= nums[i-k]) || (i+k < n && nums[i] <= nums[i+k]))
                sum -= nums[i];
        }

        return sum;
    }
};