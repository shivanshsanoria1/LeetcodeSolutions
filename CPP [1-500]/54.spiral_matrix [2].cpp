class Solution {
private:
    #define MARK 1000

    void restoreMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++)
                matrix[i][j] -= MARK;
    }

public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        // right, down, left, up
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // directional index
        int i = 0;
        // curr coordinates
        int currX = 0, currY = 0;

        vector<int> ans;
        while(ans.size() < m*n)
        {
            ans.push_back(matrix[currX][currY]);
            // mark the curr cell as visited
            matrix[currX][currY] += MARK;

            // next possible coordinates
            int nextX = currX + dirs[i].first;
            int nextY = currY + dirs[i].second;
            
            // change the direction if the next coordinates reach out of bounds
            // or is already visited
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || matrix[nextX][nextY] >= MARK)
                i = (i + 1) % 4;

            // update the curr coordinates
            currX += dirs[i].first;
            currY += dirs[i].second;
        }

        restoreMatrix(matrix); // not required

        return ans;
    }
};