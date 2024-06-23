class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-Window (fixed-length)
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flips = 0;

        for(int i=0; i<=n-3; i++)
            if(nums[i] == 0)
            {
                nums[i] = !nums[i];
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
                flips++;
            }
        
        return accumulate(nums.begin(), nums.end(), 0) == n ? flips : -1;
    }
};