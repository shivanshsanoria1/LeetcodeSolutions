class Solution {
private:
    int solve(int i, int day, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore){
        if(day == k)
            return 0;

        int stay = stayScore[day][i] + solve(i, day + 1, k, stayScore, travelScore);

        int move = 0;
        for(int j=0; j<travelScore.size(); j++)
            move = max(move, travelScore[i][j] + solve(j, day + 1, k, stayScore, travelScore));

        return max(stay, move);
    }

public:
    // T.C.=O(n^k), S.C.=O(k)
    // Recursion
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, solve(i, 0, k, stayScore, travelScore));

        return ans;
    }
};

// stayScore[][] is of size k*n
// travelScore[][] is of size n*n