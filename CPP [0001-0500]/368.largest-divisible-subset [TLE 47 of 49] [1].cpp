class Solution {
private:
    void solve(vector<int>& nums, vector<int>& ans, vector<int>& currAns, int prevIdx, int i){
        if(i >= nums.size())
        {
            // new ans found
            if(currAns.size() > ans.size())
                ans = currAns;
            return;
        }
        
        // exclude
        solve(nums, ans, currAns, prevIdx, i+1); 
        
        // include
        if(prevIdx == -1 || nums[i] % nums[prevIdx] == 0)
        {
            currAns.push_back(nums[i]);
            solve(nums, ans, currAns, i, i+1);
            currAns.pop_back();
        }
    }

public:
    // T.C.=O(2^n), S.C.=O(n), recursion
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> currAns;
        solve(nums, ans, currAns, -1, 0);
        return ans;
    }
};