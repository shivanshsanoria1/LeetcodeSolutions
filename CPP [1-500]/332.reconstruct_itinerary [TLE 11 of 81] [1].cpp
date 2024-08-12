class Solution {
private:
    int e = 0;

    void dfs(unordered_map<string, map<string, int>>& graph, vector<string>& ans, string curr){
        ans.push_back(curr);
        
        for(auto it: graph[curr])
        {
            string nei = it.first;
            if(graph[curr][nei] == 0)
                continue;

            graph[curr][nei]--;
            dfs(graph, ans, nei);
            graph[curr][nei]++;
        }

        if(ans.size() == e + 1)
            return;

        ans.pop_back();
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        e = tickets.size();
        unordered_map<string, map<string, int>> graph;
        for(vector<string>& ticket: tickets)
        {
            string a = ticket[0];
            string b = ticket[1];
            graph[a][b]++;
        }

        vector<string> ans;
        dfs(graph, ans, "JFK");
        return ans;
    }
};