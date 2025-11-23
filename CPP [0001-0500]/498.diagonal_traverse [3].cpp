class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) { // BFS, T.C.=O(m*n), S.C.=O(sqrt(n))
        int m=mat.size(), n=mat[0].size();
        queue<pair<int, int>> q;
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
                // down is only included for 0th col
                if(y == 0 && x+1 < m) 
                    q.push({x+1, y});
                // right
                if(y+1 < n)
                    q.push({x, y+1});
            }

            if(isRev)
                reverse(ans.end()-size, ans.end());
            isRev = !isRev;
        }
        return ans;
    }
};