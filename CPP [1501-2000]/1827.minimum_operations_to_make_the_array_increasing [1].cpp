class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] <= nums[i-1])
            {
                int temp= nums[i]; //save the curr value
                nums[i]= nums[i-1]+1; //update curr value to prev value + 1
                c+=nums[i]-temp; //add diff of new curr value and old curr value to count
            }
        }
        return c;
    }
};