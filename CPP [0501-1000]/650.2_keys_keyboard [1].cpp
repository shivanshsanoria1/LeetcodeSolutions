class Solution {
private:
    #define INF int(1e9)

    int solve(int curr, int prev, int n){
        if(curr > n)
            return INF;

        if(curr == n)
            return 0;
        
        int paste = prev > 0 ? 1 + solve(curr + prev, prev, n) : INF;
        int copyPaste = 2 + solve(curr*2, curr, n);

        return min(paste, copyPaste);
    }

public:
    // T.C.=O(2^n), S.C.=O(n)
    // Recursion
    int minSteps(int n) {
        return solve(1, 0, n);
    }
};
// curr: length of curr string
// prev: length of previously copied string