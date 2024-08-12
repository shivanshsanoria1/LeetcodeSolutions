class Solution {
private:
    void dfs(unordered_map<string, vector<string>>& graph, vector<string>& ans, string curr){
        while(!graph[curr].empty())
        {
            string nei = graph[curr].back();
            // remove the edge: curr -> nei
            graph[curr].pop_back();
            dfs(graph, ans, nei);
        }

        ans.push_back(curr);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for(vector<string>& ticket: tickets)
        {
            string a = ticket[0];
            string b = ticket[1];
            graph[a].push_back(b);
        }

        // sort the neighbours in decreasing order
        for(auto& it: graph)
            sort(it.second.begin(), it.second.end(), greater<string>());
        
        vector<string> ans;
        dfs(graph, ans, "JFK");
        reverse(ans.begin(), ans.end());

        return ans;
    }
};