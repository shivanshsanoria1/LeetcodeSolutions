class Solution {
public:
    // T.C.=O(e + 3*n), S.C.=O(3*n)
    // e: size of paths[]
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // build a 0-indexed graph
        vector<vector<int>> graph(n);
        for(vector<int>& path: paths)
        {
            int a = path[0], b = path[1];
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        // keeps track of color of each node
        vector<int> colors(n, 0);
        for(int i=0; i<n; i++)
        {
            // node is already colored
            if(colors[i] != 0)
                continue;

            // keeps track of colors of neighbouring nodes
            vector<bool> colorsTaken(5, false);
            for(int nei: graph[i])
                colorsTaken[colors[nei]] = true;

            // fill the curr node with a color 
            // different from its neighbours
            for(int j=1; j<=4; j++)
                if(!colorsTaken[j])
                    colors[i] = j;
        }

        return colors;
    }
};