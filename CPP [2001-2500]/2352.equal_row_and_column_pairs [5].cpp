class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) { // T.C.=O(n^2), S.C.=O(n^2)
        int n=grid.size();
        map<vector<int>, int> mp; // row -> freq
        for(int i=0; i<n; i++)
            mp[grid[i]]++;

        int count = 0;
        for(int j=0; j<n; j++)
        {
            vector<int> col(n);
            for(int i=0; i<n; i++)
                col[i] = grid[i][j];
            count += mp[col];
        }
        return count;
    }
};
/*
# add each row and its freq in map
# for each col, find if a matching row exists in map, if yes, add its freq to ans
*/