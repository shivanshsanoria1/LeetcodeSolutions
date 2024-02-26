class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }

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
        // ith person knows the secret or not
        vector<bool> secrets(n, false);
        secrets[0] = true;
        secrets[firstPerson] = true;

        // sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(), cmp);

        int m=meetings.size();
        for(int i=0; i<m; )
        {
            // meetings in index range [startIdx, endIdx) occur at the same time
            int startIdx = i, endIdx = i+1;
            while(endIdx < m && meetings[startIdx][2] == meetings[endIdx][2])
                endIdx++;

            // build graph
            unordered_map<int, vector<int>> graph;
            for(int j=startIdx; j<endIdx; j++)
            {
                int x = meetings[j][0];
                int y = meetings[j][1];

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

            i = endIdx;
        }

        // push all the people who finally know the secret in ans
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(secrets[i])
                ans.push_back(i);

        return ans;
    }
};