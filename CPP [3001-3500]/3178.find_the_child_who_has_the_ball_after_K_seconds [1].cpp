class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int numberOfChild(int n, int k) {
        int fullPasses = k / (n-1);
        int lastPass = k % (n-1);
        // true: left to right, false: right to left
        bool dir = fullPasses % 2 == 0;

        return dir ? lastPass : (n-1) - lastPass;
    }
};
/*
# for n elements: (n-1) steps are required to move from 0 to (n-1)
# eg: n = 5, 4 steps are required to move from 0 to 4
  0 -> 1 -> 2 -> 3 -> 4

# similar: [2582. pass-the-pillow]
*/