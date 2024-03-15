class Solution {
public:
    // T.C.=O(n^2 + q*n), S.C.=O(n^2)
    // q: size of queries[]
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        long long int totalSum = 0;

        for(vector<int>& query: queries)
        {
            int type = query[0];
            int idx = query[1];
            int val = query[2];

            // update all the cells of row with index 'idx' with value 'val'
            if(type == 0)
            {
                for(int j=0; j<n; j++)
                {
                    totalSum -= grid[idx][j];
                    grid[idx][j] = val;
                    totalSum += val;
                }
            }
            // update all the cells of col with index 'idx' with value 'val'
            else // type == 1
            {
                for(int i=0; i<n; i++)
                {
                    totalSum -= grid[i][idx];
                    grid[i][idx] = val;
                    totalSum += val;
                }
            }
        }

        return totalSum;
    }
};