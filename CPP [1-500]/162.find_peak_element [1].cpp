class Solution {
public:
    int findPeakElement(vector<int>& nums) { //T.C.=O(n)
        int n=nums.size();
        if(n==1) //if size of array is 1 return 0th element
            return 0;
        if(nums[0] > nums[1]) //check for first element
            return 0;
        if(nums[n-1] > nums[n-2]) //check for last element
            return n-1;
        for(int i=1; i<n-1; i++) //check for all elements except first and last ones
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        return -1;
    }
};