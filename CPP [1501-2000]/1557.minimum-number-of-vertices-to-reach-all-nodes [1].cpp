class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for(auto edge: edges) // find the in-degree of each vertex
            inDegree[edge[1]]++;
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(inDegree[i] == 0)
                ans.push_back(i);
        return ans;
    }
};
/*
# just count the number of vertices with in-degree 0
# A -> B means B has now non 0 in-degree
*/