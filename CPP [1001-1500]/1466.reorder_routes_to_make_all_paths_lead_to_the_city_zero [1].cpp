class Solution {
private:
    typedef pair<int, bool> PIB;

    int dfs(vector<vector<PIB>>& graph, int parent, int curr){
        int flips = 0;
        for(auto [nei, edgeExists]: graph[curr])
        {
            if(nei == parent)
                continue;

            if(edgeExists)
                flips++;
            
            flips += dfs(graph, curr, nei);
        }

        return flips;
    }

public:
    // T.C.=O(V + E), S.C.=O(V + E)
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<PIB>> graph(n);
        for(vector<int>& connection: connections)
        {
            int a = connection[0];
            int b = connection[1];
            // edge a -> b exists
            graph[a].push_back({b, true});
            // edge a <- b does not exist
            graph[b].push_back({a, false});
        }

        return dfs(graph, -1, 0);
    }
};