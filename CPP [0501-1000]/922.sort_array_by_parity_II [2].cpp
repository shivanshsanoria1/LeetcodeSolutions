class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size(), j=1;  // j moves on odd indexs
        for(int i=0; i<n; i=i+2) // i moves on even indexs
        {
            if(nums[i]%2!=0)
            {
                if(nums[j]%2==0) // nums[i] is odd and nums[j] is even
                    swap(nums[i],nums[j]);
                else // nums[i] is odd and nums[j] is odd
                    i=i-2; // don't let i move forward
                j=j+2;
            }
        }
        return nums;
    }
};