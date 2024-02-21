class Solution {
public:
    int reductionOperations(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int step = 0;
        int op = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] != nums[i])
                step++;
            op += step;
        }
        return op;
    }
};