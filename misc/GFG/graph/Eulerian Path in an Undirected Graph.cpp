class Solution{
public:
    int eulerPath(int V, vector<vector<int>> graph){
        // code here
        int oddDegreeCount = 0;
        for(int i=0; i<V; i++)
        {
            int degree = 0;
            for(int j=0; j<V; j++)
                if(graph[i][j] == 1)
                    degree++;
            if(degree % 2 == 1)
                oddDegreeCount++;
        }
        return oddDegreeCount == 2 ? 1 : 0;
    }
    
    /*
	# T.C.=O(V^2), S.C.=O(1)
	# The graph is connected
	# oddDegreeCount = 0 -> Euler Circuit
	# oddDegreeCount = 1 -> not possible 
	  (since, The number of vertices with odd degree in a graph is even)
	# oddDegreeCount = 2 -> Euler path
	# oddDegreeCount > 2 -> non-Eular graph
	*/
};
