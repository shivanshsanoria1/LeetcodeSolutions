class Solution {
private:
    int dfs1(vector<vector<int>>& graph, vector<int>& dc, int curr, int parent){
        for(int child: graph[curr])
            if(child != parent)
                dc[curr] += dfs1(graph, dc, child, curr);
        
        return dc[curr];
    }

    int dfs2(vector<vector<int>>& graph, int curr, int parent, int level){
        int sum = level;

        for(int nei: graph[curr])
            if(nei != parent)
                sum += dfs2(graph, nei, curr, level + 1);
        
        return sum;
    }

    void dfs3(vector<vector<int>>& graph, vector<int>& dc, vector<int>& edgeCount, int curr, int parent){
        if(parent != -1)
        {
            int n=graph.size();
            int removedEdges = dc[curr];
            int addedEdges = n - dc[curr];
            edgeCount[curr] = edgeCount[parent] - removedEdges + addedEdges;
        }

        for(int nei: graph[curr])
            if(nei != parent)
                dfs3(graph, dc, edgeCount, nei, curr);
    }

public:
    // T.C.=O(n)
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges) 
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> dc(n, 1);
        // find the number of descendents of each node (including itself)
        dfs1(graph, dc, 0, -1);

        vector<int> edgeCount(n, 0);
        // find the edgeCount, assuming 0 as the root node
        edgeCount[0] = dfs2(graph, 0, -1, 0);

        // find the edgeCount of each node using the edgeCount of its parent
        dfs3(graph, dc, edgeCount, 0, -1);

        return edgeCount;
    }
};
/*
# T.C. = O(V+E) = O(n + n-1) = O(n)
# dc[i]: descendent count; counts the number of 
  descendents of the ith node (including itself)
# edgeCount[i]: sum of num of edges found in each path 
  from the ith node to every other node (assume i is the root node)

# NOTE that edgeCount[i] assumes the root to be 'i'
# lets inspect any general edge a<-->b
# assuming we know the edgeCount[a] and we want to calculate the edgeCount[b]
# for that we just need to subtract the count of edge a->b and add the count of edge b->a
# count of edge a->b is the size of subtree rooted at b
# similarly count of edge b->a is the size of subtree rooted at a

Eg- 
   0
 /  \
1    2
   / / \
  3 4   5
-------------------------

# all paths with 0 as root
0->1
0->2
0->2->3
0->2->4
0->2->5
total edges = 1+1+2+2+2 = 8
another way to represent edges
(0,1) -> 1
(0,2) -> 4
(2,3) -> 1
(2,4) -> 1
(2,5) -> 1
total edges = 1+4+1+1+1 = 8
-------------------------

# all paths with 1 as root
1->0
1->0->2
1->0->2->3
1->0->2->4
1->0->2->5
total edges = 1+2+3+3+3 = 12
another way to represent edges
(1,0) -> 5
(0,2) -> 4
(2,3) -> 1
(2,4) -> 1
(2,5) -> 1
total edges = 5+4+1+1+1 = 12
-------------------------

# all paths with 2 as root
2->0
2->0->1
2->3
2->4
2->5
total edges = 1+2+1+1+1 = 6
another way to represent edges
(2,0) -> 2
(0,1) -> 1
(2,3) -> 1
(2,4) -> 1
(2,5) -> 1
total edges = 2+1+1+1+1 = 8
-------------------------

# all paths with 3 as root
3->2
3->2->0
3->2->0->1
3->2->4
3->2->5
total edges = 1+2+3+2+2+2 = 10
another way to represent edges
(3,2) -> 5
(2,0) -> 2
(0,1) -> 1
(2,4) -> 1
(2,5) -> 1
total edges = 5+2+1+1+1 = 10
-------------------------

# observing the edges for 0 as root and 1 as root
(0,2) -> 4
(2,3) -> 1
(2,4) -> 1
(2,5) -> 1
remain the same, only
(0,1) -> 1 and (1,0) -> 5 are changed

# observing the edges for 0 as root and 2 as root
(0,1) -> 1
(2,3) -> 1
(2,4) -> 1
(2,5) -> 1
remain the same, only
(0,2) -> 4 and (2,0) -> 2 are changed

# observing the edges for 2 as root and 3 as root
(2,0) -> 2
(0,1) -> 1
(2,4) -> 1
(2,5) -> 1
remain the same, only
(2,3) -> 1 and (3,2) -> 5 are changed
*/