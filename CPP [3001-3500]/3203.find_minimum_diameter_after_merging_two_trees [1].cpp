class Solution {
private:
    // returns the farthest leaf-node starting from the source node
    int bfs(vector<vector<int>>& graph, int src){
        queue<pair<int, int>> q;
        q.push({src, -1});
        int leaf = -1;

        while(!q.empty())
        {
            auto [curr, parent] = q.front();
            q.pop();

            for(int nei: graph[curr])
                if(nei != parent)
                    q.push({nei, curr});

            leaf = curr;
        }

        return leaf;
    }

    // returns the distance (num of edges) in the path 
    // from source to destinantion node
    int findDistance(vector<vector<int>>& graph, int src, int dest){
        queue<pair<int, int>> q;
        q.push({src, -1});
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto [curr, parent] = q.front();
                q.pop();

                if(curr == dest)
                    return level;

                for(int nei: graph[curr])
                    if(nei != parent)
                        q.push({nei, curr});
            }
            
            level++;
        }

        return -1;
    }

    // returns the diameter (longest path between any 2 nodes) 
    // of the tree represented by the edges[]
    int findDiameter(vector<vector<int>>& edges){
        // size of edges is (n-1)
        int n = edges.size() + 1;

        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int x = bfs(graph, 0);
        int y = bfs(graph, x);

        return findDistance(graph, x, y);
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameter1 = findDiameter(edges1);
        int diameter2 = findDiameter(edges2);

        int radius1 = (diameter1 + 1)/2;
        int radius2 = (diameter2 + 1)/2;

        return max(max(diameter1, diameter2), radius1 + 1 + radius2);
    }
};
/*
# diameter: longest path (max num of edges) between any 2 nodes
# radius = diameter % 2 == 0 ? diameter/2 : (diameter + 1)/2  

# to find the diameter:
  (1) start at any node (say, 0) and find the farthest node from it (say, X)
  (2) start at the node X and find the farthest node from it (say, Y)
  (3) find the distance between the nodes X and Y

# to minimize the diameter of the tree formed by connecting
  a node from tree1 (say, C1) to a node in tree2 (say, C2):
  C1 and C2 must be the centers of tree1 and tree2 respectively 

# when the central nodes C1 and C2 are connected then the 
  length of the longest path containing them is (radius1 + 1 + radius2),
  here, +1 is done due to the new edge used to connect C1 and C2
  
# the diameter of the final tree is:
  max(diameter1, diameter2, radius1 + 1 + radius2)
*/