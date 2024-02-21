class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) { // BFS (Kahn's algo.)
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0); // to store the inDegree of each vertex, initially 0
        for(auto it: prerequisites) // build graph
        {
            int a = it[0];
            int b = it[1];
            graph[b].push_back(a); // edge from b to a
            inDegree[a]++; // increment the inDegree of a
        }

        queue<int> q;
        for(int i=0; i<inDegree.size(); i++)
            if(inDegree[i] == 0) // push the vertices with inDegree 0 in the queue
                q.push(i);
        vector<int> ans;
        int count=0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            ans.push_back(curr);
            for(int v: graph[curr]) // for each neighbouring vertex of the curr vertex
            {
                inDegree[v]--; // decrement the inDegree of the neighbouring vertex
                if(inDegree[v] == 0) // if inDegree becomes 0 then push that vertex in the queue
                    q.push(v);
            }
        }
        // num of vertices popped from queue is not equal to the total num of vertices
        if(count != numCourses) // graph is not a DAG (Directed Acyclic Graph)
            ans.clear();
        return ans;
    }
};
/*
# here, a -> b: means course a must be taken before course b
# Kahn’s algo. for Topological Sorting is used here
# for Topological Sort the graph must be DAG (Directed Acyclic Graph)
*/