class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flips = 0;

        for(int i=0; i<n; i++)
        {
            nums[i] = flips % 2 == 0 ? nums[i] : !nums[i];

            if(nums[i] == 0)
            {
                nums[i] = 1;
                flips++;
            }
        }
        
        return accumulate(nums.begin(), nums.end(), 0) == n ? flips : -1;
    }
};