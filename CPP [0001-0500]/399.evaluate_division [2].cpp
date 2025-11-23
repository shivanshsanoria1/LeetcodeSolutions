class Solution {
private:
    typedef pair<string, double> PI;

public:
    // returns true if target string is reachable from curr string, false otherwise
    bool dfs(unordered_map<string, vector<PI>>& graph, unordered_set<string>& visited, string& curr, string& target, double& mul){
        if(curr == target)
            return true;
        visited.insert(curr);
        for(auto [nei, wt]: graph[curr])
            // neighbour not found in set and target is found
            if(visited.find(nei) == visited.end() && dfs(graph, visited, nei, target, mul))
            {
                mul *= wt;
                return true;
            }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<PI>> graph;
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
            {
                double mul = 1;
                unordered_set<string> visited;
                bool targetFound = dfs(graph, visited, a, b, mul);
                ans[i] = targetFound ? mul : -1; 
            }
        }
        return ans;
    }
};