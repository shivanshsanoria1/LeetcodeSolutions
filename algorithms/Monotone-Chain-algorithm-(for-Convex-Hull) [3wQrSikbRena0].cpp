#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

// let A(x1, y1), B(x2, y2), C(x3, y3) be the points 
// at index i1, i2, i3 respectively
// returns the value of cross-product of the vectors AB-> X BC->
// +ive: CCW, -ive: CW, 0: collinear
int crossProduct(vector<pair<int, int>>& points, int i1, int i2, int i3){
    auto [x1, y1] = points[i1];
    auto [x2, y2] = points[i2];
    auto [x3, y3] = points[i3];

    return (x2-x1)*(y3-y2) - (x3-x2)*(y2-y1);
}

// Monotone-Chain algo. 
// T.C.=O(n*log(n)), S.C.=O(n)
vector<pair<int, int>> convexHull(vector<pair<int, int>>& points){
    // sort points in increasing order of x-coordinate and 
    // in increasing order of y-coordinate (if x-coordinates are equal)
    sort(points.begin(), points.end());
    
    int n = points.size();
    
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
        crossProduct(points, upper[upper.size()-2], upper[upper.size()-1], i) > 0)
            upper.pop_back();

        upper.push_back(i);

        // keep removing the last point as long as the 2 previously selected points
        // and the curr point make a CW turn
        while(lower.size() >= 2 && 
        crossProduct(points, lower[lower.size()-2], lower[lower.size()-1], i) < 0)
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
    
    vector<pair<int, int>> convexHullPoints;
    for(int i=0; i<n; i++)
        if(inConvexHull[i])
            convexHullPoints.push_back(points[i]);

    return convexHullPoints;
}

// --------------- END --------------- //

int main() {
    vector<pair<int, int>> points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    
    vector<pair<int, int>> convexHullPoints = convexHull(points);
    
    cout<<"Points forming the Convex-Hull are: "<<endl;
    
    for(auto [px, py]: convexHullPoints)
        cout<<"("<<px<<", "<<py<<"), ";
    
    cout<<endl<<"--------------------"<<endl;

    return 0;
}

/*
# for 3 points A(x1, y1), B(x2, y2), C(x3, y3)
  # equation of vector AB-> is: (x2-x1)i + (y2-y1)j
  # equation of vector BC-> is: (x3-x2)i + (y3-y2)j
  # the cross-product AB-> X BC-> is given by the determinant:

  |    i       j    k |
  | (x2-x1) (y2-y1) 0 | = ((x2-x1)*(y3-y2) - (x3-x2)*(y2-y1))k 
  | (x3-x2) (y3-y2) 0 |

  # thus, the value of AB-> X BC-> is:
    = (x2-x1)*(y3-y2) - (x3-x2)*(y2-y1)

# Check out Leetcode 587: [erect-the-fence]
*/