class Solution
{
private:
    typedef pair<int, int> PI; // {wt, b}

public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> visited(V, false);
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        pq.push({0, 0});
        int sumMST = 0;
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(visited[curr])
                continue;
            visited[curr] = true;
            sumMST += wt;
            for(auto it: adj[curr])
            {
                int nei = it[0];
                int wt = it[1];
                if(visited[nei])
                    continue;
                pq.push({wt, nei});
            }
        }
        return sumMST;
    }
    
    /*
    # Prim's algo.
    # T.C.=O(E*logE), S.C=O(E)
    # based on greedy approach
    */
};
