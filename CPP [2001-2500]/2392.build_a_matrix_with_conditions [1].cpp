class Solution {
private:
    // topological-sort using Kahn's algo.
    vector<int> toposort(int k, vector<vector<int>>& edges){
        // unordered_set<int> is used instead of vector<int> to avoid duplicate edges
        vector<unordered_set<int>> graph(k+1);
        vector<int> indegree(k+1, 0);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            // edge a->b not found in set
            if(graph[a].find(b) == graph[a].end())
            {
                graph[a].insert(b);
                indegree[b]++;
            }
        }

        queue<int> q;
        for(int i=1; i<=k; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        vector<int> nums;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            nums.push_back(curr);

            for(int nei: graph[curr])
                if(--indegree[nei] == 0)
                    q.push(nei);
        }

        return nums;
    }

public:
    // T.C.=O((k+m) + (k+n) + k^2), S.C.=O(max(k+m, k+n))
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoSortRows = toposort(k, rowConditions);
        // cycle found
        if(topoSortRows.size() < k)
            return {};

        vector<int> topoSortCols = toposort(k, colConditions);
        // cycle found
        if(topoSortCols.size() < k)
            return {};

        vector<vector<int>> grid(k, vector<int>(k, 0));
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                if(topoSortRows[i] == topoSortCols[j])
                    grid[i][j] = topoSortRows[i];

        return grid;
    }
};