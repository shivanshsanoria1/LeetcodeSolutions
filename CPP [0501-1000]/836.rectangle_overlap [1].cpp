class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a1 = rec1[0], b1 = rec1[1]; // (a1,b1)
        int a2 = rec1[2], b2 = rec1[3]; // (a2,b2)
        int x1 = rec2[0], y1 = rec2[1]; // (x1,y1)
        int x2 = rec2[2], y2 = rec2[3]; // (x2,y2)
        if(a1 < x2 && a2 > x1 && b1 < y2 && b2 > y1)
            return true;
        return false;
    }
};