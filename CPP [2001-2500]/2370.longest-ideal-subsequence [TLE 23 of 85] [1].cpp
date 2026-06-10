class Solution {
private:
    int solve(string& s, int k, int prevIdx, int i){
        if(i >= s.length())
            return 0;
        
        int exclude = solve(s, k, prevIdx, i+1);

        int include = (prevIdx == -1 || abs(s[prevIdx] - s[i]) <= k) ? solve(s, k, i, i+1) : -1;
        
        return include >= exclude ? 1 + include : exclude;
    }

public:
    // T.C.=O(2^n)
    // Recursion
    int longestIdealString(string s, int k) {
        return solve(s, k, -1, 0);
    }
};
// prevIdx: index of the last char included in the ideal subsequence