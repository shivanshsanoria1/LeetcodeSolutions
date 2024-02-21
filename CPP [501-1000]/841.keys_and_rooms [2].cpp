class Solution {
public:
    void bfs(vector<vector<int>>& graph, vector<bool>& visited){
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int b: graph[curr])
            {
                if(visited[b]) // already visited vertex
                    continue;
                visited[b] = true;
                q.push(b);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n, false);
        bfs(rooms, visited);
        for(bool isVisited: visited)
            if(!isVisited) // unvisited room found
                return false;
        return true;
    }
};