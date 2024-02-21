class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(1)
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int c=0;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                if(nums[j] < nums[i])
                    c++;
            }
            ans[i]=c;
        }
        return ans;
    }
};