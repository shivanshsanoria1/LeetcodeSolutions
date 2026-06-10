class Solution {
private:
    int solve(vector<vector<int>>& books, int shelfWidth, int i, vector<int>& dp){
        int n=books.size();
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int currWidth = 0;
        int maxHeight = 0;
        int res = INT_MAX;

        for(int j=i; j<n; j++)
        {
            maxHeight = max(maxHeight, books[j][1]);

            if(currWidth + books[j][0] <= shelfWidth)
            {
                currWidth += books[j][0];
                res = min(res, maxHeight + solve(books, shelfWidth, j+1, dp));
            }
            else
                break;
        }

        dp[i] = res;
        return dp[i];
    }

public:
    // T.C.=O(n * shelfWidth), S.C.=O(n)
    // Memoization
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n, -1);
        return solve(books, shelfWidth, 0, dp);
    }
};
// solve(books, shelfWidth, i, dp) means start a new shelf for the ith book