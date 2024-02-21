class Solution {
public:
    int search(vector<int>& nums, int target) { // T.C.=O(logn)
        int left=0, right=nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) // target found
                return mid;
            else if(nums[left] <= nums[mid]) // left half is in increasing order
            {
                if(target >= nums[left] && target < nums[mid]) // search for target in the left half
                    right = mid - 1;
                else // search for target in the right half
                    left = mid + 1;
            }
            else // right half is in increasing order
            {
                if(target > nums[mid] && target <= nums[right]) // search for target in the right half
                    left = mid + 1;
                else // search for target in the left half
                    right = mid - 1;
            }
        }
        return -1; // target not found
    }
};