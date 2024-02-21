class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int V){ // 1 based indexing
        parent.resize(V+1);
        size.resize(V+1, 1);
        for(int i=0; i<=V; i++)
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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) { // T.C.=O(n), S.C.=O(n)
        int n = edges.size();
        DisjointSet ds = DisjointSet(n);
        for(auto edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            // a and b are already in the same component
            // so the edge a--b is redundant
            if(ds.unionBySize(a, b) == false)
                return {a, b};
        }
        return {};
    }
};