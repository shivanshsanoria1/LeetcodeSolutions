class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) { // T.C.=O(n^2), S.C.=O(n^2)
        int n=grid.size();
        unordered_map<string, int> mp; // stringified col -> freq
        for(int j=0; j<n; j++)
        {
            string col = ""; 
            for(int i=0; i<n; i++)
                col += to_string(grid[i][j]) + ' ';
            mp[col]++;
        }

        int count = 0;
        for(int i=0; i<n; i++)
        {
            string row = "";
            for(int j=0; j<n; j++)
                row += to_string(grid[i][j]) + ' ';
            if(mp.find(row) != mp.end()) // row found in col-map
                count += mp[row]; // add the freq from mpa into count
        }
        return count;
    }
};
/*
# conert each col to string and add it to map along with its freq
# conert each row to string and check if it is present in map, ie, corresponding col is found
# add the col's freq from map into the ans
*/