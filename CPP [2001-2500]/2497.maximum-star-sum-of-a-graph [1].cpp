class Solution {
public:
    // T.C.=O(e*log(n) + n*k*log(k)), S.C.=O(e)
    // n: size of vals[], e: size of edges[][]
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        // vector of max-heaps
        vector<priority_queue<int>> heaps(n);

        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];

            if(vals[b] >= 0)
                heaps[a].push(vals[b]);
            if(vals[a] >= 0)
                heaps[b].push(vals[a]);
        }

        int maxSum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int sum = vals[i];
            int temp_k = k;
            while(!heaps[i].empty() && temp_k--)
            {
                sum += heaps[i].top();
                heaps[i].pop();
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};