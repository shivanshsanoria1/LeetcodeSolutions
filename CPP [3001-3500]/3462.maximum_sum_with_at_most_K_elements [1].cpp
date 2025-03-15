class Solution {
public:
    // T.C.=O(m*n*log(n) + m*n*log(k) + k*log(k)), S.C.=O(k)
    // m: grid.size(), n: grid[0].size()
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        // min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<grid.size(); i++)
        {
            sort(grid[i].begin(), grid[i].end(), greater<int>());

            for(int j=0; j<limits[i]; j++)
            {
                pq.push(grid[i][j]);
                if(pq.size() == k+1)
                    pq.pop();
            }
        }

        long long int maxSum = 0;
        while(!pq.empty())
        {
            maxSum += pq.top();
            pq.pop();
        }

        return maxSum;
    }
};