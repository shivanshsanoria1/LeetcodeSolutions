class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        while(left < n) //find the leftmost 1
        {
            if(nums[left]==1)
                break;
            left++;
        }
        int right=left+1;
        while(right < n)
        {
            if(nums[right]==1) //1 found
            {
                if(right-left <= k) //distance <= k  
                    return false;
                else //distance >k 
                {
                    left=right; //move left to right
                    right++; //move right forward
                }
            }
            else //0 found
                right++; //move right forward
        }
        return true;
    }
};