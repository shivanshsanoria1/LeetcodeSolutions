class Solution {
public:
    // i: curr index, j: index with max score, -1 if no index exists
    int solve(vector<pair<int, int>>& vec, vector<vector<int>>& dp, int i, int j){
        if(i == vec.size())
            return 0;

        if(dp[i][j+1] != -1) // result already in dp
            return dp[i][j+1];

        int currScore = vec[i].second;
        int maxScore = j != -1 ? vec[j].second : 0;

        // max score index remains the same, ie, 'j'
        int exclude = solve(vec, dp, i+1, j);
        // if (maxScore <= currScore) max score index is updated with curr index, ie, 'i' 
        int include = maxScore <= currScore ? currScore + solve(vec, dp, i+1, i) : 0;

        dp[i][j+1] = max(exclude, include); // store the result in dp
        return dp[i][j+1]; 
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) { // Memoization, T.C.=O(n^2), S.C.=O(n^2)
        int n=scores.size();
        vector<pair<int, int>> vec(n); // {age, score}
        for(int i=0; i<n; i++)
            vec[i] = {ages[i], scores[i]};
        // sort by age and then by score
        sort(vec.begin(), vec.end());
        // dp of size n*(n+1) filled with -1's
        vector<vector<int>> dp(n, vector(n+1, -1));
        return solve(vec, dp, 0, -1);
    }
};
// j is taken in range [0,n] instead of [0,n-1] to accomodate j = -1