class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) { // T.C= O((m*n)^2)
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0)); // m*n grid filled with 0's
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                    continue;
                int minDist = INT_MAX;
                for(int k=0; k<m; k++)
                    for(int l=0; l<n; l++)
                        if(mat[k][l] == 0)
                        {
                            int currDist = abs(k-i) + abs(l-j);
                            minDist = min(minDist, currDist);
                        }
                dist[i][j] = minDist;
            }
        return dist;
    }
};