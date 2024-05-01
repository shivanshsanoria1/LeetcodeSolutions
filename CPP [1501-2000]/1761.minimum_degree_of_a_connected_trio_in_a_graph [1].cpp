class Solution {
private:
    int checkForTrio(vector<unordered_set<int>>& graph, int a){
        int minTrioDegree = INT_MAX;

        for(int b: graph[a])
            for(int c: graph[a])
            {
                if(b == c)
                    continue;
                // no edge between b and c
                if(graph[b].find(c) == graph[b].end())
                    continue;

                int degree_a = graph[a].size();
                int degree_b = graph[b].size();
                int degree_c = graph[c].size();

                int trioDegree = degree_a + degree_b + degree_c - 6;

                minTrioDegree = min(minTrioDegree, trioDegree);
            }

        return minTrioDegree;
    }

public:
    // T.C.=O(n^3)
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // build graph
        vector<unordered_set<int>> graph(n+1);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }

        int minTrioDegree = INT_MAX;

        for(int i=1; i<=n; i++)
            minTrioDegree = min(minTrioDegree, checkForTrio(graph, i));

        return minTrioDegree == INT_MAX ? -1 : minTrioDegree;
    }
};