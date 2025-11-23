class Solution {
private:
    typedef pair<string, double> PI;

public:
    double bfs(unordered_map<string, vector<PI>>& graph, string& start, string& target){
        unordered_set<string> visited;
        queue<PI> q;
        visited.insert(start);
        q.push({start, 1});
        while(!q.empty())
        {
            auto [ver, val] = q.front();
            q.pop();
            for(auto [nei, wt]: graph[ver])
            {
                if(visited.find(nei) != visited.end()) // already visited neighbour
                    continue;
                visited.insert(nei);
                if(nei == target) // found the target
                    return val * wt;
                q.push({nei, val * wt});
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<PI>> graph; // a -> {b, (val of a)/(val of b)}
        for(int i=0; i<equations.size(); i++) // build graph
        {
            // edge a -> b with weight w
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            // edge a <- b with weight 1/w
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> ans(queries.size());
        for(int i=0; i<queries.size(); i++)
        {
            string a = queries[i][0], b = queries[i][1];
            // a or b not found in graph
            if(graph.find(a) == graph.end() || graph.find(b) == graph.end())
                ans[i] = -1;
            // a and b are present in graph and are equal
            else if(a == b) 
                ans[i] = 1;
            else
                ans[i] = bfs(graph, a, b);
        }
        return ans;
    }
};