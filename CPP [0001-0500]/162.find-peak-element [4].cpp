class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) //array has only 1 element so return index 0
            return 0;
        if(nums[0] > nums[1]) //0th index element is peak
            return 0;
        if(nums[n-1] > nums[n-2]) //last index element is peak
            return n-1;
        int left=1, right=n-2, mid; //left at index 1 and right at 2nd last index
        while(left <= right)
        {
            mid = left+(right-left)/2;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) //peak element found
                return mid;
            else if(nums[mid+1] > nums[mid]) //check in right subarray
                left = mid+1;
            else //check in left subarray
                right = mid-1;
        }
        return -1;
    }
};