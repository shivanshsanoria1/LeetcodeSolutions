class Solution {
public:
    void moveZeroes(vector<int>& nums) { // similar to Bubble Sort
        int n=nums.size(), temp;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-1-i; j++)
            {
                if(nums[j]==0)
                {
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
    }
};