class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return;
        int left=0, right=0, temp;
        for(int i=0; i<n; i++)
        {
            if(nums[right]==0)
                right++;
            else
            {
                if(left!=right)
                {
                    temp=nums[right];
                    nums[right]=nums[left];
                    nums[left]=temp;
                }
                left++;
                right++;
            }
        }
    }
};