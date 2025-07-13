class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& compIds, int curr, int compId){
        if(compIds[curr] != -1)
            return;

        compIds[curr] = compId;

        for(int nei: graph[curr])
            dfs(graph, compIds, nei, compId);
    }

public:
    // T.C.=O((n+e) + n*log(n) + q*log(n)), S.C.=O(n+e)
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int n = c;
        // step 1: build the graph
        vector<vector<int>> graph(n+1);
        for(vector<int>& connection: connections)
        {
            int a = connection[0];
            int b = connection[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // step 2: assign each node its corresponding component id
        vector<int> compIds(n+1, -1);
        int compId = 0;
        for(int i=1; i<=n; i++)
        {
            if(compIds[i] != -1)
                continue;
            dfs(graph, compIds, i, compId);
            compId++;
        }

        // step 3: map each component id with 
        // the online nodes in that component
        vector<set<int>> compId_onlineNodes(compId);
        for(int i=1; i<=n; i++)
        {
            int compId = compIds[i];
            compId_onlineNodes[compId].insert(i);
        }

        // step 4: fill ans[] according to queries[]
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int type = query[0];
            int i = query[1];

            int compId = compIds[i];

            // mark the ith node as offline
            if(type == 2)
            { 
                compId_onlineNodes[compId].erase(i);
                continue;
            }

            // ith node is online
            if(compId_onlineNodes[compId].find(i) != compId_onlineNodes[compId].end())
                ans.push_back(i);
            // ith node is offline so
            // find the smallest online node in that component (if exists)
            else if(!compId_onlineNodes[compId].empty())
                ans.push_back(*compId_onlineNodes[compId].begin());
            else
                ans.push_back(-1);
        }

        return ans;
    }
};