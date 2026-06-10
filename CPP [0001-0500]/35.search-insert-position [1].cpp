class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target) // search in left subarray
                low=mid+1;
            else // search in right subarray
                high=mid-1;
        }
        // target not present in array
        if(target>nums[mid])
            return mid+1;
        return mid;
    }
};