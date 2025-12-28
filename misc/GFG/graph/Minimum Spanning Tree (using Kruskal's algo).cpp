class DisjointSet
{
private:
    vector<int> parent, size;
    
public:
    DisjointSet(int V){
        parent.resize(V);
        size.resize(V, 1);
        for(int i=0; i<V; i++)
            parent[i] = i;
    }
    
    int findUltParent(int curr){ // find ultimate parent
        if(curr == parent[curr])
            return curr;
        parent[curr] = findUltParent(parent[curr]);
        return parent[curr];
    }
    
    bool unionBySize(int a, int b) 
    {
        //code here
        int ultPar_a = findUltParent(a);
        int ultPar_b = findUltParent(b);
        if(ultPar_a == ultPar_b)
            return false;
        if(size[ultPar_a] <= size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] > size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }
        return true;
    }
};

class Solution
{
private:
    typedef pair<int, pair<int, int>> PII; // {wt, {a, b}}
    
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<PII> edges;
        for(int a=0; a<V; a++)
            for(auto it: adj[a])
            {
                int b = it[0];
                int wt = it[1];
                edges.push_back({wt, {a, b}});
            }
            
        // sort the edges in increasing order of weights
        sort(edges.begin(), edges.end()); 
        
        int sumMST = 0;
        DisjointSet ds = DisjointSet(V);
        for(auto edge: edges)
        {
            int wt = edge.first;
            int a = edge.second.first;
            int b = edge.second.second;
            if(ds.unionBySize(a, b) == false)
                continue;
            sumMST += wt;
        }
        
        return sumMST;       
    }
    
    /*
    # Kruskal's algo.
    # T.C.=O(E*logE + E*logV)
    */
};