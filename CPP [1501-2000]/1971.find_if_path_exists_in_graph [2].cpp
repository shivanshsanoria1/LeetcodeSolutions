class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { //iterative DFS, T.C.=O(n), S.C.=O(n)
        vector<vector<int>> graph(n);
        for(auto edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]); // edge from vertex a to b
            graph[edge[1]].push_back(edge[0]); // edge from vertex b to a
        }
        vector<bool> visited(n, false); // initially all nodes are unvisited
        stack<int> st;
        visited[source] = true; // mark the source node as visited
        st.push(source); // push the souce node in stack
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            if(curr == destination) // destination node found
                return true;
            for(auto ver: graph[curr]) // push the nodes conected curr node in the stack
                if(visited[ver] == false) // push only the unvisited nodes in stack
                {
                    visited[ver] = true; // mark the nodes as visited before pushing them in stack
                    st.push(ver);
                }
        }
        return false;
    }
};