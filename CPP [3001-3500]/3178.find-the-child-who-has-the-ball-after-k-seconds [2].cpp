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
# for n elements: 2*(n-1) steps are required to reach 0 again when starting from 0
# eg: n = 5, 2*4 steps are required to move from 0 to 0 again
  0 -> 1 -> 2 -> 3 -> 4
    <-   <-   <-   <-

# similar: [2582. pass-the-pillow]
*/