class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int findClosest(int x, int y, int z) {
        int diff1 = abs(x-z);
        int diff2 = abs(y-z);

        if(diff1 == diff2)
            return 0;
        
        return diff1 < diff2 ? 1 : 2;
    }
};