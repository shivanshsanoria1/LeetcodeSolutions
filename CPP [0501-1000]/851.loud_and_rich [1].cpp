class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<richer.size(); i++)
            graph[richer[i][1]].push_back(richer[i][0]);
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            dfs(graph, visited, i);

            int minQuiet = INT_MAX;
            int minQuietPerson = i;
            for(int j=0; j<n; j++)
                if(visited[j] && quiet[j] < minQuiet)
                {
                    minQuiet = quiet[j];
                    minQuietPerson = j;
                }
                
            ans[i] = minQuietPerson;
        }
        return ans;
    }
};
// A <- B : A is richer than B