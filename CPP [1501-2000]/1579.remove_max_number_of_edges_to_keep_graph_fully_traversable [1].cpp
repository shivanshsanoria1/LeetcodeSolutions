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

    // returns true if there is only 1 component or ultimate parent
    bool isConnected(){
        int count = 0; // num of components or ultimate parents
        for(int i=1; i<parent.size(); i++)
            if(parent[i] == i)
                count++;
        return count == 1 ? true: false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) { // T.C.=O(E), S.C.=O(n)
        DisjointSet ds_A = DisjointSet(n);
        DisjointSet ds_B = DisjointSet(n);

        int edgesRequired = 0;

        for(auto& edge: edges)
        {
            int type = edge[0];
            int a = edge[1];
            int b = edge[2];
            if(type == 3)
            {
                bool val1 = ds_A.unionBySize(a, b);
                bool val2 = ds_B.unionBySize(a, b);
                edgesRequired += val1 || val2;
            }
        }

        for(auto& edge: edges)
        {
            int type = edge[0];
            int a = edge[1];
            int b = edge[2];
            if(type == 1 && ds_A.unionBySize(a, b) == true)
                edgesRequired++;
            else if(type == 2 && ds_B.unionBySize(a, b) == true)
                edgesRequired++;
        }

        if(ds_A.isConnected() && ds_B.isConnected())
            return edges.size() - edgesRequired;
        return -1;
    }
};