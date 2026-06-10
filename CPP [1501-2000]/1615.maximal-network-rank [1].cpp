class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        unordered_set<string> edges;
        for(auto& road: roads)
        {
            int a = road[0];
            int b = road[1];
            degrees[a]++;
            degrees[b]++;
            if(a < b)
                edges.insert(to_string(a) + "#" + to_string(b));
            else // a > b
                edges.insert(to_string(b) + "#" + to_string(a));
        }
        int ans = 0;
        // check for all pair of verices a and b where a < b
        for(int a=0; a<n; a++)
            for(int b=a+1; b<n; b++)
            {
                if(edges.find(to_string(a) + "#" + to_string(b)) != edges.end())
                    ans = max(ans, degrees[a] + degrees[b] - 1);
                else
                    ans = max(ans, degrees[a] + degrees[b]);
            }
        return ans;
    }
};
