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
    // T.C.=O(n + (maxX + maxY)), S.C.=O(maxX + maxY)
    // maxX, maxY: max val of stone[0] and stone[1] respectively
    int removeStones(vector<vector<int>>& stones) {
        int maxX = 0, maxY = 0;
        for(vector<int>& stone: stones)
        {
            maxX = max(maxX, stone[0]);
            maxY = max(maxY, stone[1]);
        }

        DisjointSet ds(maxX + 1 + maxY + 1);
        vector<bool> isPresent(maxX + 1 + maxY + 1, false);
        for(vector<int>& stone: stones)
        {
            int a = stone[0];
            // offset the y coordinate by (maxX + 1)
            int b = maxX + 1 + stone[1];

            ds.unionBySize(a, b);

            isPresent[a] = true;
            isPresent[b] = true;
        }

        int absentNodeCount = count(isPresent.begin(), isPresent.end(), false);
        return stones.size() - (ds.componentCount() - absentNodeCount);
    }
};

/*
# using rows and cols as nodes of a graph
# num of nodes in graph must be ((maxX + 1) + (maxY + 1))
# row coordinate remains the same for a node but, 
  col coordinate is offset by (maxX + 1)
# to get the actual component count: 
  remove the nodes which don't have any stone lying on them
*/