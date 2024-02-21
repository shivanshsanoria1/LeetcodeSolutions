class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        vector<unordered_set<int>> graph(n);
        for(auto& road: roads)
        {
            int a = road[0];
            int b = road[1];
            degrees[a]++;
            degrees[b]++;
            graph[a].insert(b);
            graph[b].insert(a);
        }
        int ans = 0;
        // check for all pair of verices a and b where a < b
        for(int a=0; a<n; a++)
            for(int b=a+1; b<n; b++)
            {
                if(graph[a].find(b) != graph[a].end()) // a and b have an edge between them
                    ans = max(ans, degrees[a] + degrees[b] - 1);
                else
                    ans = max(ans, degrees[a] + degrees[b]);
            }
        return ans;
    }
};
