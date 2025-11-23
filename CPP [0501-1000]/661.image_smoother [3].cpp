class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(), n=img[0].size();
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
                    // decode the cell to get its original value
                    sum += img[x][y] & 255;
                    count++;
                }
                // encode the cell with its original value and its calculated average
                img[i][j] = img[i][j] | ((sum / count) << 8);
            }
        
        // decode each cell to get its calculated average value
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                img[i][j] = img[i][j] >> 8;

        return img;
    }
};
/*
# each cell value is in the range [0, 255]
# for each cell integer, the rightmost 8 bits are used to store
  the original cell value while the remaining bits are used to
  store the calculated average for that cell
*/