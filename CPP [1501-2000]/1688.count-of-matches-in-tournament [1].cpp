class Solution {
public:
    int numberOfMatches(int n) { // T.C.=O(logn), S.C.=O(1)
        int matches = 0;
        while(n != 1)
        {
            matches += n/2;
            n = n/2 + n % 2;
        }
        return matches;
    }
};