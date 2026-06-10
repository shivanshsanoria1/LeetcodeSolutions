class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int V) { 
        parent.resize(V);
        size.resize(V, 1);

        // initially every node is a parent of itself
        for(int i=0; i<V; i++)
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

    bool areConnected(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        return ultPar_a == ultPar_b ? true : false;
    }
};

class Solution {
private:
    static bool cmp(vector<int>& edge_a, vector<int>& edge_b){
        int wt_a = edge_a[2];
        int wt_b = edge_b[2];

        return wt_a < wt_b;
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // sort edges in increasing order of wt./dist. 
        sort(edgeList.begin(), edgeList.end(), cmp);

        // add index to its corresponding query
        int q=queries.size();
        for(int i=0; i<q; i++)
            queries[i].push_back(i);

        // sort queries in increaing order of wt./dist. limit
        sort(queries.begin(), queries.end(), cmp);

        vector<bool> ans(q);
        int i = 0;
        DisjointSet ds = DisjointSet(n);

        for(vector<int>& query: queries)
        {
            int a = query[0];
            int b = query[1];
            int limit = query[2];
            int idx = query[3];

            // using disjoint-set connect each edge whose wt. < limit
            for(; i<edgeList.size() && edgeList[i][2] < limit; i++)
                ds.unionBySize(edgeList[i][0], edgeList[i][1]);

            // check if nodes 'a' and 'b' are in the same component 
            ans[idx] = ds.areConnected(a, b);

            // remove the index from each query
            query.pop_back();
        }

        return ans;
    }
};