class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 2) // 2 points always form a straight line
            return true;
        for(int i=1; i<n-1; i++)
        {
            int x1=coordinates[i-1][0], y1=coordinates[i-1][1]; // (x1,y1)
            int x2=coordinates[i][0], y2=coordinates[i][1]; // (x2,y2)
            int x3=coordinates[i+1][0], y3=coordinates[i+1][1]; // (x3,y3)
            // (i-1)th, ith, (i+1)th points don't form a straight line
            if((y2-y1)*(x3-x2) != (y3-y2)*(x2-x1)) 
                return false;
        }
        return true;
    }
};
/*
# 3 points (x1,y1), (x2,y2), (x3,y3) form a straight line if-
# (y2-y1)/(x2-x1) = (y3-y2)/(x3-x2)
*/