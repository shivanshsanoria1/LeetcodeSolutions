class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) { // T.C.=O(n) , S.C.=O(1)
        int left = 0, right = nums.size()-1;
        while(left < right)
        {
            if(nums[left] % 2 == 1) // odd
            {
                swap(nums[left], nums[right]);
                right--;
            }
            else // even
                left++;
        }
        return nums;
    }
};