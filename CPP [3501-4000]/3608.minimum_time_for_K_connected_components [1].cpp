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

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if(edges.size() == 0)
            return 0;

        // sort edges in decreasing order of time
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        });

        DisjointSet ds(n);
        // assume initially all nodes are disconnected
        int compCount = n;
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int time = edge[2];

            // a and b are in diff components so unioning 
            // them would decrement the component count by 1
            if(ds.unionBySize(a, b))
                compCount--;

            if(compCount < k)
                return time;
        }

        return 0;
    }
};