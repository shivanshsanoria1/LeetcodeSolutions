class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    // Constructor
    DisjointSet(int n){
        this->parent.resize(n+1);
        // initially, every node is a parent of itself
        for(int i=0; i<=n; i++)
            this->parent[i] = i;

        // initially, size of each component
        // with ultimate-parent i is 1
        this->size.resize(n+1, 1);
    }

    int findUltimateParent(int curr){
        if(parent[curr] == curr)
            return curr;

        parent[curr] = findUltimateParent(parent[curr]);

        return parent[curr];
    }

    // returns false if 'a' and 'b' are in the same component
    bool unionBySize(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        if(ultPar_a == ultPar_b)
            return false;

        if(size[ultPar_a] < size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] >= size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }

        return true;
    }

    // returns true if 'a' and 'b' are in same component
    bool areConnected(int a, int b){
        return findUltimateParent(a) == findUltimateParent(b);
    }
};

class Solution {
public:
    // T.C.=O(n^2*log(n) + q)
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSet ds(n);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i != j && __gcd(i, j) > threshold)
                    ds.unionBySize(i, j);
        
        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            int a = query[0];
            int b = query[1];
            ans.push_back(ds.areConnected(a, b));
        }

        return ans;
    }
};