class Solution {
private:
    int solve(vector<vector<int>>& books, int shelfWidth, int i){
        int n=books.size();
        if(i >= n)
            return 0;

        int currWidth = 0;
        int maxHeight = 0;
        int res = INT_MAX;

        for(int j=i; j<n; j++)
        {
            maxHeight = max(maxHeight, books[j][1]);

            if(currWidth + books[j][0] <= shelfWidth)
            {
                currWidth += books[j][0];
                res = min(res, maxHeight + solve(books, shelfWidth, j+1));
            }
            else
                break;
        }

        return res;
    }

public:
    // Recursion
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return solve(books, shelfWidth, 0);
    }
};
// solve(books, shelfWidth, i) means start a new shelf for the ith book