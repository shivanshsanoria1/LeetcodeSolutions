// link: "https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1"

class Solution {
private:
    #define INF int(1e9)
    
public:
    // T.C.=O(V^3), S.C.=O(V^2)
	void shortest_distance(vector<vector<int>>&matrix){
        // Code here

        int V = matrix.size();

        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                if(matrix[i][j] == -1)  
                    matrix[i][j] = INF;
        
        for(int via=0; via<V; via++)
            for(int i=0; i<V; i++)
                for(int j=0; j<V; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
        
	    for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                if(matrix[i][j] == INF)  
                    matrix[i][j] = -1;
	}
};
