class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) { 
        int m=mat.size(), n=mat[0].size();
        vector<pair<int, int>> mp(m*n + 1); // idx: arr[i], mp[idx]: {i, j}
        // match each num with its corresponding coordinates
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                mp[mat[i][j]] = {i, j};
        // count of the painted cells in each row and col
        vector<int> rowCount(m, 0), colCount(n, 0);
        for(int idx=0; idx <= m*n; idx++)
        {
            auto [i, j] = mp[arr[idx]];
            rowCount[i]++;
            colCount[j]++;
            // ith row or jth col is completely painted
            if(rowCount[i] == n || colCount[j] == m)
                return idx;
        }
        return -1;
    }
};