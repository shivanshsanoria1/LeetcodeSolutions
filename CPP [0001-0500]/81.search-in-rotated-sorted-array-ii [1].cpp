class Solution {
public:
    bool search(vector<int>& nums, int target) { // T.C.=O(logn), but O(n) in the worst case
        int left=0, right=nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) // target found
                return true;
            
            if(nums[left] < nums[mid]) // left half is in increasing order
            {
                if(target >= nums[left] && target < nums[mid]) // search for target in the left half
                    right = mid - 1;
                else // search for target in the right half
                    left = mid + 1;
            }
            else if(nums[left] > nums[mid]) // right half is in increasing order
            {
                if(target > nums[mid] && target <= nums[right]) // search for target in the right half
                    left = mid + 1;
                else // search for target in the left half
                    right = mid - 1;
            }
            else
                left++;
        }
        return false;
    }
};