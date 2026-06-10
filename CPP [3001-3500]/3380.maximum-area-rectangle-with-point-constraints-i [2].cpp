class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int maxRectangleArea(vector<vector<int>>& points) {
        // atleast 4 points are required to form a rect.
        int n = points.size();
        if(n < 4)
            return -1;

        // sort in increasing order of x-coordinate and 
        // in increasing order of y-coordinate (if x-coordinates are equal)
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });


        int maxArea = -1;

        for(int i=0; i<n-3; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i+1][0], y2 = points[i+1][1];

            if(x1 != x2)
                continue;

            for(int j=i+2; j<n-1; j++)
            {
                int x3 = points[j][0], y3 = points[j][1];
                int x4 = points[j+1][0], y4 = points[j+1][1];

                // point 3 can be skipped as it lies above the possible rect.
                if(x2 == x3)
                    continue;

                // point 3 can be skipped as it lies either above or below the possible rect.
                if(y3 < y1 || y3 > y2)
                    continue;

                // rect. can be formed with points 1,2,3,4
                if(y1 == y3 && y2 == y4 && x3 == x4)
                    maxArea = max(maxArea, abs(x1 - x3) * abs(y1 - y2));
                // point 3 will lie on or inside the next possible rect.
                else
                    break;
            }
        }

        return maxArea;
    }
};

/*

(x2, y2) ---- (x4, y4)
   |             |
   |             |
(x1, y1) ---- (x3, y3)

*/