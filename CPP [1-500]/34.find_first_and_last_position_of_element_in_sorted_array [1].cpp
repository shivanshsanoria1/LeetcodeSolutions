class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1,-1};
        int n=nums.size(), left=0, right=n-1, mid;
        if(n==0) // input array is empty 
            return ans;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid] == target)
                break;
            else if(nums[mid] < target)
                left=mid+1;
            else
                right=mid-1;
        }
        if(nums[mid]==target) // target value found
        {
            left=mid-1;
            right=mid+1;
            while(left>=0)
            {
                if(nums[left]!=nums[mid])
                    break;
                else
                    left--;
            }
            while(right<=n-1)
            {
                if(nums[right]!=nums[mid])
                    break;
                else
                    right++;
            }
            ans[0]=left+1;
            ans[1]=right-1;
        }
        return ans;
    }
};