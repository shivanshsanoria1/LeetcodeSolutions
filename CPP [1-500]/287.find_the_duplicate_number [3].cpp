class Solution {
public:
    void restoreArray(vector<int>& nums){
        for(int& num: nums)
            if(num < 0)
                num *= -1;
    }

    int findDuplicate(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        for(int i=0; i<nums.size(); i++)
        {
            // find index corresponding to each element, duplicate elements will have same index values
            int idx = abs(nums[i]);
            // mark the curr element as visited
            nums[idx] *= -1;
            // -ive means that element is visited once, +ive means that element is visited twice
            if(nums[idx] > 0) // nums[idx] is visited twice
            {
                restoreArray(nums);
                return nums[i]; // so return the element corresponding to that index
            }
        }
        restoreArray(nums);
        return -1;
    }
};