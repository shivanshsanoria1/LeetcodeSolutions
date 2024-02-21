class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& perms, vector<int>& perm, vector<bool>& visited){
        if(perm.size() == nums.size())
        {
            perms.push_back(perm);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i])
                continue;
            visited[i] = true;
            perm.push_back(nums[i]);
            solve(nums, perms, perm, visited);
            visited[i] = false;
            perm.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) { // Backtracking, T.C.=O(n*n!), S.C.=O(n)
        int n=nums.size();
        vector<vector<int>> perms;
        vector<int> perm;
        vector<bool> visited(n, false);
        solve(nums, perms, perm, visited);
        return perms;
    }
};