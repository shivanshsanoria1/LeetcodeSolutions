class Solution {
public:
    int jump(vector<int>& nums) { // greedy
        int n= nums.size();
        int left=0, right=0;
        int count=0;
        while(right < n-1)
        {
            int longest= 0;
            for(int i=left; i<=right; i++)
                longest= max(longest, i+nums[i]);
            left= right+1;
            right= longest;
            count++;
        }
        return count;
    }
};