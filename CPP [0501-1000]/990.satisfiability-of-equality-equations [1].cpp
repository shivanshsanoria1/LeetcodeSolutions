class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& compIds, int compId, int curr){
        if(compIds[curr] != -1)
            return;
        
        compIds[curr] = compId;

        for(int nei: graph[curr])
            dfs(graph, compIds, compId, nei);
    }

public:
    bool equationsPossible(vector<string>& equations) {
    	// build graph with the equations of type x == y
        vector<vector<int>> graph(26);
        for(string& equation: equations)
        {
            int x = equation[0] - 'a', y = equation[3] - 'a';
            // skip the equations of type x != y
            if(equation[1] == '!')
                continue;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        // assign the elements of each component a unique id
        vector<int> compIds(26, -1);
        int compId = 0;
        for(int i=0; i<26; i++)
            if(compIds[i] == -1)
            {
                dfs(graph, compIds, compId, i);
                compId++;
            }
        

        for(string& equation: equations)
        {
            int x = equation[0] - 'a', y = equation[3] - 'a';
            // skip the equations of type x == y
            if(equation[1] == '=')
                continue;
            // since x != y at this point, 
            // so they cannot be in the same component
            if(compIds[x] == compIds[y])
                return false;
        }

        return true;
    }
};