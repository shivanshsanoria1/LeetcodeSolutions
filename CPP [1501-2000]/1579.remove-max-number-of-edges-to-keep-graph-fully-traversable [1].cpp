class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    // 1-based indexing
    DisjointSet(int V) { 
        parent.resize(V+1);
        size.resize(V+1, 1);

        // initially every node is a parent of itself
        for(int i=0; i<=V; i++)
            parent[i] = i;
    }

    int findUltimateParent(int curr) { 
        if(curr == parent[curr])
            return curr;

        parent[curr] = findUltimateParent(parent[curr]);

        return parent[curr];
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

    // returns true if there is only 1 component or ultimate parent
    bool isConnected() {
        // num of components or ultimate parents
        int count = 0;
        for(int i=1; i<parent.size() && count <= 1; i++)
            if(parent[i] == i)
                count++;

        return count == 1 ? true: false;
    }
};

class Solution {
public:
    // T.C.=O(E), S.C.=O(n)
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) { 
        DisjointSet ds_A = DisjointSet(n);
        DisjointSet ds_B = DisjointSet(n);

        int edgesRequired = 0;

        for(vector<int>& edge: edges)
        {
            int type = edge[0];
            int a = edge[1];
            int b = edge[2];

            if(type == 3)
            {
                bool val1 = ds_A.unionBySize(a, b);
                bool val2 = ds_B.unionBySize(a, b);

                if(val1 || val2)
                    edgesRequired++;
            }
        }

        for(vector<int>& edge: edges)
        {
            int type = edge[0];
            int a = edge[1];
            int b = edge[2];

            if(type == 1 && ds_A.unionBySize(a, b))
                edgesRequired++;
            else if(type == 2 && ds_B.unionBySize(a, b))
                edgesRequired++;
        }

        return ds_A.isConnected() && ds_B.isConnected() ? edges.size() - edgesRequired : -1;
    }
};