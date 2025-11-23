class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) { // T.C.O(n^3), S.C.=O(1)
        int n = points.size();
        double maxArea = 0;
        for(int i=0; i<n-2; i++)
        {
            int x1 = points[i][0], y1 = points[i][1]; // (x1,y1)
            for(int j=i+1; j<n-1; j++)
            {
                int x2 = points[j][0], y2 = points[j][1]; // (x2,y2)
                for(int k=j+1; k<n; k++)
                { 
                    int x3 = points[k][0], y3 = points[k][1]; // (x3,y3)
                    double area = abs((double)(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)))/2;
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
/*
# area of a triangle made with the points (x1,y1), (x2,y2), (x3,y3) is-
# abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)))/2
*/