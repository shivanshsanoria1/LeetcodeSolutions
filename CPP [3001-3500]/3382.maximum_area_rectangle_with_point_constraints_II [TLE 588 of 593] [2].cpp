class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        // atleast 4 points are required to form a rect.
        int n = xCoord.size();
        if(n < 4)
            return -1;

        vector<pair<int, int>> points;
        for(int i=0; i<n; i++)
            points.push_back({xCoord[i], yCoord[i]});

        // sort in increasing order of x-coordinate and 
        // in increasing order of y-coordinate (if x-coordinates are equal)
        sort(points.begin(), points.end());

        long long int maxArea = -1;

        for(int i=0; i<n-3; i++)
        {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[i+1];

            if(x1 != x2)
                continue;

            for(int j=i+2; j<n-1; j++)
            {
                auto [x3, y3] = points[j];
                auto [x4, y4] = points[j+1];

                // point 3 can be skipped as it lies above the possible rect.
                if(x2 == x3)
                    continue;

                // point 3 can be skipped as it lies either above or below the possible rect.
                if(y3 < y1 || y3 > y2)
                    continue;

                // rect. can be formed with points 1,2,3,4
                if(y1 == y3 && y2 == y4 && x3 == x4)
                    maxArea = max(maxArea, (long long int)abs(x1 - x3) * abs(y1 - y2));
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