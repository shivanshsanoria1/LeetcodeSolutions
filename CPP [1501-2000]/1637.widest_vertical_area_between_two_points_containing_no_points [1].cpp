class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxDiff = 0;
        for(int i=1; i<points.size(); i++)
            maxDiff = max(maxDiff, points[i][0] - points[i-1][0]);
        return maxDiff;
    }
};