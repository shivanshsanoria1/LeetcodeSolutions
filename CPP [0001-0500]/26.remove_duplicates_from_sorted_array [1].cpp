class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),j=0;
        if(n==0)
            return 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] != nums[j])
            {
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};