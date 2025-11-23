class Solution {
public:
    int findPeakElement(vector<int>& nums) { // T.C.=O(logn)
        int n=nums.size(), left=0, right=n-1, mid;
        if(n==1) // array has only 1 element so return index 0
            return 0;
        while(left <= right)
        {
            mid= left+(right-left)/2;
            if(mid > 0 && mid < n-1) // mid is not the first or last element
            {
                if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) // peak element found
                    return mid;
                else if(nums[mid+1] > nums[mid]) // check in right subarray
                    left= mid+1;
                else // check in left subarray
                    right= mid-1;
            }
            else if(mid==0) // mid is first element
            {
                if(nums[mid] > nums[mid+1])
                    return mid;
                else
                    return mid+1;
            }
            else // mid is last element
            {
                if(nums[mid] > nums[mid-1])
                    return mid;
                else
                    return mid-1;
            }
        }
        return -1;
    }
};