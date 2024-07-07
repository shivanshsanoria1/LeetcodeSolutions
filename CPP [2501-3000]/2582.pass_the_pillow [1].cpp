class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int passThePillow(int n, int time) {
        int fullPasses = time / (n-1);
        int lastPass = time % (n-1);
        // true: left to right, false: right to left
        bool dir = fullPasses % 2 == 0;

        return dir ? lastPass + 1 : n - lastPass;
    }
};
/*
# for n elements: (n-1) steps are required to move from 1 to n
# eg: n = 5, 4 steps are required to move from 1 to 5
  1 -> 2 -> 3 -> 4 -> 5

# similar: [3178. find-the-child-who-has-the-ball-after-k-seconds]
*/