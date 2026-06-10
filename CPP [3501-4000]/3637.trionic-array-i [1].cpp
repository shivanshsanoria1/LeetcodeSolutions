class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = -1, q = -1;

        for(int i=1; i<n; i++)
        {
            if(nums[i-1] == nums[i])
                return false;

            if(p == -1)
            {
                if(nums[i-1] > nums[i])
                    p = i-1;
                if(p == 0)
                    return false;
            }
            else if(q == -1)
            {
                if(nums[i-1] < nums[i])
                    q = i-1;
            }
            else if(nums[i-1] > nums[i])
                return false;
        }

        return q > 0;
    }
};