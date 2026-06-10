class Solution {
public:
    int longestConsecutive(vector<int>& nums) { //T.C.=O(nlogn)
        int n=nums.size();
        if(n==0) //empty vector
            return 0;
        int max_len=1, curr_len=1;
        sort(nums.begin(),nums.end());
        for(int i=1; i<n; i++)
        {
            if(nums[i]==nums[i-1]) //skip the equal elements
                continue;
            if(nums[i]-nums[i-1]==1)
                curr_len++;
            else 
                curr_len=1; //reset the curr length
            max_len=max(max_len,curr_len);
        }
        return max_len;
    }
};