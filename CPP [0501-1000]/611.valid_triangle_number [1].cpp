class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(), c=0;
        if(n<3) // no triplets possible
            return 0;
        sort(nums.begin(),nums.end());
        for(int i=n-1; i>=2; i--)
        {
            int low=0, high=i-1;
            while(low<high)
            {
                if(nums[low]+nums[high] > nums[i]) // sum of 2 sides > max side 
                {
                    c=c+(high-low); // all the lows corrseponding to that high are counted
                    high--;
                }
                else // sum of 2 sides <= max side
                    low++;
            }
        }
        return c;
    }
};