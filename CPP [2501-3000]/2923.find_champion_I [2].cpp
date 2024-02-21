class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0; i<n; i++)
        {
            int rowSum = 0;
            for(int j=0; j<n; j++)
                rowSum += grid[i][j];
            if(rowSum == n-1)
                return i;
        }
        return -1;
    }
};
/*
# the champ team must be stronger than all the remaining (n-1) teams
# ie, ith team will be the champion if the sum of the ith row is (n-1)
*/