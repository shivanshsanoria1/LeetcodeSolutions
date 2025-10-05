class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            int sign = i % 2 == 0 ? 1 : -1;
            sum += sign * nums[i];
        }

        return sum;
    }
};