// DSU by Rank (with Path-Compression)
class DisjointSet{
private:
    vector<int> parent;
    vector<int> rank;

    int findUltimateParent(int curr){
        if(curr == parent[curr])
            return curr;
        
        parent[curr] = findUltimateParent(parent[curr]);
        return parent[curr];
    }

public:
    DisjointSet(int n){
        // initially every node has rank 0
        this->rank.resize(n, 0);

        this->parent.resize(n);
        // initially every node is the parent of itself
        for(int i=0; i<n; i++)
            this->parent[i] = i;
    }

    void unionByRank(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        if(ultPar_a == ultPar_b)
            return;
            
        if(rank[ultPar_a] < rank[ultPar_b])
            parent[ultPar_a] = ultPar_b;
        else if(rank[ultPar_a] > rank[ultPar_b])
            parent[ultPar_b] = ultPar_a;
        else
        {
            parent[ultPar_a] = ultPar_b;
            rank[ultPar_b]++;
        }
    }

    bool isConnected(int a, int b){
        return findUltimateParent(a) == findUltimateParent(b);
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);

        for(vector<int>& edge: edges)
            ds.unionByRank(edge[0], edge[1]);
        
        return ds.isConnected(source, destination);
    }
};