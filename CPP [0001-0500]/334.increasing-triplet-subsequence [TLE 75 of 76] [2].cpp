class Solution {
public:
    bool increasingTriplet(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(1)
        int n=nums.size();
        if(n < 3) //atleast 3 numbers are needed
            return false;
        for(int i=1; i<n-1; i++)
        {
            int left=i-1, right=i+1;
            bool flag_left=false, flag_right=false;
            while(left >= 0)
            {
                if(nums[left] < nums[i]) //smaller element found in the left subarray
                {
                    flag_left=true;
                    break;
                }
                left--;
            }
            while(right < n)
            {
                if(nums[i] < nums[right]) //larger element found in the right subarray
                {
                    flag_right=true;
                    break;
                }
                right++;
            }
            if(flag_left==true && flag_right==true)
                return true;
        }
        return false;
    }
};