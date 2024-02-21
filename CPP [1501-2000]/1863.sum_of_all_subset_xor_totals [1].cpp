class Solution {
public:
    vector<vector<int>> ans; //stores all subsets of array nums
    int n;
    void solve(vector<int>& nums, int i, vector<int> subset)
    {
        if(i==n)
        {
            ans.push_back(subset);
            return;
        }
        solve(nums,i+1,subset); //not including nums[i] in subset
        subset.push_back(nums[i]); //push nums[i] in subset
        solve(nums,i+1,subset); //including nums[i] in subset
    }
    
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        vector<int> subset;
        solve(nums,0,subset);
        for(int i=1; i<ans.size(); i++)
        {
            int xored=ans[i][0];
            for(int j=1; j<ans[i].size(); j++)
                xored=xored^ans[i][j];
            sum+=xored;
        }
        return sum;
    }
};