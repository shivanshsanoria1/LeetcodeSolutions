class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};
// the center node must appear in every edge