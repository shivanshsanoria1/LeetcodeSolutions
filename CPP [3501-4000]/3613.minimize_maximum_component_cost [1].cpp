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
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // sort edges in increasing order of weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        DisjointSet ds(n);
        int componentCount = n;
        int ans = 0;

        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            // a and b are in the same component
            // so we don't include this edge
            if(!ds.unionBySize(a, b))
                continue;
            
            // a and b are in different components
            // so we include this edge and thus
            // the num of components is decremented by 1

            if(--componentCount >= k)
                ans = wt;
            else
                break;
        }

        return ans;
    }
};