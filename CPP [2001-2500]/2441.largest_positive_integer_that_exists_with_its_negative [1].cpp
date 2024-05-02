class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    // Sorting + 2-pointer
    int findMaxK(vector<int>& nums) { 
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size()-1;

        while(left < right)
        {
            if(nums[left] > 0 || nums[right] < 0)
                break;
                
            if(nums[left] + nums[right] == 0)
                return nums[right];
            else if(nums[left] + nums[right] > 0)
                right--;
            else // nums[left] + nums[right] < 0
                left++;
        }

        return -1;
    }
};