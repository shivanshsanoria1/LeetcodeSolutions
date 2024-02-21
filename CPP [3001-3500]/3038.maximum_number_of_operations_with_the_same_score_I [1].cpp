class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maxOperations(vector<int>& nums) {
        int sum = nums[0] + nums[1];
        int ops = 0;
        for(int i=0; i<nums.size()-1; i += 2)
        {
            if(nums[i] + nums[i+1] != sum)
                break;
            ops++;
        }
        return ops;
    }
};