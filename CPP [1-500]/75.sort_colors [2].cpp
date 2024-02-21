class Solution {
public:
    void sortColors(vector<int>& nums) { // T.C=O(n) , S.C=O(1)
        int n=nums.size();
        int c0=0,c1=0,c2=0;
        for(int i=0; i<n; i++) // count the freq. of 0's,1's,2's
        {
            if(nums[i]==0)
                c0++;
            else if(nums[i]==1)
                c1++;
            else c2++;
        }
        for(int i=0; i<c0; i++)
            nums[i]=0;
        for(int i=c0; i<c0+c1; i++)
            nums[i]=1;
        for(int i=c0+c1; i<n; i++)
            nums[i]=2;
    }
};