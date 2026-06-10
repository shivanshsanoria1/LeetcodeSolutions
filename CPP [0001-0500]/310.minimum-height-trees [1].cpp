class Solution {
public:
    // T.C.=O(n)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // graph with only 1 node with no edges
        if(n == 1)
            return {0};

        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges) 
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // calculate the degree of each node and 
        // push the nodes with degree 1 in queue
        queue<int> q;
        vector<int> degrees(n, 0);
        for(int i=0; i<n; i++)
        {
            degrees[i] = graph[i].size();
            if(degrees[i] == 1)
                q.push(i);
        }

        // initially all nodes are unvisited
        int unvisited = n;
        
        while(!q.empty() && unvisited > 2)
        {
            int size = q.size();

            while(size--)
            {
                int curr = q.front();
                q.pop();

                unvisited--;

                for(int nei: graph[curr])
                {
                    degrees[nei]--;
                    if(degrees[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
/*
# MHT: Minimum Height Tree
# MHT can only have 1 or 2 roots 
# approach is similar to Kahn's algo. for Topological-sort
*/