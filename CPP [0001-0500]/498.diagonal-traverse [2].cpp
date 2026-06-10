class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) { // BFS, T.C.=O(m*n), S.C.=O(m*n)
        int m=mat.size(), n=mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        visited[0][0] = true;
        q.push({0, 0});
        vector<int> ans;
        bool isRev = false;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=1; i<=size; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                ans.push_back(mat[x][y]);
                // down neighbour is unvisited
                if(x+1 < m && !visited[x+1][y]) 
                {
                    visited[x+1][y] = true;
                    q.push({x+1, y});
                }
                // right neighbour is unvisited
                if(y+1 < n && !visited[x][y+1])
                {
                    visited[x][y+1] = true;
                    q.push({x, y+1});
                }
            }

            if(isRev)
                reverse(ans.end()-size, ans.end());
            isRev = !isRev;
        }
        return ans;
    }
};