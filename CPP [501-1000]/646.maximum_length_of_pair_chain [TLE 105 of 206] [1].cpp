class Solution {
public:
    int solve(vector<vector<int>>& pairs, int i, int prevEnd){
        if(i >= pairs.size())
            return 0;
        int currStart = pairs[i][0];
        int currEnd = pairs[i][1];
        int exclude = solve(pairs, i+1, prevEnd);
        int include = (prevEnd < currStart) ? 1 + solve(pairs, i+1, currEnd) : 0;
        return max(exclude, include);
    }

    int findLongestChain(vector<vector<int>>& pairs) { // Recursion, T.C.=O(2^n)
        sort(pairs.begin(), pairs.end());
        return solve(pairs, 0, INT_MIN);
    }
};