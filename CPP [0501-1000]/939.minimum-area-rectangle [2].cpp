class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        // atleast 4 points are needed to form a rectangle
        if(n < 4)
            return 0;

        unordered_set<string> s;
        for(auto& point: points)
            s.insert(to_string(point[0]) + "#" + to_string(point[1]));

        int minArea = INT_MAX;

        for(int i=0; i<n-1; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 || y1 == y2)
                    continue;
                string hash1 = to_string(x1) + "#" + to_string(y2);
                string hash2 = to_string(x2) + "#" + to_string(y1);
                // points (x1,y2) and (x2,y1) found in set
                if(s.find(hash1) != s.end() && s.find(hash2) != s.end())
                    minArea = min(minArea, abs(x2-x1)*abs(y2-y1)); 
            }
        }

        return minArea == INT_MAX ? 0 : minArea;
    }
};

/*
(x1,y2) ----- (x2,y2)
   |             |
   |             |
   |             |
(x1,y1) ----- (x2,y1)

# points (x1,y1) and (x2,y2) must be diagonally facing each other
  so x1 != x2 && y1 != y2
*/