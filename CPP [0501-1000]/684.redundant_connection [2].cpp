class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

    int findUltimateParent(int curr){
        if(curr == parent[curr])
            return curr;
            
        parent[curr] = findUltimateParent(parent[curr]);
        return parent[curr];
    }

public:
    // 1 based indexing
    DisjointSet(int n){ 
        // initially all nodes hasve size 1
        this->size.resize(n+1, 1);

        this->parent.resize(n+1);
        // initially every node is a parent of itself
        for(int i=0; i<=n; i++)
            this->parent[i] = i;
    }

    bool unionBySize(int a, int b) {
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            // a and b are already in the same component
            // so the edge a--b is redundant
            if(!ds.unionBySize(a, b))
                return {a, b};
        }

        return {};
    }
};