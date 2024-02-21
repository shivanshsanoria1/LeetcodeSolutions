class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) { // Tabulation, T.C.=O(n^2), S.C.=O(n)
        int n=scores.size();
        vector<pair<int, int>> vec(n); // {age, score}
        for(int i=0; i<n; i++)
            vec[i] = {ages[i], scores[i]};
        // sort by age and then by score
        sort(vec.begin(), vec.end());

        // dp of size n
        vector<int> dp(n);
        // initially max score for each player is their individual score
        for(int i=0; i<n; i++)
            dp[i] = vec[i].second;
        int ans = 1;
        for(int i=0; i<n; i++)
        {
            int currScore = vec[i].second;
            for(int j=i-1; j>=0; j--)
            {
                int prevScore = vec[j].second;
                if(prevScore <= currScore)
                    dp[i] = max(dp[i], currScore + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// after sorting we need to find the increasing subsequence with max sum of scores
// dp[i]: max score possible by taking the ith player and possible players before it. 