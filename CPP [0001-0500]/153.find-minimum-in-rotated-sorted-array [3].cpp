class Solution {
public:
    int findMin(vector<int>& nums) { // T.C.=O(logn)
        int n=nums.size(), left=0, right=n-1, mid;
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(nums[mid] >= nums[right]) // search in right subarray
                left=mid+1;
            else // search in left subarray
                right=mid;
        }
        return nums[mid];
    }
};