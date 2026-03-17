class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int countCommas(int n) {
        return n < 1000 ? 0 : n - 999;
    }
};

// only 4,5,6 digit numbers contribute to a comma (1 for each)