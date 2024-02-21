class Solution {
public:
    // i: curr index, j: index with max score, -1 if no index exists
    int solve(vector<pair<int, int>>& vec, int i, int j){
        if(i == vec.size())
            return 0;

        int currScore = vec[i].second;
        int maxScore = j != -1 ? vec[j].second : 0;

         // max score index remains the same, ie, 'j'
        int exclude = solve(vec, i+1, j);
        // if (maxScore <= currScore) max score index is updated with curr index, ie, 'i' 
        int include = maxScore <= currScore ? currScore + solve(vec, i+1, i) : 0;

        return max(exclude, include);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) { // Recursion, T.C.=O(2^n), S.C.=O(n)
        int n=scores.size();
        vector<pair<int, int>> vec(n); // {age, score}
        for(int i=0; i<n; i++)
            vec[i] = {ages[i], scores[i]};
        // sort by age and then by score
        sort(vec.begin(), vec.end());
        return solve(vec, 0, -1);
    }
};