class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1=points[0][0], y1=points[0][1]; //(x1,y1)
        int x2=points[1][0], y2=points[1][1]; //(x2,y2)
        int x3=points[2][0], y3=points[2][1]; //(x3,y3)
        if((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x3==x1 && y3==y1)) //all points must be distinct
            return false;
        if((y2-y1)*(x3-x2) == (y3-y2)*(x2-x1)) //points are on a straight line
            return false;
        return true;
    }
};