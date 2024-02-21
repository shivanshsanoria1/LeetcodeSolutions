class Solution {
public:
    unordered_set<int> dfs(vector<vector<int>> &graph, unordered_map<int, unordered_set<int>> &mp, int curr){
        if(mp.find(curr) != mp.end()) // vertex found in map, ie, visited vertex
            return mp[curr]; // return all the prerequisites of curr
        unordered_set<int> s; // empty set
        mp[curr] = s; // insert curr vertex and empty set in map
        for(int ver: graph[curr])
        {
            mp[curr].insert(ver); // insert the direct prerequisite of curr
            unordered_set<int> temp = dfs(graph, mp, ver);
            mp[curr].insert(temp.begin(), temp.end());
        }
        return mp[curr];
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for(auto prerequisite: prerequisites) // build the graph
        {
            int a = prerequisite[0];
            int b = prerequisite[1];
            graph[b].push_back(a); // b -> a
        }

        unordered_map<int, unordered_set<int>> mp; // vertex -> {prerequisites}
        for(int i=0; i<numCourses; i++)
            dfs(graph, mp, i);
        
        vector<bool> ans;
        for(auto query: queries)
        {
            int a = query[0];
            int b = query[1];
            if(mp[b].find(a) != mp[b].end()) // 'a' found in set
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
// b -> a indicates a is the prerequisite of b