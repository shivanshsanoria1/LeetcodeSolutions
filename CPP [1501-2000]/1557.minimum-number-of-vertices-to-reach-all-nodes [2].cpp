class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inDegreeZero(n, true); // initially all nodes have in-degree 0
        for(auto edge: edges) // mark the vertices with non 0 in-degree
            inDegreeZero[edge[1]] = false;
        vector<int> ans;
        for(int i=0; i<n; i++) // count the vertices with in-degree 0
            if(inDegreeZero[i])
                ans.push_back(i);
        return ans;
    }
};
/*
# just count the number of vertices with in-degree 0
# A -> B means B has now non 0 in-degree
# true: in-degree is 0, false: in-degree is not 0
*/