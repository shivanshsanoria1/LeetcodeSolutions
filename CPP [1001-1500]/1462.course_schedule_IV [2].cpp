class Solution {
public:
    vector<bool> dfs(vector<vector<int>> &graph, vector<vector<bool>> &grid, int curr)
    {
        if(grid[curr][curr]) // already visited vertex
            return grid[curr]; // return the prerequisites of curr
        grid[curr][curr] = true; // mark the curr vertex as visited
        for(int ver: graph[curr]) // direct prerequisites of curr
        {
            vector<bool> temp = dfs(graph, grid, ver);
            for(int j=0; j<temp.size(); j++)
                if(grid[ver][j]) // mark the indirect prerequisites of curr
                    grid[curr][j] = true;
        }
        return grid[curr]; // return the prerequisites of curr
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for(auto prerequisite: prerequisites) // build the graph
        {
            int a = prerequisite[0];
            int b = prerequisite[1];
            graph[b].push_back(a); // b -> a
        }

        // numCourses * numCourses grid filled with false's
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));
        for(int i=0; i<numCourses; i++)
            dfs(graph, grid, i);

        vector<bool> ans;
        for(auto query: queries)
        {
            int a = query[0];
            int b = query[1];
            // a is prerequisite of b, ie, a <- b
            ans.push_back(grid[b][a] ? true : false);
        }
        return ans;
    }
};
/*
# edge (a,b) is represented as a <- b indicates a is the prerequisite of b
# grid[i][j] indicates i needs j as prerequisite, ie, i -> j
# diagonal cells in grid[][], ie, grid[v][v] are used as visited set for vertex v
*/