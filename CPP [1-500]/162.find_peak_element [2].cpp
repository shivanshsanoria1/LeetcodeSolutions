class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=n-1, mid;
        while(left < right)
        {
            mid= left+(right-left)/2;
            if(nums[mid] < nums[mid+1]) // search in right subarray
                left= mid+1;
            else // search in left subarray
                right= mid;
        }
        return left; // since at this point left=right so any one of them can be returned 
    }
};