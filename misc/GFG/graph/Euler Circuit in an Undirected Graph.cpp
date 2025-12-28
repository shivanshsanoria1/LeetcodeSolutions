class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    // Code here
	    int oddDegreeCount = 0;
        for(int i=0; i<V; i++)
            if(adj[i].size() % 2 == 1)
                oddDegreeCount++;
        return oddDegreeCount == 0 ? true : false;
	}
    
    /*
	# T.C.=O(V), S.C.=O(1)
	# The graph is connected
	# oddDegreeCount = 0 -> Euler Circuit
	# oddDegreeCount = 1 -> not possible 
	  (since, The number of vertices with odd degree in a graph is even)
	# oddDegreeCount = 2 -> Euler path
	# oddDegreeCount > 2 -> non-Eular graph
	*/
};
