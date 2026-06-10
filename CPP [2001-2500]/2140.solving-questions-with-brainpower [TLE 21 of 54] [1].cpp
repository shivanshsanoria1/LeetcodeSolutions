class Solution {
private:
    typedef long long int lli;

public:
    void solve(vector<vector<int>>& questions, lli& maxPts, lli currPts, int i){
        if(i >= questions.size()) // index out of bounds
        {
            maxPts = max(maxPts, currPts);
            return;
        }
        // solve the ith question
        solve(questions, maxPts, currPts + questions[i][0], i + 1 + questions[i][1]);
        // skip the ith question
        solve(questions, maxPts, currPts, i + 1);
    }

    long long mostPoints(vector<vector<int>>& questions) { // Recursion, T.C.=O(2^n)
        lli ans = 0;
        solve(questions, ans, 0, 0);
        return ans;
    }
};