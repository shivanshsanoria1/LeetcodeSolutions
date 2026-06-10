class Solution {
private:
    typedef long long int lli;

public:
    lli dfs(vector<vector<int>>& questions, int i){
        if(i >= questions.size()) // index out of bounds
            return 0;
        // solve the ith question
        lli solve = questions[i][0] + dfs(questions, i + 1 + questions[i][1]);
        // skip the ith question
        lli skip = dfs(questions, i + 1);
        return max(solve, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) { // Recursion, T.C.=O(2^n)
        return dfs(questions, 0);
    }
};