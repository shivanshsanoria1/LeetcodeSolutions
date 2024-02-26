class Solution {
private:
    void bfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int start){
        queue<int> q;
        visited.insert(start);
        q.push(start);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int nei: graph[curr])
            {
                // already visited neighbour
                if(visited.find(nei) != visited.end())
                    continue;
                visited.insert(nei);
                q.push(nei);
            }
        }
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> secrets(n, false);
        secrets[0] = true;
        secrets[firstPerson] = true;

        // time -> [{x, y}]
        map<int, vector<pair<int, int>>> timeMap;

        int m=meetings.size();
        for(int i=0; i<m; i++)
        {
            int x = meetings[i][0];
            int y = meetings[i][1];
            int t = meetings[i][2];

            timeMap[t].push_back({x, y});
        }

        for(auto itt: timeMap)
        {
            // build graph
            unordered_map<int, vector<int>> graph;
            for(auto [x, y]: itt.second)
            {
                graph[x].push_back(y);
                graph[y].push_back(x);
            }

            // Multi-Source BFS
            unordered_set<int> visited;
            for(auto it: graph)
            {
                int curr = it.first;
                // already visited
                if(visited.find(curr) != visited.end())
                    continue;
                // does not know the secret
                if(!secrets[curr])
                    continue;
                bfs(graph, visited, curr);
            }
            
            // all the visited people now know the secret
            for(int person: visited)
                secrets[person] = true;
        }

        // push all the people who finally know the secret in ans
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(secrets[i])
                ans.push_back(i);

        return ans;
    }
};