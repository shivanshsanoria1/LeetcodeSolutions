class Solution {
public:
    // T.C.=O(e*log(k) + n*k*log(k)), S.C.=O(min(e, n*k))
    // n: size of vals[], e: size of edges[][]
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        // vector of min-heaps
        vector<priority_queue<int, vector<int>, greater<int>>> heaps(n);

        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];

            if(vals[b] >= 0)
                heaps[a].push(vals[b]);
            if(vals[a] >= 0)
                heaps[b].push(vals[a]);

            if(heaps[a].size() == k+1)
                heaps[a].pop();
            if(heaps[b].size() == k+1)
                heaps[b].pop();
        }

        int maxSum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int sum = vals[i];
            while(!heaps[i].empty())
            {
                sum += heaps[i].top();
                heaps[i].pop();
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};