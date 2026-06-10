class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int a){
        if(visited[a]) // already visited vertex
            return;
        visited[a] = true;
        for(int b: graph[a])
            dfs(graph, visited, b);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0);
        for(bool isVisited: visited)
            if(!isVisited) // unvisited room found
                return false;
        return true;
    }
};