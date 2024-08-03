class Solution {
public:
    // T.C.=O(p + n*10), S.C.=O(n*10)
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> grid(n, vector<int>(11, 0));
        
        for(vector<int>& p: pick)
        {
            int player = p[0];
            int color = p[1];
            grid[player][color]++;
        }
        
        int winners = 0;
        for(int i=0; i<n; i++)
            if(*max_element(grid[i].begin(), grid[i].end()) > i)
                winners++;
        
        return winners;
    }
};
// row: player, col: color of ball