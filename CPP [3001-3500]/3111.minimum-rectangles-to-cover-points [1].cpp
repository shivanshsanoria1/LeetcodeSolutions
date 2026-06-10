class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        // sort in increasing order of x-coordinates
        sort(points.begin(), points.end());

        // 1st group starts at the 0th point
        int start = points[0][0];
        int groups = 1;

        for(vector<int>& point: points)
            // new group is required
            if(point[0] - start > w)
            {
                // start index of the new group
                start = point[0];
                groups++;
            }

        return groups;
    }
};
// y-coordinate of the points is useless here