class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),c=0,j=n-1;
        for(int i=0; i<n; i++)
        {
            if(i>j)
                break;
            if(nums[i]==val)
            {
                nums[i]=nums[j];
                nums[j]=-1;
                j--;
                i--;
            }
        }
        return j+1;
    }
};