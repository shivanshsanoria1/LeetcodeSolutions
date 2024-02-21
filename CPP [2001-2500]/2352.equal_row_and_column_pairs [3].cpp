class Solution {
private:
    #define M 1000003 // 1000003 is a prime

public:
    // returns true if the row with index r has the same elements in the same order as the col with index c
    bool compareRowCol(vector<vector<int>>& grid, int r, int c){
        for(int k=0; k<grid.size(); k++)
            if(grid[r][k] != grid[k][c])
                return false;
        return true;
    }

    int equalPairs(vector<vector<int>>& grid) { // T.C.=O(n^3), S.C.=O(n)
        int n=grid.size();
        unordered_map<int, vector<int>> mp1; // row product -> {row indexes}
        for(int i=0; i<n; i++)
        {
            long long int pro = 1;
            for(int j=0; j<n; j++)
                pro = (pro * grid[i][j]) % M;
            mp1[pro].push_back(i);
        }
        unordered_map<int, vector<int>> mp2; // col product -> {col indexes}
        for(int j=0; j<n; j++)
        {
            long long int pro = 1;
            for(int i=0; i<n; i++)
                pro = (pro * grid[i][j]) % M;
            mp2[pro].push_back(j);
        }
        
        int count = 0;
        for(auto it: mp1)
        {
            int rowPro = it.first;
            // row product is equal to col product
            if(mp2.find(rowPro) != mp2.end()) // row sum found in mp2
            {
                vector<int> rows = it.second;
                vector<int> cols = mp2[rowPro];
                for(int r: rows)
                    for(int c: cols)
                        if(compareRowCol(grid, r, c))
                            count++;
            }
        }
        return count;
    }
};
/*
# basic idea is to compare a row with a col only if they have the same product
# T.C.=O(n^3), but better than brute force, worst case happens when all rows and cols have the same product
*/