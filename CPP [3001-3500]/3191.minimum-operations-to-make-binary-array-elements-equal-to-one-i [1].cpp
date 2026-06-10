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

        return nums[n-2] == 0 || nums[n-1] == 0 ? -1 : flips;
    }
};
// S.C. can also be considered O(n) as the input array is being modified