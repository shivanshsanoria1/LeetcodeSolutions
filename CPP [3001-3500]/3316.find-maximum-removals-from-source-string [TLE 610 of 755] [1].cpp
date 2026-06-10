class Solution {
private:
    #define INF INT_MIN

    int solve(string& s1, string& s2, vector<bool>& canRemove, int i, int j){
        int n1 = s1.length(), n2 = s2.length();

        if(j == n2)
        {   
            // all the removable chars in index-range [i, n1) 
            // can now be excluded from s1
            return count(canRemove.begin() + i, canRemove.end(), true);
        }

        // no chars left in s1 but some chars are still left in s2,
        // thus s2 cannot be a subsequence of s1
        if(i == n1)
            return INF;

        // include i
        int include = s1[i] == s2[j] ? solve(s1, s2, canRemove, i+1, j+1) : INF;

        // exclude i
        int exclude = solve(s1, s2, canRemove, i+1, j);
        // excluding the removable-index i increments the operations by 1
        if(canRemove[i])
            exclude++;

        return max(include, exclude);
    }

public:
    // Recursion
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n1 = source.length(), n2 = pattern.length();

        vector<bool> canRemove(n1, false);
        for(int idx: targetIndices)
            canRemove[idx] = true;
        
        return solve(source, pattern, canRemove, 0, 0);
    }
};