class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];

        return x1 == x2 ? y1 < y2 : x1 < x2;
    }

    // let A(x1, y1), B(x2, y2), C(x3, y3) be the points 
    // at index i1, i2, i3 respectively
    // returns the value of cross-product of the vectors AB-> X BC->
    // +ive: CCW, -ive: CW, 0: collinear
    int crossProduct(vector<vector<int>>& trees, int i1, int i2, int i3){
        int x1 = trees[i1][0], y1 = trees[i1][1];
        int x2 = trees[i2][0], y2 = trees[i2][1];
        int x3 = trees[i3][0], y3 = trees[i3][1];

        return (x2-x1)*(y3-y2) - (x3-x2)*(y2-y1);
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // Monotone-Chain (for Convex-Hull)
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // sort points in increasing order of x-coordinate and 
        // in increasing order of y-coordinate (if x-coordinates are equal)
        sort(trees.begin(), trees.end(), cmp);

        int n = trees.size();

        // index of the points forming the upper and lower part of convex-hull
        // with respect to the line formed by joining the first and last points, 
        // ie, points[0] and points.back()
        vector<int> upper;
        vector<int> lower;

        for(int i=0; i<n; i++)
        {
            // keep removing the last point as long as the 2 previously selected points
            // and the curr point make a CCW turn
            while(upper.size() >= 2 && 
            crossProduct(trees, upper[upper.size()-2], upper[upper.size()-1], i) > 0)
                upper.pop_back();
            upper.push_back(i);

            // keep removing the last point as long as the 2 previously selected points
            // and the curr point make a CW turn
            while(lower.size() >= 2 && 
            crossProduct(trees, lower[lower.size()-2], lower[lower.size()-1], i) < 0)
                lower.pop_back();
            lower.push_back(i);
        }

        // inConvexHull[i]: point at index i is a part of convex-hull or not
        vector<bool> inConvexHull(n, false);
        // mark the points in upper and lower halves as a part of the final convex-hull
        for(int i: upper)
            inConvexHull[i] = true;
        for(int i: lower)
            inConvexHull[i] = true;
        
        vector<vector<int>> convexHull;
        for(int i=0; i<n; i++)
            if(inConvexHull[i])
                convexHull.push_back(trees[i]);

        return convexHull;
    }
};

/*
for 3 points A(x1, y1), B(x2, y2), C(x3, y3)
the cross-product AB-> X BC-> is given by the determinant:

|    i       j    k |
| (x2-x1) (y2-y1) 0 |
| (x3-x2) (y3-y2) 0 |

= (x2-x1)*(y3-y2) - (x3-x2)*(y2-y1)
*/