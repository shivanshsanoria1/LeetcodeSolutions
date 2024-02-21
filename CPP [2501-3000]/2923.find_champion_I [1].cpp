class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        // assume all teams are champions initially
        vector<bool> champ(n, true); 
        
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                // team i is stronger and team j is weaker
                if(grid[i][j] == 1) 
                    champ[j] = false;
                // team i is weaker and team j is stronger
                else // grid[i][j] == 0
                    champ[i] = false;
            }

        for(int i=0; i<n; i++)
            if(champ[i])
                return i;
        return -1;
    }
};