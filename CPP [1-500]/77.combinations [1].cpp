class Solution {
public:
    void solve(vector<vector<int>>& combs, vector<int>& comb, int n, int k, int curr){
        if(comb.size() == k)
        {
            combs.push_back(comb);
            return;
        }
        for(int i=curr + 1; i<=n; i++)
        {
            comb.push_back(i);
            solve(combs, comb, n, k, i);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) { // Backtracking
        vector<vector<int>> combs;
        vector<int> comb;
        solve(combs, comb, n, k, 0);
        return combs;
    }
};
// the number of combinations will be nCk = n! / (k!*(n-k)!)