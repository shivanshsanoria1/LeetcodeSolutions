class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 2) // 2 points always form a straight line
            return true;
        int x0 = coordinates[0][0], y0=coordinates[0][1]; // (x0,y0)
        int x1 = coordinates[1][0], y1=coordinates[1][1]; // (x1,y1)
        for(int i=2; i<n; i++)
        {
            int x=coordinates[i][0], y=coordinates[i][1]; // (x,y)
            // point (x,y) does not lie on the straight line formed by (x0,y0), (x1,y1)
            if((y1-y0)*(x-x1) != (y-y1)*(x1-x0)) 
                return false;
        }
        return true;
    }
};
/*
# 3 points (x0,y0), (x1,y1), (x,y) form a straight line if-
# (y1-y0)/(x1-x0) = (y-y1)/(x-x1)
*/