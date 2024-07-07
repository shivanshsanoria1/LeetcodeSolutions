class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int passThePillow(int n, int time) {
        time %= 2*(n-1);
        return time < n ? time + 1 : 2*(n-1) - time + 1;
    }
};
/*
# for n elements: 2*(n-1) steps are required to reach 1 again when starting from 1
# eg: n = 5, 2*4 steps are required to move from 1 to 1 again
  1 -> 2 -> 3 -> 4 -> 5
    <-   <-   <-   <-

# similar: [3178. find-the-child-who-has-the-ball-after-k-seconds]
*/