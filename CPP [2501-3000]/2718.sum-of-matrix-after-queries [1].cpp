class Solution {
public:
    // T.C.=O(q), S.C.=O(n)
    // q: size of queries[]
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_set<int> visitedRows;
        unordered_set<int> visitedCols;
        long long int totalSum = 0;

        // traversing the queries in reverse ensures we get the 
        // final value for each cell first
        for(int q=queries.size()-1; q>=0; q--)
        {
            int type = queries[q][0];
            int idx = queries[q][1];
            int val = queries[q][2];

            // update all the cells of row with index 'idx' with value 'val'
            if(type == 0)
            {
                // skip the visited row
                if(visitedRows.find(idx) != visitedRows.end())
                    continue;
                // mark the curr row as visited
                visitedRows.insert(idx);
                // for the curr row, only the cells with unvisited cols
                // contribute towards the total sum
                totalSum += val * (n - visitedCols.size());
            }
            // update all the cells of col with index 'idx' with value 'val'
            else // type == 1
            {
                // skip the visited col
                if(visitedCols.find(idx) != visitedCols.end())
                    continue;
                // mark the curr col as visited
                visitedCols.insert(idx);
                // for the curr col, only the cells with unvisited rows
                // contribute towards the total sum
                totalSum += val * (n - visitedRows.size());
            }
        }

        return totalSum;
    }
};