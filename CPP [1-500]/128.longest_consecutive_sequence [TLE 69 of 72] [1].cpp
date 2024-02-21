class Solution {
public:
    int longestConsecutive(vector<int>& nums) { //T.C.=O(n^2)
        int n=nums.size(), max_len=1;
        if(n==0) //empty vector
            return 0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            int skip=0;
            for(int j=i+1; j<n; j++)
            {
                if(nums[j]==nums[j-1]) //skip the equal elements
                    skip++;
                else if(nums[j]-nums[j-1] != 1)
                    break;
                max_len=max(max_len,j-i+1-skip);
            }
        }
        return max_len;
    }
};