class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // T.C.=O(logn), S.C.=O(1)
        int n = nums.size();
        if(n == 1) // array length is 1
            return nums[0];
        if(nums[0] != nums[1]) // element is at the start of the array
            return nums[0];
        if(nums[n-2] != nums[n-1]) // element is at the end of the array
            return nums[n-1];
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])
                return nums[mid];
            else if (nums[mid-1] == nums[mid]) // pair found on left side
            {
                if(mid % 2 == 0) // (odd, even) index pair
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else // pair found on right side
            {
                if(mid % 2 == 0) // (even, odd) index pair
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// array is always of odd length
// for each element before the unique element, the index of each pair is of the form (even, odd)
// for each element after the unique element, the index of each pair is of the form (odd, even)