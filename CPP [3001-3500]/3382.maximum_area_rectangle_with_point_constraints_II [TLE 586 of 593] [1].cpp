class Solution {
private:
    string getHash(int x, int y){
        return to_string(x) + "#" + to_string(y);
    }

    bool hasPointInsideRect(vector<int>& xCoord, vector<int>& yCoord, int x1, int y1, int x2, int y2){
        for(int i=0; i<xCoord.size(); i++)
        {
            int x = xCoord[i], y = yCoord[i];

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
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        // atleast 4 points are required to form a rect.
        int n = xCoord.size();
        if(n < 4)
            return -1;

        unordered_set<string> s;
        for(int i=0; i<n; i++)
            s.insert(getHash(xCoord[i], yCoord[i]));

        long long int maxArea = -1;
        for(int i=0; i<n; i++)
        {
            int x1 = xCoord[i], y1 = yCoord[i];
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;

                int x2 = xCoord[j], y2 = yCoord[j];

                // (x1, y1) and (x2, y2) must form a diagonal of the rect.
                if(x1 == x2 || y1 == y2)
                    continue;
                
                // (x1, y2) and (x2, y1) are found and
                // there is no point lying on or inside the rect.
                if(s.find(getHash(x1, y2)) != s.end() && 
                s.find(getHash(x2, y1)) != s.end() && 
                !hasPointInsideRect(xCoord, yCoord, x1, y1, x2, y2))
                    maxArea = max(maxArea, (long long int)abs(x1-x2) * abs(y1-y2));
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
