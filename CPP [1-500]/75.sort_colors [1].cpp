class Solution {
public:
    void sortColors(vector<int>& nums) { // T.C=O(n) , S.C=O(n)
        int n=nums.size(), start=0, end=n-1;
        vector<int> vec(n,-1); // vector of size n filled with -1 as each element
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0) // fill 0's at start of vector
            {
                vec[start]=nums[i];
                start++;
            }
            else if(nums[i]==2) // fill 2's at the end of vector
            {
                vec[end]=nums[i];
                end--;
            }
        }
        for(int i=start; i<=end; i++) // fill the remaining vector with 1's
            vec[i]=1;
        for(int i=0; i<n; i++) // copy to original vector
            nums[i]=vec[i];
    }
};