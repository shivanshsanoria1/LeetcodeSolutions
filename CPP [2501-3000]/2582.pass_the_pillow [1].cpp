class Solution {
public:
    int passThePillow(int n, int time) {
        int fullPasses = time / (n-1);
        int lastPass = time % (n-1);
        // true: left to right, false: right to left
        bool dir = fullPasses % 2 == 0;
        return dir ? lastPass + 1 : n - lastPass;
    }
};