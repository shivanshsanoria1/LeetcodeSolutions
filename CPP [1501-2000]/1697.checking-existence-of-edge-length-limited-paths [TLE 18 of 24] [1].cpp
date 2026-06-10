class Solution {
private:
    typedef pair<int, int> PII;

    bool dfs(vector<vector<PII>>& graph, vector<bool>& visited, int curr, int dest, int maxEdgeLen){
        if(visited[curr])
            return false;
        
        visited[curr] = true;

        if(curr == dest)
            return true;

        for(auto [nei, dist]: graph[curr])
            // run dfs() only when the edge length between 'curr' and 'nei' < maxEdgeLen
            if(dist < maxEdgeLen && dfs(graph, visited, nei, dest, maxEdgeLen))
                return true;

        return false;
    }

public:
    // T.C.=O(q*(V+E))
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // edge hash -> min edge length
        unordered_map<string, int> mp;

        // find the min edge length between 2 nodes,
        // thereby removing duplicate edges
        for(vector<int>& edge: edgeList)
        {
            int a = edge[0];
            int b = edge[1];
            int dist = edge[2];

            // to avoid duplicate hash generation
            if(a > b)
                swap(a, b);

            string hash = to_string(a) + "#" + to_string(b);

            // hash found in map
            if(mp.find(hash) != mp.end())
                mp[hash] = min(mp[hash], dist);
            // hash not found in map
            else
                mp[hash] = dist;
        }

        // build-graph
        vector<vector<PII>> graph(n);
        for(auto& [hash, dist]: mp)
        {
            int idx = hash.find('#');

            int a = stoi(hash.substr(0, idx));
            int b = stoi(hash.substr(idx + 1));

            graph[a].push_back({b, dist});
            graph[b].push_back({a, dist});
        }

        // map in no longer needed as we have already built the graph
        mp.clear();

        vector<bool> ans;

        for(vector<int>& query: queries)
        {
            int src = query[0];
            int dest = query[1];
            int maxEdgeLen = query[2];

            vector<bool> visited(n, false);

            ans.push_back(dfs(graph, visited, src, dest, maxEdgeLen));
        }

        return ans;
    }
};