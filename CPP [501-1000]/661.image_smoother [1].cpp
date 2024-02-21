class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(), n=img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int sum = 0, count = 0;
                for(auto [dx, dy]: dirs)
                {
                    int x = i + dx, y = j + dy;
                    // index out of bounds
                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    sum += img[x][y];
                    count++;
                }
                ans[i][j] = sum / count;
            }

        return ans;
    }
};