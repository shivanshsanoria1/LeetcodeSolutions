class Solution {
private:
    int bfs(vector<vector<int>>& graph, int edgeTime, int change){
        int n=graph.size()-1;
        // time at which a node is visited for the 1st time
        vector<int> visitedTime1(n+1, -1);
        // time at which a node is visited for the 2nd DISTINCT time
        vector<int> visitedTime2(n+1, -1);
        int currTime = 0;
        queue<int> q;
        visitedTime1[1] = currTime;
        q.push(1);

        while(!q.empty())
        {
            bool isGreen = (currTime/change) % 2 == 0;
            int waitingTime = isGreen ? 0 : (currTime/change + 1)*change - currTime;
            currTime += edgeTime + waitingTime;

            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();

                // reached the destination for the 2nd distinct time
                if(curr == n && visitedTime2[curr] != -1) 
                    return visitedTime2[curr];

                for(int nei: graph[curr])
                {
                    // 'nei' is being visited for the 1st time
                    if(visitedTime1[nei] == -1)
                    {
                        visitedTime1[nei] = currTime;
                        q.push(nei);
                    }
                    // 'nei' is being visited for the 2nd distinct time
                    else if(visitedTime2[nei] == -1 && visitedTime1[nei] != currTime)
                    {
                        visitedTime2[nei] = currTime;
                        q.push(nei);
                    }
                }
            }
        }   

        return -1;
    }

public:
    // T.C.=O(V + E)
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // build graph
        vector<vector<int>> graph(n+1);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        return bfs(graph, time, change);
    }
};
/*
# path length = num of edges between 2 nodes
# 2nd min distinct path length = min path length + 1
                                 or
                               = min path length + 2

# Case 1: 2nd distinct min path length = min path length + 1
  # this happens when some alternate path exists (with 1 extra node)
  # 1 - 2 - 3 - 5
        |   |    
        - 4 -
    here, src = 1, dest = 5
    min path length = 3 (1,2,3,5)
    2nd min distinct path length = 4 (1,2,4,3,5)

# Case 2: 2nd distinct min path length = min path length + 2
  # Case 2.1: this happens when some alternate path exists (with 2 extra nodes)
    # 1 - 2 - 3 - 6
          |   |    
          4 - 5
      here, src = 1, dest = 6
      min path length = 3 (1,2,3,6)
      2nd min distinct path length = 5 (1,2,4,5,3,6)

  # Case 2.2: this happens when any 2 nodes are visited twice in the min path
    # 1 - 2 - 3 - 4 - 5
          |   |    
          - - -
      here, src = 1, dest = 5
      min path length = 4 (1,2,3,4,5)
      2nd min distinct path length = 6 (1,2,3,2,3,4,5)
*/