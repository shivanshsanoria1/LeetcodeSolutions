class Solution {
public:
    void shiftKTimes(vector<int>& arr, int k){
        // reverse the entire array
        reverse(arr.begin(), arr.end());
        // reverse the array from 0 to k-1
        reverse(arr.begin(), arr.begin() + k);
        // reverse the array from k to n-1
        reverse(arr.begin() + k, arr.end());
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        k %= m*n; // reduce k in range [0, m*n)
        vector<int> temp;
        // map 2d array to an 1d array
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                temp.push_back(grid[i][j]);
        shiftKTimes(temp, k);
        // map 1d array back to 2d array
        for(int i=0; i<m*n; i++)
            grid[i / n][i % n] = temp[i];
        return grid;
    }
};