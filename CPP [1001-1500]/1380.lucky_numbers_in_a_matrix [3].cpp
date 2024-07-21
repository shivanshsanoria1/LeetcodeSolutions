class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    // Greedy
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        // max-element from the min-elements from each row
        int maxOfRowMins = 0;
        // index of col of 'maxOfRowMins'
        int colIdx = -1;
        for(int i=0; i<m; i++)
        {
            // find the min-element from ith row
            int rowMin = INT_MAX;
            for(int j=0; j<n; j++)
                rowMin = min(rowMin, matrix[i][j]);

            // index of col of 'rowMin'
            int idx = -1;
            for(int j=0; j<n; j++)
                if(rowMin == matrix[i][j])
                    idx = j;

            // new 'maxOfRowMins' found
            if(rowMin > maxOfRowMins)
            {
                maxOfRowMins = rowMin;
                colIdx = idx;
            }
        }

        // find the max-element in col at index 'colIdx'
        int maxInCol = 0;
        for(int i=0; i<m; i++)
            maxInCol = max(maxInCol, matrix[i][colIdx]);

        // 'maxOfRowMins' can only be a Lucky-number if 
        // it is also the max-element in its col
        vector<int> ans;
        if(maxOfRowMins == maxInCol)
            ans.push_back(maxOfRowMins);

        return ans;
    }
};
/*
# given:
  # Lucky num: min in row and max in col 
  # All elements in the matrix are distinct

# hypothesis: there can only be 0 or 1 Lucky-nums

Proof by contradiction:
# assumption: there are 2 Lucky-nums L1, L2
# let:
  # grid is of size 6*5
  # L1 is at (2,1) and L2 at (4,3)
  # '@' represent any general num in grid
  # 'X' represent non-Lucky num

   0  1  2  3  4
0  @  @  @  @  @
1  @  @  @  @  @
2  @  L1 @  @  @
3  @  @  @  @  @
4  @  @  @  L2 @
5  @  @  @  @  @

# any num in the same row and col as L1 cannot be Lucky

   0  1  2  3  4
0  @  X  @  @  @
1  @  X  @  @  @
2  X  L1 X  X  X
3  @  X  @  @  @
4  @  X  @  @  @
5  @  X  @  @  @

# elements in row-2 must be >L1 (as L1 is the min in row-2)
# elements in col-1 must be <L1 (as L1 is the max in col-1)

# similarly, any num in the same row and col as L2 cannot be Lucky

   0  1  2  3  4
0  @  X  @  X  @
1  @  X  @  X  @
2  X  L1 X  X  X
3  @  X  @  X  @
4  X  X  X  L2 X
5  @  X  @  X  @

# elements in row-4 must be >L2 (as L2 is the min in row-4)
# elements in col-3 must be <L2 (as L2 is the max in col-3)

# Thus,
# L2 < element at (4,1) < L1, ie, L2 < L1
# L1 < element at (2,3) < L2, ie, L1 < L2
# But these above equations cannot be true simultanously
# Therefore our assumption that there can be 2 Lucky-nums is incorrect

# Examples:
  # Case of 1 Lucky num (12)
    1  10 4  2
    9  3  8  7
    15 16 17 12

  # Case of 0 Lucky num 
    1  10 4  21
    9  3  8  71
    15 16 17 12

*/