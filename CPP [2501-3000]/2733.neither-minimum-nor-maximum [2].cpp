class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) { // T.C.=O(1)
        if(nums.size() < 3)
            return -1;
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        int maxi = max(a, max(b, c));
        int mini = min(a, min(b, c));
        if(a < maxi && a > mini)
            return a;
        if(b < maxi && b > mini)
            return b;
        if(c < maxi && c > mini)
            return c;
        return -1;
    }
};
// take the first 3 nums and find the one which is not the min or max