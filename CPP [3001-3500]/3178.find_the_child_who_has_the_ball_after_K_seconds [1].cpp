class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int numberOfChild(int n, int k) {
        k %= 2*(n-1);
        return k < n ? k : 2*(n-1) - k;
    }
};
/*
# Eg: n = 5
# here k can only have 8 values in range [0, 7]
  so k must be reduced mod 8
# nums: 0 1 2 3 4
     k: 0 1 2 3 4
          7 6 5
# in general k must be reduced mod 2*(n-1)
*/