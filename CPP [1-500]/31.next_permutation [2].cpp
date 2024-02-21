class Solution {
public:
    void nextPermutation(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1) , Narayana Panditha's algo.
        int n=nums.size();
        int i, j;
        for(i=n-2; i>=0; i--)
            if(nums[i] < nums[i+1])
                break;
        if(i < 0) //no next permutation possible, ie, vector is in decreasing order
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(j=n-1; j>i; j--)
            if(nums[i] < nums[j])
                break;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};