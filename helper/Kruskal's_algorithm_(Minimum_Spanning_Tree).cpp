#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    // Constructor
    DisjointSet(int n){
        this->parent.resize(n);
        // initially, every node is a parent of itself
        for(int i=0; i<n; i++)
            this->parent[i] = i;

        // initially, size of each component
        // with ultimate-parent i is 1
        this->size.resize(n, 1);
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

    // num of components is given by
    // num of distinct ultimate-parents
    int componentCount(){
        int n = parent.size();
        unordered_set<int> ultPars;

        for(int i=0; i<n; i++)
            ultPars.insert(findUltimateParent(i));

        return ultPars.size();
    }
};

int minimumSpanningTree(int V, vector<vector<int>>& edges, vector<vector<int>>& mst){
    // sort in increasing order of edge weights
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });
    
    int sumMst = 0;
    DisjointSet ds(V);
    
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        
        // a and b belong to the same component
        if(ds.unionBySize(a, b))
        {
            sumMst += wt;
            mst.push_back({a, b, wt});
        }
    }
    
    return sumMst;
}

// --------------- END --------------- //

int main() {
    int V = 5;
    // edge: {a, b, wt}
    vector<vector<int>> edges = { {0,1,2}, {0,2,1}, {1,2,1}, {2,3,2}, {2,4,2}, {3,4,1} };
    
    vector<vector<int>> mst;
    int sumMST = minimumSpanningTree(V, edges, mst);
    
    cout<<"MST weight = "<<sumMST<<endl;
    cout<<"MST is: "<<endl;
    for(vector<int>& edge: mst)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        
        if(a > b)
            swap(a, b);
        cout<<a<<" - "<<b<<" | "<<wt<<endl;
    }
    
    cout<<"--------------------"<<endl;

    return 0;
}