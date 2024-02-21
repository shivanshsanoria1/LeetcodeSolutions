class Solution {
public:
    int findMin(vector<int>& nums) { // T.C.=O(n)
        int min=INT_MAX;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] < min)
                min=nums[i];
        return min;
    }
};