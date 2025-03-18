class Solution {
private:
    string getHash(int x, int y){
        return to_string(x) + "#" + to_string(y);
    }

    bool hasPointInsideRect(vector<vector<int>>& points, int x1, int y1, int x2, int y2){
        for(vector<int>& point: points)
        {
            int x = point[0], y = point[1];

            if((x == x1 && y == y1) || 
            (x == x2 && y == y2) || 
            (x == x1 && y == y2) || 
            (x == x2 && y == y1))
                continue;

            if(min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2))
                return true;
        }

        return false;
    }

public:
    // T.C.=O(n^3), S.C.=O(n)
    int maxRectangleArea(vector<vector<int>>& points) {
        // atleast 4 points are required to form a rect.
        int n = points.size();
        if(n < 4)
            return -1;

        unordered_set<string> s;
        for(vector<int>& point: points)
        {
            int x = point[0], y = point[1];
            s.insert(getHash(x, y));
        }

        int maxArea = -1;
        for(int i=0; i<n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;

                int x2 = points[j][0], y2 = points[j][1];

                // (x1, y1) and (x2, y2) must form a diagonal of the rect.
                if(x1 == x2 || y1 == y2)
                    continue;
                
                // (x1, y2) and (x2, y1) are found and
                // there is no point lying on or inside the rect.
                if(s.find(getHash(x1, y2)) != s.end() && 
                s.find(getHash(x2, y1)) != s.end() && 
                !hasPointInsideRect(points, x1, y1, x2, y2))
                    maxArea = max(maxArea, abs(x1-x2) * abs(y1-y2));
            }
        }

        return maxArea;
    }
};

/*

(x1, y2) ---- (x2, y2)
   |             |
   |             |
(x1, y1) ---- (x2, y1)

*/