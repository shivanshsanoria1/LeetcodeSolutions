class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // josephus-problem, bottom-up approach
    int findTheWinner(int n, int k) {
        // initially, solve for 0-based indexing

        // for len = 1, 0th person is in safe-position
        int safePos = 0;
        // iteratively solve for len = 2,3,4,...,n
        for(int len = 2; len <= n; len++)
            safePos = (safePos + k) % len;
        
        // convert back to 1-based indexing
        return safePos + 1;
    }
};