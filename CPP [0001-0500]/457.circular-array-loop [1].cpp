class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, int curr, vector<int>& nums){
        visited[curr] = true;
        pathVisited[curr] = true;

        for(int nei: graph[curr])
        {
            // curr and nei must be of the same sign
            if(nums[curr] * nums[nei] < 0)
                continue;

            if(visited[nei] && pathVisited[nei])
                return true;
            if(!visited[nei] && dfs(graph, visited, pathVisited, nei, nums))
                return true;
        }

        pathVisited[curr] = false;
        return false;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
        {
            // index to jump to
            int j = i + nums[i];
            // convert the index to +ive
            if(j < 0)
                j += (-j/n)*n + n;
            // reduce the index mod n
            j %= n;
            // skip self-loops
            if(i != j)
                graph[i].push_back(j);
        }

        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false);
        for(int i=0; i<n; i++)
            if(!visited[i] && dfs(graph, visited, pathVisited, i, nums))
                return true;

        return false;
    }
};

// prerequiste: cycle detection in directed graph using DFS