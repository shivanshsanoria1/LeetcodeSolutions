class Solution {
private:
    void solve(vector<int>& ans, int n, int curr){
        if(curr > n)
            return;
        ans.push_back(curr);
        solve(ans, n, 10*curr);
        if(curr % 10 < 9)
            solve(ans, n, curr + 1);
    }

public:
    // T.C.=O(n), S.C.=O(1), recursion
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        solve(ans, n, 1);
        return ans;
    }
};