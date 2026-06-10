class Solution {
public:
    // T.C.=O(??), S.C.=O(1)
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // right, down, left, up
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        // num of times to move in the ith direction
        vector<int> dirSteps = {1, 1, 2, 2};

        vector<vector<int>> coordinates;
        for(int x = rStart, y = cStart, i=0; coordinates.size() < rows*cols; i = (i+1) % 4)
        {
            int steps = dirSteps[i];
            while(steps--)
            {
                if(x >= 0 && x < rows && y >= 0 && y < cols)
                    coordinates.push_back({x, y});

                auto [dx, dy] = dirs[i];
                x += dx;
                y += dy;
            }

            dirSteps[i] += 2;
        }

        return coordinates;
    }
};
/*
pattern:
pass 1: R-1, D-1, L-2, U-2
pass 2: R-3, D-3, L-4, U-4
pass 3: R-5, D-5, L-6, U-6
.
.
.
*/