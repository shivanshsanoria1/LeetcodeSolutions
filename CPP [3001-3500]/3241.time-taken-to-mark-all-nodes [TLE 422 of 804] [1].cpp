class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& visitedTime, int curr, int parent_time){
        if(visitedTime[curr] != -1)
            return;
        
        visitedTime[curr] = curr % 2 == 0 ? parent_time + 2 : parent_time + 1;
        
        for(int nei: graph[curr])
            dfs(graph, visitedTime, nei, visitedTime[curr]);
    }
    
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n=edges.size() + 1;
        vector<vector<int>> graph(n);
        
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> times(n);
        for(int i=0; i<n; i++)
        {
            vector<int> visitedTime(n, -1);

            if(i % 2 == 0)
                dfs(graph, visitedTime, i, -2);
            else
                dfs(graph, visitedTime, i, -1);
            
            times[i] = *max_element(visitedTime.begin(), visitedTime.end());
        }
        
        return times;
    }
};